"""
Il nostro amico Bob dopo alcune commissioni in giro per la città di Flatland deve rientrare a casa. Purtroppo Bob soffre di momentanee perdite di memoria!
Questa volta la sua amnesia dura ben 60 minuti e durante questi 60 minuti Bob adotta la seguente strategia per tentare di rientrare a casa. Ogni minuto decide a caso tra:
- procedere 10 m verso Nord
- procedere 10 m verso Sud
- procedere 10 m verso Est
- procedere 10 m verso Ovest

Simulare l’intero percorso compiuto da Bob, supponendo che il punto di partenza abbia coordinate (0,0) e salvarlo all’interno di un dizionario opportunamente strutturato.
Disegnare il percorso compiuto da Bob dentro una schermata di pygame.
Infine salvare il percorso di Bob dentro un file .csv opportunamente strutturato.

BONUS: ogni volta in cui Bob passa in un punto della città di Flatland in cui è già passato, stampare a schermo le coordinate del punto.

"""

import random
import sys
import pygame
import csv

MINUTI_DI_AMNESIA = 60
DIMENIONE_LINEA = 10
COLORE_LINEA = (255,0,0)
COLORE_SFONDO = (255,255,255)

dizionarioMovimentiDiBob = {}

def spostamentoNord(coord_X, coord_Y):
    coord_Y-=10
    return coord_X, coord_Y

def spostamentoSud(coord_X, coord_Y):
    coord_Y+=10
    return coord_X, coord_Y

def spostamentoOvest(coord_X, coord_Y):
    coord_X-=10
    return coord_X, coord_Y

def spostamentoEst(coord_X, coord_Y):
    coord_X+=10
    return coord_X, coord_Y

dizionarioPossibiliSpostamenti={1:spostamentoNord, 2:spostamentoSud, 3:spostamentoOvest, 4:spostamentoEst}

def creazioneRandomicaPercorsoBob():
    coord_X=0
    coord_Y=0

    global dizionarioMovimentiDiBob
    
    for minuto in range(60):
        coordinate=[coord_X, coord_Y]
        dizionarioMovimentiDiBob[minuto] = coordinate
        coord_X, coord_Y = dizionarioPossibiliSpostamenti[random.randint(1,4)](coord_X, coord_Y)


def inizializzazioneFinestra():
    pygame.init()
    global finestra
    finestra = pygame.display.set_mode(dimensioni)
    finestra.fill(COLORE_SFONDO)


def calcoloDimensioniFinestra():
    max_X = -1
    max_Y = -1
    min_X=0  # correggere
    min_Y=0
    for chiave, coordinate in dizionarioMovimentiDiBob.items():
        if(max_X<coordinate[0]):
            max_X=coordinate[0]

        if(max_Y<coordinate[1]):
            max_Y=coordinate[1]

    global dimensioni
    dimensioni=(max_X*DIMENIONE_LINEA, max_Y*DIMENIONE_LINEA)

def salvataggioPercorsoDentroFileCSV():
    minuto=0
    with open('./percorsoBob.csv', 'w') as file:
        writer = csv.writer(file)
        writer.writerow(["Minuto", "Coordinata X", "Coordinata Y"])
        for chiave, coordinate in dizionarioMovimentiDiBob.items():
            writer.writerow([minuto, coordinate[0], coordinate[1]])
            minuto+=1

def disegnaPercorso():
    coord_X_prec=0
    coord_Y_prec=0
    for chiave, coordinate in dizionarioMovimentiDiBob.items():
        pygame.draw.line (finestra, COLORE_LINEA, (coord_X_prec, coord_Y_prec), (coordinate[0], coordinate[1]), DIMENIONE_LINEA) 
        coord_X_prec=coordinate[0]
        coord_Y_prec=coordinate[1]
    pygame.display.update() # serve per aggiornare la finestra

def percorsoSovrapposto():
    for chiave, coordinate in dizionarioMovimentiDiBob.items():
        coordinate_uguali = False
        for chiave1, coordinate1 in dizionarioMovimentiDiBob.items():
            if(coordinate[0]==coordinate1[0] and coordinate[1]==coordinate1[1]):
                coordinate_uguali=True
        if(coordinate_uguali):
            print(coordinate[0], coordinate[1])

def main():
    creazioneRandomicaPercorsoBob()
    salvataggioPercorsoDentroFileCSV()
    percorsoSovrapposto()
    calcoloDimensioniFinestra()
    inizializzazioneFinestra()

    while True:
        disegnaPercorso()
        # ciclo for per gestione eventi
        for event in pygame.event.get():
            if(event.type == pygame.QUIT):
                pygame.quit()  # serve per chiudere la finestra
                sys.exit() # serve per terminare il programma python

        pygame.display.update() # serve per aggiornare la finestra



if __name__ == "__main__":
    main()

