# IMPORTAZIONE LIBRERIE #
import socket as sck
import datetime
import random
from time import sleep
# -------------------- #
# INFORMAZIONI SUI DATI #
"""
MESSAGGIO DI AVVENUTA RICEZIONE: "OK"
MESSAGGIO DI RICHIESTA DI ATTIVAZIONE SIRENA: "PERICOLO"
MESSAGGIO MISURAZIONE: misurazione+"#"+data_misurazione+"#"+id_stazione
"""
# -------------------- #
# DEFINIZIONE VARIABILI GLOBALI #
TEMPO_DI_ATTESA_INVIO_DATI = 15 # variabile per gestire il tempo tra l'invio di ogni dato
# -------------------- #

def lettura_sensore():
    """
    Questa funzione va a simulare la lettera del sensore
    per sapere il livello del fiume
    """
    return random.uniform(0.1, 8) # estraggo numeri casuali
 

def main():

    # CREAZIONE SOCKET
    s = sck.socket(sck.AF_INET, sck.SOCK_STREAM)
    s.connect(('127.0.0.1', 5000)) # tupla --> indirizzo ip, porta -- mi connetto al server

    id_stazione = int(input("Inserire l'ID della stazione: ")) # acquisisco l'id della stazione
    s.sendall(f"{id_stazione}".encode()) # invio l'id della stazione

    pericolo = False

    while True:

        misurazione = lettura_sensore() # leggo il dato del sensore

        data_misurazione = datetime.datetime.now() # acquisisco data e ora della misurazione

        s.sendall(f"{misurazione}#{data_misurazione}#{id_stazione}".encode()) # invio il dato al server, seguendo il formato sopra indicato

        risposta = s.recv(4096).decode() # ricevo la risposta

        # gestione in base alla risposta
        if risposta == "OK":
            if pericolo:
                print("ALLARME LUMINOSO SPENTO")
                pericolo = False
        elif risposta == "PERICOLO":
            print("ALLARME LUMINOSO ACCESO")
            pericolo = True

        sleep(TEMPO_DI_ATTESA_INVIO_DATI) # attendo prima di ripetere l'operazione


    
if __name__ == "__main__":
    main()