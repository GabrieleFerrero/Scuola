"""
ROBOT E PAVIMENTI

Dati:
- forma stanza: rettangolare
- piastrelle che formano una matrice (Nx,Ny)
- ci sono degli ostacoli che occupano delle piastrelle singole

STEP 1:
- memorizzare il pavimento in una matrice
- etichettare le celle libere
- creare un dizionario 

"""

import random
import sys
import pygame

PIASTRELLA_LIBERA = (0,0,0)
PIASTRELLA_OCCUPATA = (255,255,255)
SFONDO = (255,0,0)
DIMENSIONE_PIASTRELLA = 50
PROBABILITA_OSTACOLO = 0.2

def calcolatoreMappaPavimento(x,y):
    pavimento=[]

    for _ in range(x):
        riga=[]
        for _ in range(y):
            x = random.random() #sorteggia un numero tra 0 e 1, float    ---   invece con random.uniform() sorteggia un numero tra i due estremi che metti dentro la tonda
            if x<PROBABILITA_OSTACOLO:
                riga.append(1)
            else:
                riga.append(0)
        
        pavimento.append(riga)

    return pavimento


def calcolatoreNumeroPiastrelleLarghezzaAltezzaStanza():
    x = random.randint(6,10)
    y = random.randint(6,10)

    global dimensioni
    dimensioni = (x*DIMENSIONE_PIASTRELLA,y*DIMENSIONE_PIASTRELLA)

    return x,y

def creazioneMatriceIdPiastrelle(pavimento):
    copy_pavimento = [riga.copy() for riga in pavimento]
    print(copy_pavimento)
    for x in range(len(copy_pavimento)):
        for y in range(len(copy_pavimento[x])):
            if(copy_pavimento[x][y]==0):
                copy_pavimento[x][y]=str("LIBERA_"+str(x)+"_"+str(y))
            else:
                copy_pavimento[x][y]=str("OSTACOLO_"+str(x)+"_"+str(y))
    return copy_pavimento


def creazioneDizionarioPossibiliSpostamenti(matrice_id):
    dizionario_possibili_movimenti = {}
    spostamenti = []
    for x in range(len(matrice_id)):
        for y in range(len(matrice_id[x])):
            if(matrice_id[x][y]!=presenzaOstacolo(x,y)):
                if(y-1>0 and matrice_id[x][y-1]!=presenzaOstacolo(x,y-1)):
                    spostamenti.append(matrice_id[x][y-1])

                if(y+1<len(matrice_id[x]) and matrice_id[x][y+1]!=presenzaOstacolo(x,y+1)):
                    spostamenti.append(matrice_id[x][y+1])

                if(x-1>0 and matrice_id[x-1][y]!=presenzaOstacolo(x-1,y)):
                    spostamenti.append(matrice_id[x-1][y])
                
                if(x+1<len(matrice_id) and matrice_id[x+1][y]!=presenzaOstacolo(x+1,y)):
                    spostamenti.append(matrice_id[x+1][y])

                dizionario_possibili_movimenti[matrice_id[x][y]]=spostamenti

                spostamenti = []
    
    return dizionario_possibili_movimenti

 
def presenzaOstacolo(x,y):
    return "OSTACOLO_"+str(x)+"_"+str(y)


def estrazioneCoordinateDaCella(cella):
    parti_divise=cella.split("_")
    return parti_divise[1], parti_divise[2]    

def inizializzazioneFinestra():
    pygame.init()
    global finestra
    finestra = pygame.display.set_mode(dimensioni)
    finestra.fill(SFONDO)

def drawgrid(pavimento): #questa funzione disegna una matrice, disegnando colonna per colonna
    for x in range(len(pavimento)):
        for y in range(len(pavimento[x])):
            piastrella = pygame.Rect(x*DIMENSIONE_PIASTRELLA,y*DIMENSIONE_PIASTRELLA,DIMENSIONE_PIASTRELLA,DIMENSIONE_PIASTRELLA)
            if(pavimento[x][y]==1):
                pygame.draw.rect(finestra, PIASTRELLA_OCCUPATA, piastrella)
            else:
                pygame.draw.rect(finestra, PIASTRELLA_LIBERA, piastrella)


def main():
    x,y = calcolatoreNumeroPiastrelleLarghezzaAltezzaStanza()
    pavimento = calcolatoreMappaPavimento(x,y)
    print(str(pavimento)+"\n\n")

    matrice_id = creazioneMatriceIdPiastrelle(pavimento)
    print(str(pavimento)+"\n\n")
    dizionario_possibili_movimenti = creazioneDizionarioPossibiliSpostamenti(matrice_id)

    print(str(dizionario_possibili_movimenti)+"\n\n")
   
    print(str(matrice_id)+"\n\n")

    inizializzazioneFinestra()
    
    while True:
        drawgrid(pavimento)
        # ciclo for per gestione eventi
        for event in pygame.event.get():
            if(event.type == pygame.QUIT):
                pygame.quit()  # serve per chiudere la finestra
                sys.exit() # serve per terminare il programma python

        pygame.display.update() # serve per aggiornare la finestra



if __name__ == "__main__":
    main()