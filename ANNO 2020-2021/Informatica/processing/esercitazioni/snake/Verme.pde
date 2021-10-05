public class Verme{
  
  //creazione e inizializzazione variabili
  DisegnaCampo campo = new DisegnaCampo();
  int [][] matrice = new int [campo.getNumeroCellePerLato()][campo.getNumeroCellePerLato()];
  private int punteggio = 0;
  
  private int coord_x_verme = 3;
  private int coord_y_verme = 3;
  //---------------------------------------
  
  /*
  creazione del costruttore, ma non lo uso
  */
  public Verme(){
  }
  //---------------------------------------
  
  /*
  creazione della funzione per ottenere la matrice modificata con dentro contenuta la cella iniziale da cui partira il verme 
  */
  public int [][] getVerme(int [][] matrice){
    this.matrice = matrice;
    this.matrice[coord_x_verme][coord_y_verme] = 3;
    return this.matrice;
  }
  //---------------------------------------
  
  /*
  creazione funzione per permettere al verme di muoversi
  */
  public int [][] Direzione(String direzione, int [][] matrice)throws Exception{
    this.matrice = matrice;
    
    //setto il valore delle coordinate precedenti del verme a 0 in modo che poi non venga più ridisegnato
    this.matrice[coord_x_verme][coord_y_verme]=0;
    
    //poi in base alla direzione le oppurtune coordinate diminuiranno o aumenteranno
    switch(direzione){
      case "left":
      coord_x_verme -= 1;
      break;
      case "right":
      coord_x_verme += 1;
      break;
      case "up":
      coord_y_verme -= 1;
      break;
      case "down":
      coord_y_verme += 1;
      break;
    }
    
    //poi si fanno delle condizioni per vedere dentro la cella delle nuove coordinate che valore è presente e in base al valore vengono fatte determinate azioni
    if(this.matrice[coord_x_verme][coord_y_verme] == 1){  // controllo per vedere se il verme è uscito fuori dal campo
      this.matrice[coord_x_verme][coord_y_verme]=3;
      campo.disegna(this.matrice);
      throw new Exception("il verme è uscito dal campo");      
    }else if(this.matrice[coord_x_verme][coord_y_verme] == 2){  // controllo per vedere se ha mangiato del cibo
      this.matrice[coord_x_verme][coord_y_verme]=3;
      campo.disegna(this.matrice);
      punteggio++;
      this.matrice=campo.getCibo(this.matrice);
      campo.disegna(this.matrice);
    }else if(this.matrice[coord_x_verme][coord_y_verme] == 4){   // controllo per vedere se ha toccato un ostacolo
      this.matrice[coord_x_verme][coord_y_verme]=3;
      campo.disegna(this.matrice);
      throw new Exception("il verme ha toccato un ostacolo"); 
    }else{     // controllo per vedere se è solamente sul campo
    this.matrice[coord_x_verme][coord_y_verme]=3;
    campo.disegna(this.matrice);
    }
    //restituisco la matrice modificata
    return this.matrice;
  }
  //---------------------------------------
  
  /*
  creazione della funzione per il ritorno del punteggio
  */
  public int getPunteggio(){
    return this.punteggio;
  }
  //---------------------------------------
  
}

  
  
  
  
  
  
