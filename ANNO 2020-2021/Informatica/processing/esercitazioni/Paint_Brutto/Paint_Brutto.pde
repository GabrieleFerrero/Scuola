private static final int WIDTH = 600;
private static final int HEIGHT = 600;
private Matrice matrice;


public void setup(){
  size(600,600);
  background(255,255,255);
  try{
  matrice = new Matrice(600,600,30,30);
  }catch(Exception e){
    System.out.println("errore nell'inserimento dei dati");
  }
  
}

public void draw(){
  matrice.draw();
}

public void mousePressed(){
  matrice.premuto(mouseX, mouseY);
}
