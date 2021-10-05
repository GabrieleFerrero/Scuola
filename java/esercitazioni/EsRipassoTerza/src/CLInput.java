import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.text.CharacterIterator;

public class CLInput {
    private BufferedReader br;

    CLInput() {
        InputStreamReader isr = new InputStreamReader(System.in);
        this.br = new BufferedReader(isr);
    }
    public String readString(String prompt) {
        String ris = null;
        while (ris == null) {
            System.out.print(prompt);
            try {
                ris = br.readLine();
            } catch (IOException e) {
                System.out.print("Valore non valido!");
            }

        }
        return ris;
    }


    public float readFloat(String prompt){
        float valore = 0;
        try {
            valore = Float.parseFloat(readString(prompt));
        } catch (Exception e) {
            System.out.println("Il valore inserito non è corretto!");
            valore = readFloat(prompt);
        }
        return valore;
    }

    public int readInt(String prompt){
        int valore = 0;
        try {
            valore = Integer.parseInt(readString(prompt));
        } catch (Exception e) {
            System.out.println("Il valore inserito non è corretto!");
            valore = readInt(prompt);
        }
        return valore;
    }


    public char readChar(String prompt){
        String valore=null;
        char carattere;
        int lunghezza=0;

        while(lunghezza!=1){
            try{
            valore = br.readLine();
            }catch(Exception e){
                
            }
            if((lunghezza = valore.length())==1){
                carattere=valore.charAt(0);
            }else{
                System.out.println("inserisci un solo carattere!!!");
            }
        }
        return carattere;
    }

}
