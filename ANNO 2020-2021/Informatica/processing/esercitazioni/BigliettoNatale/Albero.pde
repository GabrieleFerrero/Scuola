public class Albero{
  private static final int LARGHEZZA_FINESTRA = 1000;
  private static final int ALTEZZA_FINESTRA = 600;
  private color MARRONE = color(101,67,33);
  private color VERDE = color(0,255,0);
  private static final int N_ALBERI = 10;
  private int [] posX = new int [N_ALBERI];
  private int [] altezza = new int [N_ALBERI];
  private int [] larghezza = new int [N_ALBERI];
  
  public Albero(){
    for(int i=0; i<N_ALBERI;i++){
      this.posX[i]=round(random(0,LARGHEZZA_FINESTRA));
      this.altezza[i]=round(random(50,300));
      this.larghezza[i]=round(random(50,150));
    }
  }
  
  public void disegnaAlbero(int larghezza, int altezza, int posizioneX, int posizioneY){
    int altezza_tronco = altezza/4;
    int altezza_chioma = altezza-altezza_tronco;
     
    int larghezza_tronco = larghezza/3;
    int larghezza_chioma = larghezza;
    
    /*
    if(posizioneX<0 || posizioneX>LARGHEZZA_FINESTRA || posizioneY<0 || posizioneY>ALTEZZA_FINESTRA){
      throw new Exception("coordinate x e y non valide");
    }
    */
    
    /*
    if(larghezza<0 || altezza<0 || posizioneY-altezza_tronco-altezza_chioma<0 || posizioneX+(larghezza_chioma/2)+(larghezza_tronco/2)>ALTEZZA_FINESTRA || posizioneX-(larghezza_chioma/2)+(larghezza_tronco/2)<0){
      throw new Exception("dimensioni non valide");
    }   
    */
     
    fill(MARRONE);
    rect(posizioneX,posizioneY-altezza_tronco,larghezza_tronco,altezza_tronco);
     
    fill(VERDE);
    triangle(posizioneX-(larghezza_chioma/2)+(larghezza_tronco/2),posizioneY-altezza_tronco,posizioneX+(larghezza_chioma/2)+(larghezza_tronco/2),posizioneY-altezza_tronco,posizioneX+(larghezza_tronco/2),posizioneY-altezza_chioma-altezza_tronco);  
  }
  
  public void disegnaForesta(int x){
    for(int i=0; i<N_ALBERI; i++){
      disegnaAlbero(this.larghezza[i],this.altezza[i],this.posX[i]+x,ALTEZZA_FINESTRA);
    }
  }
}
