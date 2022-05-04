import requests
from time import sleep
import datetime


def get_scelta_menu():
    print("Menù:\n1: Upload misurazione\n2: Get informazioni dati\n3: Termina programma")
    try: 
        scelta = int(input("Inserire opzione: "))
    except: 
        print("Opzione scelta non valida")
        scelta = get_scelta_menu()

    return scelta 


def menu_upload_misurazione():
    id_grandezza = get_id_grandezza()
    id_stazione = get_id_stazione()
    misurazione = get_misurazione()
    data_ora = get_data()

    risposta = requests.get("http://127.0.0.1:5000/api/v1/upload_misurazione", params={"id_stazione": id_stazione, "id_grandezza": id_grandezza, "data_ora": data_ora, "misurazione": misurazione}).json()
    print(f'Risultato operazione: {risposta["errore"]}')


def menu_get_informazioni():
    id_grandezza = get_id_grandezza()
    id_stazione = get_id_stazione()

    risposta = requests.get("http://127.0.0.1:5000/api/v1/get_informazioni", params={"id_stazione": id_stazione, "id_grandezza": id_grandezza}).json()
    
    if risposta["errore"] == "Nessun errore":
        print(F"MIN: {risposta['dati']['min']}, MAX: {risposta['dati']['max']}, MEDIA: {risposta['dati']['media']}")
    else:
        print(f'Risultato operazione: {risposta["errore"]}')


def get_data():
    try:
        giorno = input("Inserire giorno misurazione: ")
        mese = input("Inserire mese misurazione: ")
        anno = input("Inserire anno misurazione: ")
        if len(anno) < 4:
            anno = "errore"
        else: anno = anno[2:]
        ora = input("Inserire ora misurazione: ")
        minuto = input("Inserire minuto misurazione: ")
        secondo = input("Inserire secondo misurazione: ")

        data_ora = datetime.datetime.strptime(f"{giorno}-{mese}-{anno} {ora}:{minuto}:{secondo}", "%d-%m-%y %H:%M:%S")
    except:
        print("Data creata non corretta")
        data_ora = get_data()
    return data_ora

def get_id_stazione():
    try: 
        nome = input("Inserire nome stazione: ")
        risposta = requests.get("http://127.0.0.1:5000/api/v1/get_id_stazione", params={"nome": nome}).json()
        if risposta["errore"] == "Nessun errore":
            id_stazione = risposta["dati"]["id"]
        else:
            print(risposta["errore"])
            id_stazione = get_id_stazione()
    except: 
        id_stazione = get_id_stazione()

    return id_stazione 


def get_id_grandezza():
    try: 
        nome = input("Inserire nome grandezza: ")
        risposta = requests.get("http://127.0.0.1:5000/api/v1/get_id_grandezza", params={"nome": nome}).json()
        if risposta["errore"] == "Nessun errore":
            id_grandezza = risposta["dati"]["id"]
        else:
            print(risposta["errore"])
            id_grandezza = get_id_grandezza()
    except: 
        id_grandezza = get_id_grandezza()

    return id_grandezza 



def get_misurazione():
    try: 
        misurazione = float(input("Inserire misurazione: "))
    except: 
        print("Impossibile convertire valore a float")
        misurazione = get_misurazione()
    return misurazione 



menu = {
    1: menu_upload_misurazione,
    2: menu_get_informazioni
}

def main():
    while True:
        scelta = get_scelta_menu()
        if scelta == 3: break
        else: menu[scelta]()
        
    print("Programma terminato")


if __name__ == "__main__":
    main()