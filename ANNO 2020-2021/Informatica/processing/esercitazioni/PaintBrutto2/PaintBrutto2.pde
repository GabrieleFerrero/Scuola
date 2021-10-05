Griglia g;
public void setup() {
  size(400, 400);
  g = new Griglia(width, height, 30, 30);
}

public void draw() {
  background(#eeeeee);
  g.disegna();
}

public void mousePressed() {
  g.clickMouse(mouseX, mouseY);
}
