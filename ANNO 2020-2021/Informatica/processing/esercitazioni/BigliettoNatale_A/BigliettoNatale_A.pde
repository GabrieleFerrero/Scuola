Foresta foresta;
StellaCometa stella;
CatenaDiLuci catena_di_luci;
int PUNTO_DI_INIZIO_STELLA_COMETA = -100;
int x=PUNTO_DI_INIZIO_STELLA_COMETA;
int y=100;

public void setup(){
  size(1000,600);
  background(255,255,255);
  stella = new StellaCometa();
  foresta = new Foresta();
  catena_di_luci = new CatenaDiLuci();
}

public void draw(){
  catena_di_luci.draw();
  foresta.draw();
  stella.disegnaStellaCometa(x,y);
  x+=5;
  if(x>width){
    x=PUNTO_DI_INIZIO_STELLA_COMETA;
  }
  delay(1);
}

public void mousePressed(){
  catena_di_luci.premuto(mouseX,mouseY);
}
