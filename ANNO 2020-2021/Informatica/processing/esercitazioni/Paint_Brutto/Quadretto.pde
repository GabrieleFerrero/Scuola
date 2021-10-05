public class Quadretto{
  
  private float larghezza;
  private float altezza;
  private float x;
  private float y;
  private static final int N_COLORI=3;
  private color[] set_colori = new color[N_COLORI];
  private color ROSSO = color(255,0,0);
  private color VERDE = color(0,255,0);
  private color BLU = color(0,0,255);
  private int numero_colore;
  
  
  public Quadretto(float larghezza, float altezza, float x, float y){
    this.set_colori[0]=ROSSO;
    this.set_colori[1]=VERDE;
    this.set_colori[2]=BLU;
    this.numero_colore=0;
    this.larghezza=larghezza;
    this.altezza=altezza;
    this.x=x*this.larghezza;
    this.y=y*this.altezza;
  }
  
  public void draw(){
    stroke(0,0,0);
    fill(this.set_colori[this.numero_colore]);
    rect(this.x, this.y, this.larghezza, this.altezza);
  }
  
  public void premuto(float x, float y){
    if((x>this.x && x<this.x+this.larghezza)&&(y>this.y && y<this.y+this.altezza)){
      if(this.numero_colore>=N_COLORI-1){
        this.numero_colore=0;
      }else{
        this.numero_colore++;
      }
    }
  }
  
  
  
  
  
  
}
