//creazione e inizializzazione variabili
DisegnaCampo campo = new DisegnaCampo();
Verme verme = new Verme();

String direzione = "right";

int [][] matrice = new int [campo.getNumeroCellePerLato()][campo.getNumeroCellePerLato()];
//---------------------------------------

/*
creazione funione setup per la inizializzazione e settaggio dei valori iniziali
*/
public void setup(){
  size(600,600);
  matrice = campo.inizializzazioneCampo();
  matrice = verme.getVerme(matrice);
  matrice = campo.getCibo(matrice);
  matrice = campo.getOstacoli(matrice);
  campo.disegna(matrice);
}
//---------------------------------------

/*
creazione funzione draw per il movimento del verme
*/
public void draw(){
  try{
  matrice = verme.Direzione(direzione, matrice);
  }catch(Exception e){
    background(255,0,0);
    fill(0,0,0);
    textSize(18);
    text("Il tuo punteggio è di: " + verme.getPunteggio(), (600/2)-100, 600/2);
    delay(3000);
    exit();
  }
  delay(200);
}
//---------------------------------------

/*
creazione funzione per il cambio direzione del verme
*/
void keyPressed(){
  if(key==CODED){
    if(keyCode==UP){
      direzione="up";
    }
    if(keyCode==DOWN){
      direzione="down";
    }
    if(keyCode==RIGHT){
      direzione="right";
    }
    if(keyCode==LEFT){
      direzione="left";
    }
  }
}
//---------------------------------------
