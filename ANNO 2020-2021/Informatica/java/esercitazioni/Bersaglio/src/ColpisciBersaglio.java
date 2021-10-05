/*
* ColpisciBersaglio che aggrega al più 100 oggetti di tipo Bersaglio (inizialmente vuoto),
 che assumiamo essere disgiunti, e una proprietà punteggioTotale
 con
 - il costruttore senza parametri
 - un metodo aggiungiBersaglio(Bersaglio b) e un metodo spara(float mx, float my) che
 controlla se si è colpito un bersaglio e, in tal caso, aggiorna il punteggio totale
 - un getter per punteggioTotale
 - aggiungere un meccanismo per contare quanti ColpisciBersaglio sono stati istanziati*/

import processing.core.PApplet;

public class ColpisciBersaglio {
    private Bersaglio[] bersaglios;
    private int punteggioTotale;
    public static int nColpisciBersaglio;
    private int conti;
    public static final int MAX = 100;
    PApplet applet;

    public ColpisciBersaglio(PApplet applet) {
        this.nColpisciBersaglio++;
        bersaglios = new Bersaglio[MAX];
        conti = 0;
        this.applet=applet;
    }

    public int getPunteggioTotale() {
        return punteggioTotale;
    }
    public void aggiungiBersaglio(Bersaglio b){
        bersaglios[conti++] = b;
    }
    public void spara(float mx, float my){
        for(int a=0; a<conti; a++) {
            if (bersaglios[a].eColpito(mx, my)) {
                punteggioTotale += bersaglios[a].getPunteggio();
            }
        }
    }

    public void draw(){
        for(int i=0; i<conti; i++){
            bersaglios[i].draw();
        }
    }
}
