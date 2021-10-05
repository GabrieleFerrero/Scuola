public class App {

    Massimo max;
    CLInput numero;

    App(){
        numero = new CLInput();
        max = new Massimo();
        
    }
    public static void main(String[] args) throws Exception {
        App principale = new App();
        int scelta=0;
        boolean condizione=true;
        while(condizione){
            System.out.println("Menù\n\n+ digitare 1 per inserire un numero\n+ digitare 2 per vedere il numero maggiore mai inserito\n+ digitare 3 per terminare il programma\n");
            scelta=principale.numero.readInt("inserisci la scelta: ");
            switch(scelta){
                case 1:
                    principale.max.setNumero(principale.numero.readInt("inserisci il numero: "));
                    break;
                case 2:
                    System.out.println(principale.max.getNumeroMax());
                    break;
                case 3:
                    condizione=false;
                    System.out.println("exit...");
                    break;
                default:
                    System.out.println(("opzione inserita non corretta!!!\n"));
                    break;
            }


        }
    }
}
