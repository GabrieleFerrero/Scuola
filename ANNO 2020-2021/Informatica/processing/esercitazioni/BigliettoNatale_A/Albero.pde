public class Albero{
  private static final int LARGHEZZA_FINESTRA = 1000;
  private static final int ALTEZZA_FINESTRA = 600;
  private color MARRONE = color(101,67,33);
  private color VERDE = color(0,255,0);
  private int posX;
  private int posY;
  private int altezza;
  private int larghezza;
  
  public Albero(int posX, int altezza, int larghezza){
      this.posX = posX;
      this.posY = ALTEZZA_FINESTRA;
      this.altezza = altezza;
      this.larghezza = larghezza;
  }
  
  public void draw(){
    int altezza_tronco = this.altezza/4;
    int altezza_chioma = this.altezza-altezza_tronco;
     
    int larghezza_tronco = this.larghezza/3;
    int larghezza_chioma = this.larghezza;

    fill(MARRONE);
    rect(this.posX,posY-altezza_tronco,larghezza_tronco,altezza_tronco);
     
    fill(VERDE);
    triangle(posX-(larghezza_chioma/2)+(larghezza_tronco/2),posY-altezza_tronco,posX+(larghezza_chioma/2)+(larghezza_tronco/2),posY-altezza_tronco,posX+(larghezza_tronco/2),posY-altezza_chioma-altezza_tronco);  
  }
  
}
