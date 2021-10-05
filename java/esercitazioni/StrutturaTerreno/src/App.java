/*
Scrivere una programma che legge da tastiera un intero e stampa un messaggio a 
video secondo la seguente tabella:

Valore Messaggio
v &gt;= 700 Montagna
700 &gt; v &gt;= 300 Collina
300 &gt; v &gt;= 0 Pianura
*/

public class App {

    CLInput in;
    Terreno terreno;

    App(){
        in = new CLInput();
        terreno = new Terreno();
    }
    public static void main(String[] args) throws Exception {
        App app = new App();
        
        app.terreno.setAltezza(app.in.readInt("Inserire un'altezza: "));
        try{
            System.out.println("La conformazione corrispondente è: "+ app.terreno.calcolatoreFormazioneTerreno());
        }catch(Exception e){
            System.out.println("Errore nell'inserimento dell'altezza");
        }
        
    }
}
