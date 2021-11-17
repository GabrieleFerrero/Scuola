import socket as sck
import sqlite3
from pathlib import Path
import threading as thr

#          SOCKET          #
NUM_MAX_CLIENT = 10
SERVER_ADDRESS = "0.0.0.0"
SERVER_PORT = 5000
SERVER_DATA = (SERVER_ADDRESS, SERVER_PORT)	
s = sck.socket(sck.AF_INET, sck.SOCK_STREAM)
s.bind(SERVER_DATA)
s.listen(NUM_MAX_CLIENT)
# ------------------------ #

#         PERCORSO         #
dir_path = str(Path(__file__).parent.resolve())
print(dir_path)
# ------------------------ #

#       ELENCO UTENTI      #
blocco_modifca_dict = thr.Lock() 
elenco_connesioni = []
# ------------------------ #

class ClientManager(thr.Thread):
    def __init__(self, connection, addr):
        thr.Thread.__init__(self)
        self.nome = "Sconosciuto"
        self.addr = addr
        self.connection = connection
        self.running = True
    #OVERRIDE
    def run(self):
        while self.running:
            data = self.connection.recv(4096).decode()
            print(f"{self.nome}: {data}")
            if "Nickname:" in data:
                self.nome = data[9:]
                inserisciDatiNelDatabase(self.nome, self.addr, len(elenco_connesioni), self.connection)
                mandaMessaggi(f"{data[9:]} si è unito alla chat", "server")
                print("----------------------------\nLista utenti registrati:\nnickname, address, port, index\n")
                stampaUtenti()
                print("----------------------------")
            else:
                nick, _, _ = trovaQuelloCheVuoi(data.split(",")[0].split(":")[1], "nickname")
                if nick != "":
                    #Sender:{Nickname_mittente}, Receiver:{Nickname_ricevente}, msg
                    if "tutti" in data.split(",")[1]:
                        mandaMessaggi(data.split(",")[2], data.split(",")[0].split(":")[1])
                    else:
                        _, _, i = trovaQuelloCheVuoi(data.split(",")[1].split(":")[1], "nickname")
                        if i != -1:
                            mittente =  data.split(",")[0].split(":")[1]
                            msg = data.split(",")[2]
                            con = elenco_connesioni[i]
                            con.sendall(f"{mittente} ti ha inviato: {msg}".encode())
                        else:
                            print("Ricevente non presente in archivio!")
                else:
                    self.connection.close()
                    self.stop()
                    self.connection.sendall(f"server ti ha inviato: devi registrarti!".encode())
                    print("Utente non registrato!")

    def stop(self):
        self.running = False


def mandaMessaggi(messaggio, utente_che_ha_inviato_il_messaggio):
    for conn in elenco_connesioni:
        conn.sendall(f"{utente_che_ha_inviato_il_messaggio} ha inviato a tutti: {messaggio}".encode())

def stampaUtenti():
    con = sqlite3.connect(f"{dir_path}/utenti_registrati.db")
    cur = con.cursor()
    for row in cur.execute('SELECT * FROM utenti'):
        print(row)
    con.close()

def trovaQuelloCheVuoi(dato_di_ricerca, tipo_di_dato):
    con = sqlite3.connect(f"{dir_path}/utenti_registrati.db")
    cur = con.cursor()

    lista_nick = []
    lista_address = []
    lista_port = []
    lista_index = []

    nick = ""
    addr = ("", 0)
    index = -1

    for row in cur.execute('SELECT * FROM utenti'):
        lista_nick.append(row[0])
        lista_address.append(row[1])
        lista_port.append(row[2])
        lista_index.append(row[3])

    con.close()

    lista_addr = [(address, port) for address, port in zip(lista_address, lista_port)]


    if tipo_di_dato == "nickname" and dato_di_ricerca not in lista_nick or \
       tipo_di_dato == "addr" and dato_di_ricerca not in lista_addr or \
       tipo_di_dato == "index" and dato_di_ricerca not in lista_index:
       pass  # se non è presente il dato richiesto non faccio niente

    else:
        if tipo_di_dato == "nickname":
            nick = dato_di_ricerca
            addr = lista_addr[lista_nick.index(dato_di_ricerca)]
            index = lista_index[lista_nick.index(dato_di_ricerca)]
        elif tipo_di_dato == "addr":
            nick = lista_nick[lista_addr.index(dato_di_ricerca)]
            addr = dato_di_ricerca
            index = lista_index[lista_addr.index(dato_di_ricerca)]
        elif tipo_di_dato == "index":
            nick = lista_nick[lista_index.index(dato_di_ricerca)]
            addr = lista_addr[lista_index.index(dato_di_ricerca)]
            index = dato_di_ricerca

    return nick, addr, index


def inserisciDatiNelDatabase(nick, addr, indice, conn):
    con = sqlite3.connect(f"{dir_path}/utenti_registrati.db")
    cur = con.cursor()

    n, _, i = trovaQuelloCheVuoi(nick, "nickname")
    if n != "":
        elenco_connesioni[i].sendall(f"server ti ha inviato: SEI STATO BUTTATO FUORI DALLA CHAT!".encode())

        cur.execute(f"UPDATE \"main\".\"utenti\" SET \"nickname\"=? WHERE \"_rowid_\"=\'{i}\'", (nick,))
        cur.execute(f"UPDATE \"main\".\"utenti\" SET \"address\"=? WHERE \"_rowid_\"=\'{i}\'", (addr[0],))
        cur.execute(f"UPDATE \"main\".\"utenti\" SET \"port\"=? WHERE \"_rowid_\"=\'{i}\'", (addr[1],))

        elenco_connesioni[i].close()
        with blocco_modifca_dict:
            elenco_connesioni[i] = conn
    else:
        cur.execute(f"INSERT INTO utenti VALUES ('{nick}','{addr[0]}',{addr[1]},{indice})")
        with blocco_modifca_dict:
                elenco_connesioni.append(conn)
    con.commit()
    con.close()


def main():
    try:
        while True:
            connection, addr = s.accept()
            ClientManager(connection, addr).start()
    except:
        print("Errore Rilevato!\nexit...")
        for conn in elenco_connesioni:
            conn.close()

if __name__ == "__main__":
    main()
    