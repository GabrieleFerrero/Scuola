public class Foresta{
  private static final int N_ALBERI = 10;
  private static final int LARGHEZZA_FINESTRA = 1000;
  private static final int LARGHEZZA_MAX_ALBERO = 100;
  private static final int ALTEZZA_MAX_ALBERO = 300;
  Albero[] albero;
  
  public Foresta(){
    int posX;
    int larghezza;
    int altezza;
    
    albero = new Albero[N_ALBERI];
    
    for(int i=0; i<N_ALBERI; i++){
      posX=round(random(0,LARGHEZZA_FINESTRA));
      larghezza=round(random(0,LARGHEZZA_MAX_ALBERO));
      altezza=round(random(0,ALTEZZA_MAX_ALBERO));
      albero[i]= new Albero(posX,altezza,larghezza);
    }
  }
  
  public void draw(){
    for(int i=0; i<N_ALBERI; i++){
      albero[i].draw();
    }
  }
  
  
  
  
  
}
