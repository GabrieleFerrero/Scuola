import java.lang.System.Logger;

/*Fare un programma che letto un numero non negativo N e un carattere C, stampi a
video N volte C Per esempio se N=4 e C='A'; a schermo compare 'AAA'*/


public class App {
    public static void main(String[] args) throws Exception {
        CLInput read = new CLInput();
        int N=0;
        char C='a';
        N=read.readInt("inserisci un numero: ");
        C=read.readChar("inserisci un carattere: ");
        for(int i=0; i<N; i++){
            System.out.print(C);
        }
        
    }
}
