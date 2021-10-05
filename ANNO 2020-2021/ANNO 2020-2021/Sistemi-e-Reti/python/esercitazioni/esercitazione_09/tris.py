"""
Realizzare un gioco in python utilizzando la libreria pygame
"""

import CampoDaGioco
import sys
import pygame


SFONDO = (255,255,255)
DIMENSIONE_CASELLA = 300
DIMENSIONI_FINESTRA = (900,900)
pyg = pygame


def inizializzazioneFinestra():
    pyg.init()
    global finestra
    finestra = pygame.display.set_mode(DIMENSIONI_FINESTRA)
    finestra.fill(SFONDO)


def main():

    inizializzazioneFinestra()

    campo = CampoDaGioco.CampoDaGioco(pyg, finestra, DIMENSIONE_CASELLA)    
    
    while True:

        campo.draw()

        vincitore=campo.verificaVittoria()

        if(vincitore!=False):
            print("Il vincitore è il: "+vincitore)
            sys.exit() # serve per terminare il programma python
        
        # ciclo for per gestione eventi
        for event in pygame.event.get():
            if(event.type == pygame.QUIT):
                pygame.quit()  # serve per chiudere la finestra
                sys.exit() # serve per terminare il programma python
            if(event.type == pygame.MOUSEBUTTONUP):
                x,y = pygame.mouse.get_pos()
                print(str(x)+" "+str(y))
                campo.premuto(x,y)

        pygame.display.update() # serve per aggiornare la finestra



if __name__ == "__main__":
    main()