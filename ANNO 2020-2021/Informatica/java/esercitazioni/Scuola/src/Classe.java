public class Classe {

    private int n_studenti = 0;

    public Classe(int n_studenti){
        setNumeroStudenti(n_studenti);
    }

    public void setNumeroStudenti(int n_studenti){
        this.n_studenti=n_studenti;
    }

    public int getNumeroStudenti(){
        return this.n_studenti;
    }
    
}
