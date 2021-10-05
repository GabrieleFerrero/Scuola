public class Albero_di_natale{
  //creazione variabili
  private int coordinata_x;
  private int coordinata_y;
  private int base_tronco = 10;
  private int altezza_tronco = 20;
  private int base_chioma = 40;
  private int altezza_chioma = 30;
  private int differenza_tra_posizione_chiome = 10;
  private int lunghezza;
  private int altezza;
  //-------------------------------------
  
  /*
  creazione del costruttore:
  
  1. associa gli opportuni valori a tutte le variabili
  2. controlla se le dimensioni inserite sono accentabili (vuol dire che il disegno è più piccolo della dimensione della finestra)
  3. richiama la funzione disegna la quale disegna l'albero e la scritta
  
  */
  public Albero_di_natale(int dimensione_albero)throws Exception{
    
    //associazione valori
    this.base_tronco*=dimensione_albero;
    this.altezza_tronco*=dimensione_albero;
    this.base_chioma*=dimensione_albero;
    this.altezza_chioma*=dimensione_albero;
    this.differenza_tra_posizione_chiome*=dimensione_albero;
    this.lunghezza = width;
    this.altezza = height;
    //-------------------------------------
    
    //controllo dati
    if((((this.altezza_chioma*3)-(this.differenza_tra_posizione_chiome*2)+this.altezza_tronco)>this.altezza)||(this.base_chioma>this.lunghezza)){
      throw new Exception("dimensione dell'albero troppo grande");
    }
    //-------------------------------------
    
    //richiamo la funzione disegna
    disegna();
    //-------------------------------------
  }
  
  /*
  creazione funzione disegna:
  1. creazione scritta
  2. calcolo le coordinate per l'inizio del disegno
  3. richiamo la funzione disegnaTronco (per disegnare il tronco)
  4. calcolo le nuove coordinate
  5. infine richiamo la funzione disegnaChioma (disegna le foglie dell'albero) per 3 volte
  */
  private void disegna(){
    
    //creazione scritta
    fill(255,0,0);
    textSize(18);
    text("TANTI AUGURI\nDI BUON NATALE!!", 330, 30);
    //-------------------------------------
    
    //calcolo coordinate
    this.coordinata_x=(this.lunghezza/2)-(this.base_tronco/2);
    this.coordinata_y=500-this.altezza_tronco;
    //-------------------------------------
    
    //richiamo funzione disegnaTronco
    disegnaTronco();
    //-------------------------------------
    
    //calcolo delle nuove coordinate
    this.coordinata_x = this.coordinata_x+(this.base_tronco/2)-(this.base_chioma/2);
    //-------------------------------------
    
    //richiamo 3 volte la funzione disegnaChioma
    disegnaChioma();
    disegnaChioma();
    disegnaChioma();
    //-------------------------------------
  }
  
  /*
  creazione funzione disegnaTronco:
  1. setto il colore del bordo e dello sfondo del rettangolo
  2. disegno il rettangolo
  */
  private void disegnaTronco(){
    
    //setto il colore
    fill(65,43,21);
    stroke(65,43,21);
    //-------------------------------------
    
    //disegno il rettangolo
    rect(this.coordinata_x, this.coordinata_y, this.base_tronco, this.altezza_tronco);
    //-------------------------------------
  }
  
  /*
  creazione funzione disegnaChioma:
  1. setto il colore del bordo e dello sfondo del triangolo
  2. disegno il triangolo
  */
  private void disegnaChioma(){
    
    //setto il colore
    fill(28,72,33);
    stroke(28,72,33);
    //-------------------------------------
    
    //disegno triangolo
    triangle(this.coordinata_x, this.coordinata_y, this.coordinata_x+this.base_chioma, this.coordinata_y, this.coordinata_x+(this.base_chioma/2), this.coordinata_y-this.altezza_chioma);
    this.coordinata_y = this.coordinata_y-(this.altezza_chioma-this.differenza_tra_posizione_chiome);
    //-------------------------------------
  }
}
