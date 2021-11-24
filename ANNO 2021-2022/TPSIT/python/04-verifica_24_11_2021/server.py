# IMPORTAZIONE LIBRERIE #
import socket as sck
import threading as thr
import sqlite3
# -------------------- #
# INFORMAZIONI SUI DATI #
"""
LIVELLI PERICOLOSITÀ: BASSO, MEDIO e ALTO
MESSAGGIO DI AVVENUTA RICEZIONE: "OK"
MESSAGGIO DI RICHIESTA DI ATTIVAZIONE SIRENA: "PERICOLO"
MESSAGGIO MISURAZIONE: misurazione+"#"+data_misurazione+"#"+id_stazione
"""
# -------------------- #
# DEFINIZIONE VARIABILI GLOBALI #
clients = []
# -------------------- #


def verifica_pericolosita_misurazione(valore_di_guardia, misurazione):
    """
    Questa funzione permette di capire il valore di pericolosità
    del valore della misurazione ricevuto 
    """
    # inizia calcolando le diverse percentuali del valore di guardia
    pc_30 = 30/100*valore_di_guardia # 30% del valore di guardia
    pc_70 = 70/100*valore_di_guardia # 70% del valore di guardia

    livello_pericolosita = ""

    # controlli della misurazione ricevuta in base al valore di guardia
    if misurazione < pc_30: livello_pericolosita = "BASSO"
    elif misurazione >= pc_30 and misurazione < pc_70: livello_pericolosita = "MEDIO"
    elif misurazione >= pc_70: livello_pericolosita = "ALTO"

    return livello_pericolosita



class ClientManager(thr.Thread):
    """
    Questa classe permette di gestire le diverse connessione delle varie
    stazioni di rilevazione
    """
    def __init__(self, connection, address, pos):
        thr.Thread.__init__(self)
        self.connection = connection
        self.address = address
        self.pos = pos
        self.running = True

    def run(self):
        id_stazione = int(self.connection.recv(4096).decode()) # inizialmento mi faccio inviare l'id della stazione in modo da potere estrarre subito i dati
        fiume_misurazione = ""
        localita_misurazione = ""
        valore_di_guardia = 0

        # ESTRAZIONE DATI DAL DATABASE

        sql = f"SELECT fiume, localita, livello FROM livelli WHERE id_stazione = {id_stazione}" # faccio una SELECT mirata

        con = sqlite3.connect('/home/gabriele/Scaricati/verfica/fiumi.db') # apro il database
        cur = con.cursor() # creo l'oggetto cursore
        dati = cur.execute(sql).fetchall() # eseguo la select
        con.close() # chiudo la connessione al database

        # SALVO I DATI ESTRATTI DAL DATABASE
        fiume_misurazione = dati[0][0]
        localita_misurazione = dati[0][1]
        valore_di_guardia = dati[0][2]


        while self.running:
            misurazione = self.connection.recv(4096).decode() # ricezione misurazione

            livello_pericolosita = verifica_pericolosita_misurazione(valore_di_guardia, float(misurazione.split("#")[0])) # calcolo del livello di pericolosità
            data_misurazione = misurazione.split("#")[1] # acquisizione della data di misurazione

            # gestione in base al livello di pericolosità
            if  livello_pericolosita == "BASSO":
                messaggio = "OK"
            elif livello_pericolosita == "MEDIO":
                messaggio = "OK"
                print(f"PERICOLO IMMINENTE SUL FIUME {fiume_misurazione} NELLA LOCALITA DI {localita_misurazione}, MISURAZIONE AVVENUTA IL {data_misurazione}")
            elif livello_pericolosita == "ALTO":
                messaggio = "PERICOLO"
                print(f"PERICOLO SUL FIUME {fiume_misurazione} NELLA LOCALITA DI {localita_misurazione}, MISURAZIONE AVVENUTA IL {data_misurazione}")

            self.connection.sendall(f"{messaggio}".encode()) # invio il dato alla stazione

def main():
    global clients

    # CREAZIONE SERVER TCP
    s = sck.socket(sck.AF_INET, sck.SOCK_STREAM)
    s.bind(("127.0.0.1", 5000))
    s.listen()

    while True:
        connection, address = s.accept() # accettazione client (stazioni)
        client = ClientManager(connection, address, len(clients)) # creazione di un thread per ogni stazione
        clients.append(client) # aggiungo il thread alla lista dei client
        client.start() # avvio il thread
        
if __name__ == "__main__":
    main()