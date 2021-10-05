public class Luce{
  private color LUCE_ON = color(255,255,0);
  private color LUCE_OFF = color(125,125,125);
  private boolean accesa;
  private float posX;
  private float posY;
  private float raggio;
  private static final int LARGHEZZA_FINESTRA = 1000;
  private static final int ALTEZZA_FINESTRA = 600;
  
  public Luce(float posX, float posY, float raggio, boolean accesa){
      this.posX=posX;
      this.posY=posY;
      this.raggio=raggio;
      this.accesa=accesa;
  }
  
  public void draw(){
    if(this.accesa){
      fill(LUCE_ON);
    }else{
      fill(LUCE_OFF);
    }
    circle(this.posX, this.posY, this.raggio*2);
  }
  
  public void premuto(float x, float y){   
    if(raggio*raggio>(((this.posX-x)*(this.posX-x))+((this.posY-y)*(this.posY-y)))){
      this.accesa=!this.accesa;
    }
  }
  
}
