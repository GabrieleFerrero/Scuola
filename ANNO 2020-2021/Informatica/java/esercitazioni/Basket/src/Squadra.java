import jdk.nashorn.internal.runtime.ECMAException;

public class Squadra {
    private static final int NUM_MAX_GIOCATORI = 100;
    private String nome;
    private Giocatore[] squadra;
    private int quanti;

    public Squadra(String nome){
        this.nome=nome;
        this.quanti=0;
        squadra=new Giocatore[NUM_MAX_GIOCATORI];
    }

    public void addGiocatore(Giocatore giocatore)throws Exception{
        if(quanti>=squadra.length){
            throw new Exception("Non si possono più aggiungere giocatori");
        }else{
            this.squadra[quanti]=giocatore;
            quanti++;
        }
    }

    public void setPunteggio(String nome, double punteggio)throws Exception{
        int pos = ricercaPerNome(nome);
        if(pos==-1){
            throw new Exception("Giocatore non esistente");
        }else{
            squadra[pos].setPunteggio(punteggio);
        }
    }

    public int ricercaPerNome(String nome){
        boolean condizione=true;
        int pos=-1;
        for(int i=0; i<quanti && condizione==true; i++){
            if(this.squadra[i].getNome().equals(nome)){  // io metto equals e non == perché se no mi riferirei ai puntatori di inizio delle stringhe e quindi ai riferimenti in memoria
                pos=i;
                condizione=false;
            }
        }
        return pos;
    }

    public double calcoloPunteggioMedio(){
        if(quanti<=0){
            throw new Exception("Numero di giocatori insuficcente")
        }else{
            double somma=0;
            for(int i=0; i<quanti; i++){
                somma+=this.squadra[i].getPunteggio();
                return somma/((double)this.quanti);
            }
        } 
    }

    public void passatoAnno(){
        for(int i=0; i<quanti; i++){
            try{
                this.squadra[i].setEta(this.squadra[i].getEta()+1);
            }catch(Exception e){}
        }
    }

    public String toString(){
        //Le stringhe in java sono oggeti immutabili e quidi per modificarne una bisogna crearne un altra
        String dati_squadra="";
        for(int i=0; i<quanti; i++){
            dati_squadra+=this.squadra[i].toString()+"  /  ";
        }
        return dati_squadra;
    }
}

