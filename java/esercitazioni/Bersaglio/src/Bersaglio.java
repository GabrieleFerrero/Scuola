import processing.core.PApplet;

public class Bersaglio {
    private float punteggio;
    private float X;
    private float Y;
    private float raggio;
    PApplet applet;

    public Bersaglio(PApplet applet, float punteggio, float x, float y, float raggio) throws Exception {
        this.punteggio = punteggio;
        X = x;
        Y = y;
        if(raggio < 0){
            throw new Exception("Il raggio deve essere positivo");
        }
        this.raggio = raggio;
        this.applet=applet;
    }

    public Bersaglio (PApplet applet, float punteggio, float raggio) throws Exception {
        this(applet, punteggio, 0, 0, raggio);
    }

    public void setX(float x) {
        X = x;
    }

    public void setY(float y) {
        Y = y;
    }

    public float getPunteggio() {
        return punteggio;
    }

    public String getPosizione() {
        return " X: "+ this.X + ", Y: "+this.Y;
    }
    public float getRaggio() {
        return raggio;
    }
    public String toString(){
        return "Punteggio: "+this.punteggio+" raggio: "+this.raggio + getPosizione();
    }
    public boolean eColpito(float mx, float my){
        float dX = this.X - mx;
        float dY = this.Y - my;
        boolean ris = true;
        if(dX*dX + dY*dY > raggio*raggio){
            ris = false;
        }
        return ris;
    }

    public void draw(){
        applet.color(255,0,0);
        applet.circle(X,Y,raggio);
    }
}
