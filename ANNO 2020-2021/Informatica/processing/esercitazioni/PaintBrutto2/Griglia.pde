class Griglia {
  private float altezza, larghezza;
  private int righe, colonne;
  private ListaQuadretti lQuadretti;
  
  public Griglia(float altezza, float larghezza, int righe, int colonne) {
    this.altezza=altezza;
    this.larghezza=larghezza;
    this.righe=righe;
    this.colonne=colonne;
    this.lQuadretti = new ListaQuadretti(this);
  }
  
  public float larghezzaQuadretto() {
    return larghezza / colonne;
  }

  public float altezzaQuadretto() {
    return altezza / righe;
  }  
  
  public void disegna() {
    float lq = larghezzaQuadretto();
    float hq = altezzaQuadretto();
    
    // disegna griglia
    for(int i=0; i<=righe; i++) {
      line(0, hq*i, larghezza, hq*i);
    }
    for(int i=0; i<=colonne; i++) {
      line(lq*i, 0, hq*i, altezza);
    }
    lQuadretti.disegna();
  }
  
  public float getLarghezza() {
    return larghezza;
  }

  public float getAltezza() {
    return altezza;
  }
  
  public int getColonne() {
    return colonne;
  }
  
  public int getRighe() {
    return righe;
  }
  
  public void clickMouse(float xm, float ym){
    int r = (int) (ym*this.righe/this.larghezza);
    int c = (int) (xm*this.colonne/this.altezza);
    Quadretto q = new Quadretto(r, c);
    lQuadretti.aggiungiQuadretto(q);
    
  }
  
  public void disegnaQuadretto(Quadretto q){
    fill(#ff0000);
    stroke(#ff0000);
    rect((q.getC()*larghezza/colonne), (q.getR()*altezza/righe), larghezza/colonne, altezza/righe);
  }
}
