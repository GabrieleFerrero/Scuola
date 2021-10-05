public class DisegnaCampo{

  //creazione e inizializzazione variabili
  private int distanza_da_lato_finestra_a_bordo_campo = 20;
  private int grandezza_lato_cella = distanza_da_lato_finestra_a_bordo_campo;
  
  private int numero_celle_per_lato = (600-(distanza_da_lato_finestra_a_bordo_campo*2))/grandezza_lato_cella;
  private int numero_celle_per_bordo = 2;  // ce sia bordo sinistra e destro
  
  private color colore_di_sfondo = color(153,203,255);
  private color colore_quadrato_1 = color(57,255,20);
  private color colore_quadrato_2 = color(0,187,45);
  private color colore_cibo = color(0,0,255);
  private color colore_verme = color(255,0,0);
  private color colore_ostacolo = color(0,0,0);
  
  private int [][] matrice = new int[numero_celle_per_lato+numero_celle_per_bordo][numero_celle_per_lato+numero_celle_per_bordo];
  //---------------------------------------
  
  /*
  creazione costruttore: ma non lo uso per fare nulla
  */
  public DisegnaCampo(){
  }
  //---------------------------------------
  
 /*
 creazione funzione inizializzazioneCampo():
 1. inizializzare l'intera matrice con valore = 1 se corrispondono ai bordi del campo è = 0 se corrispondono al campo
 2. ritorno la matrice modificata
 */
  public int[][] inizializzazioneCampo(){
    for(int x=0; x<numero_celle_per_lato+numero_celle_per_bordo; x++){
      for(int y=0; y<numero_celle_per_lato+numero_celle_per_bordo; y++){
        if((x==0) || (x==numero_celle_per_lato+numero_celle_per_bordo-1) || (y==0) || (y==numero_celle_per_lato+numero_celle_per_bordo-1)){
          matrice[x][y] = 1;   // condizione per capire se si tratta del bordo
        }else{
          matrice[x][y] = 0;
         }
      }
    }
    return this.matrice;
  }
  //---------------------------------------
  
  /*
  creazione funzione disegna:
  1. accettando una matrice come parametro, la funzione va a scorrerre l'intera matrice e fa corrispondere le celle della matrice a dei
  quadrati colorati in base al valore contenuto dentro la cella della matrice.
  
  TABELLA DEI VALORI --> COLORI  :
  0 --> verde chiato/scuro = campo
  1 --> azzurro = bordo
  2 --> blu = cibo
  3 --> rosso = verme
  4 --> nero = ostacolo
  */
  public void disegna(int [][] matrice){
    this.matrice=matrice;
    boolean variabile_switch = true;
    
    //ciclo for per scorrere la matrice
    for(int x=0; x<numero_celle_per_lato+numero_celle_per_bordo; x++){
      for(int y=0; y<numero_celle_per_lato+numero_celle_per_bordo; y++){
        
        //condizioni per associare il giusto colore al quadrato
        if(this.matrice[x][y]==0){
          if(variabile_switch==true){
          fill(colore_quadrato_1);
          stroke(colore_quadrato_1);
          }else{
            fill(colore_quadrato_2);
            stroke(colore_quadrato_2);
          }
        }else if(this.matrice[x][y]==1){
          fill(colore_di_sfondo);
          stroke(colore_di_sfondo);
        }else if(this.matrice[x][y]==2){
          fill(colore_cibo);
          stroke(colore_cibo);
        }else if(this.matrice[x][y]==3){
          fill(colore_verme);
          stroke(colore_verme);
        }else if(this.matrice[x][y]==4){
          fill(colore_ostacolo);
          stroke(colore_ostacolo);
        }
        
        //disegno il guadrato 
        rect(x*grandezza_lato_cella, y*grandezza_lato_cella, grandezza_lato_cella, grandezza_lato_cella);
        
        //faccio questi controlli in modo da alternare sempre il due colori verdi del prato anche quando non bisogna colorarlo di verde ma di nero, rosso o blu
        if((x==0) || (x==numero_celle_per_lato+numero_celle_per_bordo-1) || (y==0) || (y==numero_celle_per_lato+numero_celle_per_bordo-1)){}
        else{
          variabile_switch=!variabile_switch;
        }
        
      }
      
      /*
      alla fine di ogni riga bisogna poi ricominciare la riga succesiva con un verde opposta a quella precedente e quindi inverto il valore
      della variabile variabile_switch
      */
      variabile_switch=!variabile_switch;
    }
  }
  //---------------------------------------
  
  /*
  creazione funzione per ottenere il numero di celle per lato della finestra di gioco
  */
  public int getNumeroCellePerLato(){
    return this.numero_celle_per_lato+numero_celle_per_lato+numero_celle_per_bordo;
  }
  //---------------------------------------
  
  /*
  creazione funzione per ottenere cibo:
  1. data la matrice e due coordinate ottenute randomicamente si guarda se a quelle coordinate il valore contenuto nella matrice è = 0 
  se sì, si metterà il valore 2 a quelle coordinate se no si cerca fino a quando le due coordinate daranno un valore = 0
  */
  public int [][] getCibo(int [][] matrice){
    this.matrice = matrice;
    
    //generazione randomica delle coordinate
    int coord_x_cibo = (int)random(1,numero_celle_per_lato-1);
    int coord_y_cibo = (int)random(1,numero_celle_per_lato-1);
    
    //condizioni per vedere se le celle sono libere
    if(this.matrice[coord_x_cibo][coord_y_cibo]==0){
      this.matrice[coord_x_cibo][coord_y_cibo] = 2;
    }else{
      int c=0;
      while(c==0){
        coord_x_cibo = (int)random(1,numero_celle_per_lato-1);
        coord_y_cibo = (int)random(1,numero_celle_per_lato-1);
        
        if(this.matrice[coord_x_cibo][coord_y_cibo]==0){
          this.matrice[coord_x_cibo][coord_y_cibo] = 2;
          c=1;
        }
      }
     } 
    //ritorno della matrice modificata
    return this.matrice;
  }
  //---------------------------------------
  
  /*
  creazione della funzione per ottenere gli ostacoli:
  1. ottengo un numero randomico, ovvero il numero di ostacoli che poi piazzerò
  2. data la matrice e due coordinate ottenute randomicamente si guarda se a quelle coordinate il valore contenuto nella matrice è = 0 
  se sì, si metterà il valore 4 a quelle coordinate se no si cerca fino a quando le due coordinate daranno un valore = 0
  */
  public int [][] getOstacoli(int [][] matrice){
    this.matrice = matrice;
    
    //ottengo il numero di ostacoli che metterò
    int n_ostacoli = (int)random(1,25);
    
    //circolo for per la creazione di N ostacoli
    for(int i=0; i<n_ostacoli; i++){
      
      //ottengo le coordinate per il posizionamento dell'ostacolo
      int coord_x_ostacoli = (int)random(1,numero_celle_per_lato-1);
      int coord_y_ostacoli = (int)random(1,numero_celle_per_lato-1);
      
      //controlli per vedere se a quelle coordinate la cella è libera
      if(this.matrice[coord_x_ostacoli][coord_y_ostacoli]==0){
        this.matrice[coord_x_ostacoli][coord_y_ostacoli] = 4;
      }else{
        int c=0;
        while(c==0){
          coord_x_ostacoli = (int)random(1,numero_celle_per_lato-1);
          coord_y_ostacoli = (int)random(1,numero_celle_per_lato-1);
          
          if(this.matrice[coord_x_ostacoli][coord_y_ostacoli]==0){
            this.matrice[coord_x_ostacoli][coord_y_ostacoli] = 4;
            c=1;
          }
        }
       }
      
    }
    //ritorno la matrice modificata
    return this.matrice;
  }
  //---------------------------------------
  
}
