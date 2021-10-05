/*Fare un programma che letto un numero non negativo N e un carattere C, stampi a
video N volte C Per esempio se N=4 e C= 'A' a schermo compare AAAA*/
public class Principale {

    private CLInput cli;

    Principale(){
        cli = new CLInput();

    }
    public static void main(String[] args){
        Principale p;
        p = new Principale();
        p.crea_triangolo();

    }
    public int numero(){
        return cli.readInt("Inserire la misura del lato: ");
    }
    public void crea_triangolo(){
        try{
            int a = numero();
            int b = numero();
            int c = numero();
            Triangolo t = new Triangolo(a, b, c);
            System.out.println("Ho creato il triangolo!");

        } catch (Exception e) {
            System.out.println("Non è un triangolo!");
            crea_triangolo();
        }
    }



}
