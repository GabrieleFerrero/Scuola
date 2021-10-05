class Casella:

    def __init__(self, posX, posY, dim, pyg, finestra, colore):
        self.posX=posX
        self.posY=posY
        self.dim=dim
        self.pyg=pyg
        self.finestra=finestra
        self.colore=colore

    def premuto(self, coord_x, coord_y, colore):
        if((coord_x>self.posX*self.dim and coord_x<(self.posX*self.dim)+self.dim)and(coord_y>self.posY*self.dim and coord_y<(self.posY*self.dim)+self.dim)):
            self.colore=colore
            return True
        else:
            return False

    def draw(self):
        casella = (self.pyg).Rect(self.posX*self.dim,self.posY*self.dim,self.dim,self.dim)
        (self.pyg).draw.rect(self.finestra, self.colore, casella)

    def getCoord(self):
        return self.posX, self.posY
        
