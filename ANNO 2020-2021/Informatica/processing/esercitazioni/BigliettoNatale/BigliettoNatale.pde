Albero pino = new Albero();
CieloStellato cielo = new CieloStellato();
StellaCometa stella = new StellaCometa();
int PUNTO_DI_INIZIO_STELLA_COMETA = -100;
int x=PUNTO_DI_INIZIO_STELLA_COMETA;
int y=100;

public void setup(){
  size(1000,600);
  background(255,255,255);
}

public void draw(){
  cielo.disegnaCieloStellato(0);
  pino.disegnaForesta(0);
  stella.disegnaStellaCometa(x,y);
  x+=5;
  if(x>1000){
    x=PUNTO_DI_INIZIO_STELLA_COMETA;
  }
  delay(1);
}
