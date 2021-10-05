"""
QR code (con le dovute semplificazioni….)
Ipotesi:
considerate stringhe lunghe al massimo 12 caratteri
i caratteri ammessi sono le cifre da “0” a “9”, il carattere spazio (“ “) e le lettere minuscole dell’alfabeto italiano da “a” a “z”
ognuno di questi caratteri può essere codificato su 5 bit.

Create un programma in Python3 che:

crei un dizionario che abbia come chiave ciascuno dei caratteri di cui sopra e come valori le liste di bit (numeri interi 0 oppure 1) corrispondenti alla codifica binaria su 5 bit. La codifica può essere inventata da voi
es: {“b” : [1,0,1,0,1],.............}

chieda all’utente una stringa composta secondo le ipotesi di cui sopra.

converta la stringa inserita dall’utente in una lista di liste effettuando la conversione da ogni carattere alla corrispondente lista di bit

disegni il qr code, ovvero rappresenti la lista di lista su uno screen di Pygame, usando celle nere per i bit a 1 e celle bianche per i bit a 0

salvi la lista di liste di cui al punto 3 all’interno di un file .csv.



BONUS:
l’utente può decidere se inserire una stringa oppure il nome di un file csv: nel secondo caso il programma apre il file .csv e rappresenta il qr code su uno screen di Pygame.

Consegnare su Classroom un programma Python avente nome file: cognome_nome.py
"""


import pygame
import sys
import csv


LUNGHEZZA_MAX_STRINGA = 12
BIT_CODIFICA = 5

COLORE_SFONDO = (255,255,255)
COLORE_BIT_1 = (0,0,0)
COLORE_BIT_0 = (255,255,255)
DIMENSIONE_RETTANGOLO_BIT = 20

dizionario_codifica_caratteri={}

lista_caratteri_consentiti=['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', " "]


def verificaStringaInserita(stringa):
    if(len(stringa)>LUNGHEZZA_MAX_STRINGA):
        raise ValueError("Lunghezza massima stringa superata")
    else:
        for carattere in stringa:
            carattere_trovato=False
            for carattere_consentito in lista_caratteri_consentiti:
                if(carattere==carattere_consentito):
                    carattere_trovato=True

            if(carattere_trovato==False):
                raise ValueError("Carattere inserito non consentito")


def generazioneCodificaCaratteri():
    binary1 = "0b00000"
    binary2 = "0b00001"
    prima_volta=True
    for carattere in lista_caratteri_consentiti:
        if(prima_volta):
            prima_volta=False
        else:
            integer_sum = int(binary1, 2) + int(binary2, 2)  # faccio la somma binaria
            binary1 = bin(integer_sum)
        
        lettera_codificata=[]

        numero_binario=""
        for n_bit in range(2,len(binary1)):
            numero_binario+=binary1[n_bit]

        for _ in range(BIT_CODIFICA-len(numero_binario)):  # inserisco zero per completare la codifica, metto il -2 perché i numeri binari inizano con 0b
            lettera_codificata.append(0)
        
        for bit in numero_binario:
            lettera_codificata.append(bit)   # inserisco i bit della somma

        dizionario_codifica_caratteri[carattere]=lettera_codificata   # la aggiungo al dizionario


def conversioneStringa(stringa):
    stringa_codificata=[]
    for carattere in stringa:
        stringa_codificata.append(dizionario_codifica_caratteri[carattere])

    return stringa_codificata


def salvataggioStringaCodificataSuFile(stringa_codificata):
    with open('./stringa_codificata.csv', 'w') as file:
        writer = csv.writer(file)
        for lista in stringa_codificata:
            writer.writerow([str(lista[0])+" ", str(lista[1])+" ", str(lista[2])+" ", str(lista[3])+" ", str(lista[4])+" "])


def inizializzazioneFinestra(numero_caratteri_stringa):
    pygame.init()
    dimensione_qr_code = (DIMENSIONE_RETTANGOLO_BIT*numero_caratteri_stringa, DIMENSIONE_RETTANGOLO_BIT*numero_caratteri_stringa)
    global finestra
    finestra = pygame.display.set_mode(dimensione_qr_code)
    finestra.fill(COLORE_SFONDO)


def disegnoQrCode(nome_file, numero_caratteri_stringa):
    inizializzazioneFinestra(numero_caratteri_stringa)

    with open(nome_file, 'w') as file:
        reader = csv.reader(file, delimiter=" ")
        num_riga=0
        for riga in reader:
            for i in range(BIT_CODIFICA):
                piastrella = pygame.Rect(i*DIMENSIONE_RETTANGOLO_BIT,num_riga*DIMENSIONE_RETTANGOLO_BIT,DIMENSIONE_RETTANGOLO_BIT,DIMENSIONE_RETTANGOLO_BIT)
                if(riga[i]=='0'):
                    pygame.draw.rect(finestra, COLORE_BIT_0, piastrella)
                else:
                    pygame.draw.rect(finestra, COLORE_BIT_1, piastrella)
        num_riga+=1

    pygame.display.update() # serve per aggiornare la finestra


def main():
    generazioneCodificaCaratteri()
    stringa = input("Inserire una stringa: ")
    verificaStringaInserita(stringa)
    stringa_codificata=conversioneStringa(stringa)
    print(stringa_codificata)
    salvataggioStringaCodificataSuFile(stringa_codificata)


    nome_file='./stringa_codificata.csv'
    while(True):
        disegnoQrCode(nome_file,len(stringa))
        # ciclo for per gestione eventi
        for event in pygame.event.get():
            if(event.type == pygame.QUIT):
                pygame.quit()  # serve per chiudere la finestra
                sys.exit() # serve per terminare il programma python


if __name__ == "__main__":
    main()