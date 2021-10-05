//creazione variabili
int dimensione_albero = 5;
Fiocco_di_neve neve;
Albero_di_natale pino;
//-------------------------------------

/*
creazione funzione setup:
1. imposto i parametri dello sfondo
2. creo la variabile pino (facendo gli opportuni controlli sula dimensione inserita dall'utente) e neve
*/
public void setup(){
  
  //settaggio parametri sfondo
  frameRate(30);
  noStroke();
  smooth();
  size(500, 500);
  background(175,238,238);
  //-------------------------------------
  
  //creazione variabile pino con opportuni controlli
  try{
    pino = new Albero_di_natale(dimensione_albero);
  }catch(Exception e){
    background(255,0,0);
    fill(0,0,0);
    textSize(18);
    textAlign(CENTER);
    text("DIMENSIONE INSERITA TROPPO GRANDE", width/2, height/2);
  }
  //-------------------------------------
  
  //creazione variabile neve
  neve = new Fiocco_di_neve();
  //-------------------------------------
  
}

/*
creazione funzione draw:
1. setto il colore del background
2. richiamo la funzione disegna dell'oggetto neve
3. richiamo la funzione disegna dell'oggetto pino
*/
public void draw(){
  
  //setto colore dello sfondo
  background(175,238,238);
  //-------------------------------------
  
  //richiamo la funzione disegna dell'oggetto neve
  neve.disegna();
  //-------------------------------------
  
  //richiamo la funzione disegna dell'oggetto pino
  pino.disegna();
  //-------------------------------------
}
