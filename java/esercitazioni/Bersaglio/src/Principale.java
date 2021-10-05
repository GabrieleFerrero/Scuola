/*
creare un programma che crei dei bersagli e gestisca gli spari e i punteggi
*/

import processing.core.*;
import java.awt.*;

public class Principale extends PApplet {

    private  ColpisciBersaglio cb;

    public static void main(String args[]){
        PApplet.main("Principale");  //serve per creare la finestra di disegno
    }

    // PApplet ha stabilito che ci fossero le classi settings,setup e draw

    public void settings(){size(500,500);}

    public void setup(){
        this.cb=new ColpisciBersaglio((PApplet)this);  // qui noi abbaimo fatto un up-casting
        try{
            cb.aggiungiBersaglio(new Bersaglio((PApplet)this, 5, 100,100, 45));
            cb.aggiungiBersaglio(new Bersaglio((PApplet)this, 90, 50,50, 30));
        }catch(Exception e){
            e.printStackTrace();
        }

    }

    public void draw(){
        background(255,255,255);
        cb.draw();
    }

    @Override
    public void mousePressed() {
        System.out.println("bang");
        cb.spara(mouseX,mouseY);
        System.out.println(cb.getPunteggioTotale());
    }
}
