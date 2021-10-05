import Casella

class CampoDaGioco:

    COLORE_INIZIALE_CASELLA = (210,210,210)
    ROSSO=(255,0,0)
    BLU=(0,0,255)
    NUMERO_DI_CASELLE_PER_LATO = 3
    campo_da_gioco=[]
    campo_da_gioco_ID=[]
    colore=[ROSSO, BLU]
    scelta_colore=0

    def __init__(self,pyg, finestra, dimensione_casella):
        self.pyg=pyg
        self.finestra=finestra
        self.dimensione_casella=dimensione_casella

        for x in range(self.NUMERO_DI_CASELLE_PER_LATO):
            colonna=[]
            colonna_ID=[]
            for y in range(self.NUMERO_DI_CASELLE_PER_LATO):
                casella=Casella.Casella(x, y, self.dimensione_casella, self.pyg, self.finestra, self.COLORE_INIZIALE_CASELLA)
                colonna.append(casella)
                colonna_ID.append(-1)
            self.campo_da_gioco.append(colonna)
            self.campo_da_gioco_ID.append(colonna_ID)

    def draw(self):
        for colonna in self.campo_da_gioco:
            for casella in colonna:
                casella.draw()
    
    def premuto(self, coord_x, coord_y):
        for colonna in self.campo_da_gioco:
            for casella in colonna:
                x,y=casella.getCoord()
                if(self.campo_da_gioco_ID[x][y]==-1):
                    if(casella.premuto(coord_x,coord_y, self.colore[self.scelta_colore])):  # faccio una doppia verifica perché la casella deve essere stata si premuta, ma lo deve essere stata solo una volta
                        self.campo_da_gioco_ID[x][y]=self.scelta_colore  # il ROSSO è il giocatore uno e corrisponde al numero 0 , il BLU è il giocatore due e corrisponde al numero 1
                        if(self.scelta_colore==0):
                            self.scelta_colore=1
                        elif(self.scelta_colore==1):
                            self.scelta_colore=0
                        print("È IL TURNO DELL'ALTRO GIOCATORE")


    def verificaVittoria(self):

        for x in range(self.NUMERO_DI_CASELLE_PER_LATO):  # verifica verticale
            if(self.campo_da_gioco_ID[x][0]==self.campo_da_gioco_ID[x][1] and self.campo_da_gioco_ID[x][1]==self.campo_da_gioco_ID[x][2]):
                if(self.determinaVincitore(self.campo_da_gioco_ID[x][0])!=False):
                    return self.determinaVincitore(self.campo_da_gioco_ID[x][0])

        for y in range(self.NUMERO_DI_CASELLE_PER_LATO):  # verifica orizzonatale
            if(self.campo_da_gioco_ID[0][y]==self.campo_da_gioco_ID[1][y] and self.campo_da_gioco_ID[1][y]==self.campo_da_gioco_ID[2][y]):
                if(self.determinaVincitore(self.campo_da_gioco_ID[0][y])!=False):
                    return self.determinaVincitore(self.campo_da_gioco_ID[0][y])
        
        # verifica obliqua
        if(self.campo_da_gioco_ID[0][0]==self.campo_da_gioco_ID[1][1] and self.campo_da_gioco_ID[1][1]==self.campo_da_gioco_ID[2][2]):
            if(self.determinaVincitore(self.campo_da_gioco_ID[0][0])!=False):
                return self.determinaVincitore(self.campo_da_gioco_ID[0][0])
        
        # verifica obliqua
        if(self.campo_da_gioco_ID[0][2]==self.campo_da_gioco_ID[1][1] and self.campo_da_gioco_ID[1][1]==self.campo_da_gioco_ID[2][0]):
            if(self.determinaVincitore(self.campo_da_gioco_ID[0][2])!=False):
                return self.determinaVincitore(self.campo_da_gioco_ID[0][2])

        return False


    def determinaVincitore(self, ID):
        if(ID==0):
            return "ROSSO"
        elif(ID==1):
            return "BLU"
        else:
            return False
    