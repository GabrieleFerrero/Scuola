import javax.accessibility.AccessibleText;

public class Terreno{

    private int altezza;
    private static final int ALTEZZA_MONTAGNA = 700;
    private static final int ALTEZZA_COLLINA = 300;
    private static final int ALTEZZA_PIANURA = 0;

    public Terreno(){
        altezza=0;
    }

    public String calcolatoreFormazioneTerreno(){
        String formazione;
        if(altezza>=ALTEZZA_MONTAGNA){
            formazione="Montagna";
        }else if(altezza>=ALTEZZA_COLLINA && altezza<ALTEZZA_MONTAGNA){
            formazione="Collina";
        }else if(altezza>=ALTEZZA_PIANURA && altezza<ALTEZZA_COLLINA){
            formazione="Pianura";
        }else{
            formazione="error";
        }
        return formazione;
    }

    public void setAltezza(int altezza)throws Exception{
        if(altezza<0){
            throw new Exception("Altezza inserita non valida");
        }else{
            this.altezza=altezza;
        }
    }

}