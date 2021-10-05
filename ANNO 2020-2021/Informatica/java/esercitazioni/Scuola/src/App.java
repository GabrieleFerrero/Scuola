/*
Una scuola è composta da N classi. Per ogni classe, il numero di studenti è
generato in modo casuale (tra 15 e 30). Calcolare quanti 
frequentano la scuola e in media quanti studenti ci sono per classe, il numero
minimo e il numero massimo.
*/

public class App {

    CLInput in;
    Scuola scuola;

    App(){
        in = new CLInput();
        scuola = new Scuola();
    }

    public static void main(String[] args) throws Exception {
        App app = new App();

        app.scuola.setN(app.in.readInt("Inserire il numero di classi della scuola: "));
        app.scuola.setAlunniPerClasse();
        System.out.println("Il numero totale di alunni è: "+ app.scuola.getNumeroTotaleAlunni());
        System.out.println("Il numero medio di alunni per classe è: "+ app.scuola.getMediaNumeroAlunni());
        System.out.println("Il numero massimo di alunni per classe è: "+ app.scuola.getMaxNumeroAlunniPerClasse());
        System.out.println("Il numero minore di alunni per classe è: "+ app.scuola.getMinNumeroAlunniPerClasse());
        
    }
}
