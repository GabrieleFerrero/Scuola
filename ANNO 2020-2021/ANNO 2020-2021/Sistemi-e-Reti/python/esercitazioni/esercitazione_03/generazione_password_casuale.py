"""
programma per generazione casuale di password a lunghezza variabile
"""

import random
import string  # avrei potuto psommare le due liste in una unica di tutti i valori digitabili

caratteri_possibili = ['0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']


def generaPassword(lunghezza_password):  # funzione per generazione casuale di password
    password=""
    for _ in range(lunghezza_password):  # inserisco il trattino basso per non dovere creare un indice che poi non utilizzo
        password+=random.choice(caratteri_possibili)
    return password


def main():  # main per chiedere in input la lunghezza della password
    n=0
    n=int(input("inserire la lunghezza che si vuole della password: "))
    print("la password è: "+ generaPassword(n))


if __name__ == "__main__":
    main()