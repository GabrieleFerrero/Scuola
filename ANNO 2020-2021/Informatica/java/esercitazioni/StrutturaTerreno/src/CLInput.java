import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

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
        char carattere = 'a';
        String stringa = null;
        stringa = readString(prompt);
        int n = stringa.length();
        if(n == 1){
            carattere = stringa.charAt(0);
            System.out.print(carattere);
        }
        else{
            System.out.println("Inserisci un solo carattere!");
            carattere = readChar(prompt);
        }

        return carattere;
    }

    public boolean readBool(String prompt){
        boolean bool = true;
        String stringa = null;
        stringa = readString(prompt);
        if(stringa=="true" || stringa=="True" || stringa=="vero" || stringa=="Vero" || stringa=="T" || stringa=="t" || stringa=="yes" || stringa=="Yes" || stringa=="1"){
            bool=true;
        }else if(stringa=="false" || stringa=="False" || stringa=="falso" || stringa=="Falso" || stringa=="F" || stringa=="f" || stringa=="no" || stringa=="No" || stringa=="0"){
            bool=false;
        }else{
            bool=readBool(prompt);
        }
        return bool;
    }

}

