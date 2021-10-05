public class CatenaDiLuci{
  
  private Luce[] catena_luci;
  private static final int LARGHEZZA_FINESTRA = 1000;
  private static final int ALTEZZA_FINESTRA = 600;  
  private static final int N_LUCI = 100;
  private color BACKGROUND = color(37,40,80);
  
  public CatenaDiLuci(){
    float x;
    float y;
    float dim;
    boolean stato;
    
    catena_luci = new Luce[N_LUCI];
    
    for(int i=0; i<N_LUCI; i++){
      x=random(0,LARGHEZZA_FINESTRA);
      y=random(0,ALTEZZA_FINESTRA);
      dim=random(1.5,6.5);
      stato=parseBoolean(round(random(0,1))); 
      catena_luci[i] = new Luce(x,y,dim,stato);
    }
  }
  
  public void draw(){
    background(BACKGROUND);
    for(int i=0; i<N_LUCI; i++){
      catena_luci[i].draw();
    }
  }
  
  public void premuto(float x, float y){
    for(int i=0; i<N_LUCI; i++){
      catena_luci[i].premuto(x,y);
    }
  }
}
