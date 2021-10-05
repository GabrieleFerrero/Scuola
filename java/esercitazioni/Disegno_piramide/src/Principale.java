/*Fare un programma che letto un numero non negativo N e un carattere C, stampi a
video N volte C Per esempio se N=4 e C= 'A' a schermo compare AAAA*/
public class Principale {
    private int n;
    private char c;
    private CLInput cli;

    Principale(){
        cli = new CLInput();
        inizializza_n_c();
    }
    public static void main(String[] args){
        Principale p;
        p = new Principale();
        p.svolgi();

    }
    public void inizializza_n_c(){
        n = cli.readInt("Inserire un numero intero: ");
        while(n < 0){
            System.out.println("Il numero deve essere positivo: ");
            n = cli.readInt("Inserire un numero intero: ");
        }
        c = cli.readChar("Inserire un carattere: ");
    }

    public void svolgi(){
        for(int i = 0; i < n; i++){
            System.out.print(c);
        }
    }

}
