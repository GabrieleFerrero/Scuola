public class Fiocco_di_neve{
  
  //creazione variabili
  int quantity = 300;
  float [] xPosition = new float[quantity];
  float [] yPosition = new float[quantity];
  int [] flakeSize = new int[quantity];
  int [] direction = new int[quantity];
  float [] spostamento = new float[quantity];
  int minFlakeSize = 1;
  int maxFlakeSize = 5;
  //-------------------------------------
  
  /*
  creazione costruttore:
  1. fare un ciclo for in cui vengono settate in modo randomico tutte le variabili dei vari array
  */
  public Fiocco_di_neve() {
    for(int i = 0; i < quantity; i++) {
      flakeSize[i] = (int)(random(minFlakeSize, maxFlakeSize));
      xPosition[i] = random(0, width);
      yPosition[i] = random(0, height);
      direction[i] = (int)(random(0, 1));
      spostamento[i] = random(0, 1);
    }
    
  }
  
  /*
  creazione funzione disegna:
  1. fare un ciclo for (che cicla fino a quando non si arriva alla fine degli array) in cui:
    1. viene disegnato il fiocco di neve con le coordinate e le dimensioni contenute negli array addetti e viene inseguito colorato di bianco
    2. viene fatto un primo controllo sul fatto che la direzione contenuta alla cella iesima dell'array direction sia = 0 se sì sommo la variabile xPosition iesima 
       di spostamento se no lo vado a sottrarre
    3. viene incrementata la variabile yPosition della dimensione del fiocco di neve e dello spostamento
    4. infine viene fatto un ultimo controllo nel quale se la variabile xPosition del fiocco di neve è maggiore della lunghezza della finestra oppure
       se yPosition è maggiore dell'altezza della finestra (quindi se il fiocco esce dallo schermo) io creo un altro fiocco di neve che parte dalla cima delle finestra  
  */
  public void disegna() {
    
    for(int i = 0; i < xPosition.length; i++) {
      
      //creazione e colorazione cerchio
      fill(255,255,255);
      stroke(255,255,255);
      circle(xPosition[i], yPosition[i], flakeSize[i]);
      //-------------------------------------
      
      //primo controllo è aggiornamento coordinata x
      if(direction[i]==0) {
        xPosition[i] += spostamento[i];
      } else {
        xPosition[i] -= spostamento[i];
      }
      //-------------------------------------
      
      //aggiornamento coordinata y
      yPosition[i] += flakeSize[i]+spostamento[i]; 
      //-------------------------------------
      
      //ultimo controllo per eliminazione e creazione di un nuovo fiocco      
      if(xPosition[i] > width || yPosition[i] > height) {
        xPosition[i] = random(0, width);
        yPosition[i] = 0;
      }
      //-------------------------------------
    }
  }
}
