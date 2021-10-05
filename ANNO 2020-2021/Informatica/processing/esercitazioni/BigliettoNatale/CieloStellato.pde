public class CieloStellato{
  private static final int N_STELLE = 100;
  private color BIANCO = color(255,255,255);
  private int [] posX = new int [N_STELLE];
  private int [] posY = new int [N_STELLE];
  private float [] dim = new float [N_STELLE];
  private static final int LARGHEZZA_FINESTRA = 1000;
  private static final int ALTEZZA_FINESTRA = 600;
  
  public CieloStellato(){
    for(int i=0; i<N_STELLE; i++){
      this.posX[i]=round(random(0,LARGHEZZA_FINESTRA));
      this.posY[i]=round(random(0,ALTEZZA_FINESTRA));
      this.dim[i]=random(1.0,10.0);
    }
  }
  
  public void disegnaCieloStellato(int x){
    background(37,40,80);
    for(int i=0; i<N_STELLE; i++){
      fill(BIANCO);
      circle(this.posX[i]+x,this.posY[i],this.dim[i]);
    } 
  }
}
