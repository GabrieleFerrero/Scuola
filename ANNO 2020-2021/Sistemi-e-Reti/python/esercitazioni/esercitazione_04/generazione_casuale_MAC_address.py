"""
programma per generare un indirizzo MAC casuale
"""

import random
import string  # avrei potuto psommare le due liste in una unica di tutti i valori digitabili

caratteri_possibili = ['0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F']
LUNGHEZZA_MAC_ADDRESS = 12

def generaMAC():  # funzione per generazione casuale di indirizzi MAC
    mac=""
    for indice in range(LUNGHEZZA_MAC_ADDRESS): 
        mac+=random.choice(caratteri_possibili)  
        if(indice%2 != 0 and indice != LUNGHEZZA_MAC_ADDRESS-1):
            mac+=":"
    return mac


def main():  # main per richiamare la funzione generaMAC()
    print("l'indirizzo MAC generato è: "+ generaMAC())


if __name__ == "__main__":
    main()