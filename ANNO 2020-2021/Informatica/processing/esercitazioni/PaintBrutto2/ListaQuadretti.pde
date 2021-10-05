class ListaQuadretti{
  
  private Quadretto[] quadretti;
  private Griglia griglia;
  private int quanti;
  
  public ListaQuadretti(Griglia griglia){
    this.griglia = griglia; //HO passato un oggetto griglia
    quanti = 0;
    quadretti = new Quadretto[griglia.getColonne()*griglia.getRighe()];
    
  }
  
  public void aggiungiQuadretto(Quadretto q){
    if(q==null)
      return;
    int pos = this.ricercaQuadretto(q);
    if(pos == -1){
      System.out.println("Aggiungi: "+q.toString());
      quadretti[quanti++] = q; //In questo caso prima utilizzo il suo valore e poi lo incremento
      //Se avessi fatto ++quanti avrebbe fatto l'opposto
    }
    else{
      this.rimuoviQuadretto(pos);
    }
  }
  public int ricercaQuadretto(Quadretto q){
    int a = 0;
    int pos = -1;
    while(a<quanti && pos == -1){
      if(quadretti[a].equals(q)){ 
        System.out.println("Rimosso: "+q.toString());
        //È meglio confontare le righe e le colonne per sapre se sono uguali rispetto ad ==, perché con l'= confronta il 
        //riferimento che non sempre è lo stesso anche se gli oggetti corrispondono {MEGLIO: quadretti[a].equals(q) DI: quadretti[i] == q }
        pos = a;
      }
      a++;
    }
    return pos;
  }
  public void rimuoviQuadretto(int pos){
    for(int a = pos; a < quanti-1; a++){ //Questo è un modo preferenziale, è più efficiente. Se io fossi partito dal fondo allora di dal secondo assegnamento in poi avrei perso quello prima
      quadretti[a] = quadretti[a+1];
    }
    quanti--;
  }
  
  public void disegna(){
    for(int i = 0; i < quanti; i++){
      g.disegnaQuadretto(quadretti[i]);
    }
  }
}
