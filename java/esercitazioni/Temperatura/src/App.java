/**
fare un programma che data in input una temperatura
in gradi celsius da in output la temperatura in gradi farad
*/

public class App{
    private CLInput gradi;
    private Temperatura conversione;

    App(){
        this.gradi = new CLInput();
        this.conversione = new Temperatura();
    }
    public static void main(String[] args){
        App programma = new App();
        try{
            programma.conversione.setGradiC(programma.gradi.readFloat("inserisci gradi: "));
        }catch(Exception e){
            System.out.println("inserisci una temperatura superiore a -273.15");
        }

        System.out.println(programma.conversione.getGradiF());

        
    }
}