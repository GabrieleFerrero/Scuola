import socket as sck
import sqlite3
from pathlib import Path

#          SOCKET          #
SERVER_ADDRESS = "0.0.0.0"
SERVER_PORT = 5000
SERVER_DATA = (SERVER_ADDRESS, SERVER_PORT)	
s = sck.socket(sck.AF_INET, sck.SOCK_DGRAM)
s.bind(SERVER_DATA)
# ------------------------ #

#         PERCORSO         #
dir_path = str(Path(__file__).parent.resolve())
print(dir_path)
# ------------------------ #

def mandaMessaggi(messaggio, utente_che_ha_inviato_il_messaggio):
    lista_utenti = estraiAddressUtenti()
    for indirizzo_e_porta in lista_utenti:
        s.sendto(f"{utente_che_ha_inviato_il_messaggio} ha inviato a tutti: {messaggio}".encode(),indirizzo_e_porta)

def verificaPresenzaUtente(nick):
    con = sqlite3.connect(f"{dir_path}/utenti_registrati.db")
    cur = con.cursor()
    i=1
    for row in cur.execute('SELECT * FROM utenti'):
        if row[0] == nick: return True, i
        i+=1
    
    con.close()
    return False, -1

def trovaIndirizzoDaNickname(nick):
    con = sqlite3.connect(f"{dir_path}/utenti_registrati.db")
    cur = con.cursor()
    for row in cur.execute('SELECT * FROM utenti'):
        if nick == row[0]: return True, (row[1],row[2])
    
    con.close()
    return False, ()

def estraiAddressUtenti():
    con = sqlite3.connect(f"{dir_path}/utenti_registrati.db")
    cur = con.cursor()
    lista_utenti = []
    for row in cur.execute('SELECT * FROM utenti'):
        lista_utenti.append((row[1],row[2]))

    con.close()
    return lista_utenti

def stampaUtenti():
    con = sqlite3.connect(f"{dir_path}/utenti_registrati.db")
    cur = con.cursor()
    for row in cur.execute('SELECT * FROM utenti'):
        print(row)
    con.close()


def inserisciDatiNelDatabase(nick, addr):
    con = sqlite3.connect(f"{dir_path}/utenti_registrati.db")
    cur = con.cursor()

    is_present, index = verificaPresenzaUtente(nick)
    if is_present:
        _, ind = trovaIndirizzoDaNickname(nick)
        s.sendto(f"server ti ha inviato: SEI STATO BUTTATO FUORI DALLA CHAT!".encode(),ind)
        cur.execute(f"UPDATE \"main\".\"utenti\" SET \"nickname\"=? WHERE \"_rowid_\"=\'{index}\'", (nick,))
        cur.execute(f"UPDATE \"main\".\"utenti\" SET \"address\"=? WHERE \"_rowid_\"=\'{index}\'", (addr[0],))
        cur.execute(f"UPDATE \"main\".\"utenti\" SET \"port\"=? WHERE \"_rowid_\"=\'{index}\'", (addr[1],))
    else:
        cur.execute(f"INSERT INTO utenti VALUES ('{nick}','{addr[0]}',{addr[1]})")
    con.commit()
    con.close()

def main():
    try:
        while True:
            data, addr = s.recvfrom(4096)
            data = data.decode()
            print(f"{data}\t{addr}")
            if("Nickname:" in data):
                inserisciDatiNelDatabase(data[9:], addr)
                mandaMessaggi(f"{data[9:]} si è unito alla chat", "server")
                print("----------------------------\nLista utenti registrati:\n")
                stampaUtenti()
                print("----------------------------")
            else:
                is_present, _ = verificaPresenzaUtente(data.split(",")[0].split(":")[1])
                if is_present:
                    #Sender:{Nickname_mittente}, Receiver:{Nickname_ricevente}, msg
                    if "tutti" in data.split(",")[1]:
                        mandaMessaggi(data.split(",")[2], data.split(",")[0].split(":")[1])
                    else:
                        is_present, address = trovaIndirizzoDaNickname(data.split(",")[1].split(":")[1])
                        if is_present:
                            mittente =  data.split(",")[0].split(":")[1]
                            msg = data.split(",")[2]
                            s.sendto(f"{mittente} ti ha inviato: {msg}".encode(), address)
                        else:
                            print("Ricevente non presente in archivio!")
                else:
                    s.sendto(f"server ti ha inviato: devi registrarti!".encode(),addr)
                    print("Utente non registrato!")
    except:
        print("Errore Rilevato!\nexit...")
        s.close()

if __name__ == "__main__":
    main()
    