public class Matrice{
  
  private float larghezza;
  private float altezza;
  private int n_colonne;
  private int n_righe;
  private Quadretto[][] matrice;
  private static final int WIDTH = 600;
  private static final int HEIGHT = 600;
  
  
  public Matrice(float larghezza, float altezza, int n_colonne, int n_righe)throws Exception{
    try{
      getLarghezza(larghezza);
      getAltezza(altezza);
      getColonne(n_colonne);
      getRighe(n_righe);
    }catch(Exception e){
      throw new Exception("errore nell'inserimento dei dati");
    }

    matrice= new Quadretto[this.n_colonne][this.n_righe];
    
    for(int x=0; x<this.n_colonne; x++){
      for(int y=0; y<this.n_righe; y++){
        matrice[x][y]= new Quadretto(this.larghezza/this.n_colonne, this.altezza/this.n_righe, x, y);
      }
    }
  }
  
  private void getLarghezza(float larghezza)throws Exception{
    if(larghezza>WIDTH || larghezza<=0){
      throw new Exception("larghezza non giusta");
    }else{
      this.larghezza=larghezza;
    }
  }
  
  private void getAltezza(float altezza)throws Exception{
    if(altezza>HEIGHT || altezza<=0){
      throw new Exception("altezza non giusta");
    }else{
      this.altezza=altezza;
    }
  }
  
  private void getColonne(int n_colonne)throws Exception{
    if(n_colonne<=0){
      throw new Exception("altezza non giusta");
    }else{
      this.n_colonne=n_colonne;
    }
  }
  
  private void getRighe(int n_righe)throws Exception{
    if(n_righe<=0){
      throw new Exception("altezza non giusta");
    }else{
      this.n_righe=n_righe;
    }
  }
  
  public void draw(){
    for(int x=0; x<this.n_colonne; x++){
      for(int y=0; y<this.n_righe; y++){
        matrice[x][y].draw();
      }
    }
  }
  
  public void premuto(float coord_x, float coord_y){
    for(int x=0; x<this.n_colonne; x++){
      for(int y=0; y<this.n_righe; y++){
        matrice[x][y].premuto(coord_x, coord_y);
      }
    }
  }
  
}
