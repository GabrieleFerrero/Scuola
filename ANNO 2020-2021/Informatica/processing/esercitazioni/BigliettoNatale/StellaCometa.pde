public class StellaCometa{
  
  private static final int ALTEZZA_CODA = 50;
  private static final int LARGHEZZA_CODA = 100;
  private static final int LATO_STELLA = 30;
  private color GIALLO = color(255,255,0);
  
  public StellaCometa(){
  }
  
  public void disegnaStellaCometa(int x, int y){
    fill(GIALLO);
    triangle(x,y,x+LARGHEZZA_CODA,y-(ALTEZZA_CODA/2),x,y-ALTEZZA_CODA);
    
    noStroke();
    fill(GIALLO);
    beginShape();
    
    x=x+LARGHEZZA_CODA;
    y=y-(ALTEZZA_CODA/2);
    vertex(x,y);
    
    x=x+LATO_STELLA;
    vertex(x,y);
    
    x=x+(LATO_STELLA/2);
    y=y-LATO_STELLA;
    vertex(x,y);
    
    x=x+(LATO_STELLA/2);
    y=y+LATO_STELLA;
    vertex(x,y);
    
    x=x+LATO_STELLA;
    vertex(x,y);
    
    x=x-LATO_STELLA;
    y=y+LATO_STELLA;
    vertex(x,y);
    
    x=x+LATO_STELLA;
    y=y+LATO_STELLA+(LATO_STELLA/2);
    vertex(x,y);
    
    x=x-LATO_STELLA-(LATO_STELLA/2);
    y=y-LATO_STELLA;
    vertex(x,y);
    
    x=x-LATO_STELLA-(LATO_STELLA/2);
    y=y+LATO_STELLA;
    vertex(x,y);
    
    x=x+LATO_STELLA;
    y=y-LATO_STELLA-(LATO_STELLA/2);
    vertex(x,y);
    
    endShape();
  }  
}
