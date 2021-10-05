import java.util.Random;

public class Scuola {

    private Random rnd = new Random();
    private Classe[] scuola;
    private static final int NUM_STUDENTI_MAX = 30;
    private static final int NUM_STUDENTI_MIN = 15;
    private int N = 0;

    public Scuola(){}

    public void setN(int N){
        this.N = N;
        scuola = new Classe[this.N];
    }

    public void setAlunniPerClasse(){
        for(int i=0; i<N; i++){
            scuola[i] = new Classe(rnd.nextInt(NUM_STUDENTI_MAX-NUM_STUDENTI_MIN+1)+NUM_STUDENTI_MIN);
        }
    }

    public int getMediaNumeroAlunni(){
        int media = getNumeroTotaleAlunni()/N;
        return media;
    }

    public int getNumeroTotaleAlunni(){
        int somma=0;
        for(int i=0; i<N; i++){
            somma+=scuola[i].getNumeroStudenti();
        }
        return somma;
    }

    public int getMinNumeroAlunniPerClasse(){
        int min=scuola[0].getNumeroStudenti();
        for(int i=0; i<N; i++){
            if(scuola[i].getNumeroStudenti()<min){
                min = scuola[i].getNumeroStudenti();
            }
        }
        return min;
    }

    public int getMaxNumeroAlunniPerClasse(){
        int max=scuola[0].getNumeroStudenti();
        for(int i=0; i<N; i++){
            if(scuola[i].getNumeroStudenti()>max){
                max = scuola[i].getNumeroStudenti();
            }
        }
        return max;
    }
    
}
