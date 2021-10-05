public class Triangolo {
    private int a;
    private int b;
    private int c;

    Triangolo(int a, int b, int c) throws Exception {
        if(a > b+c || b > c+a || c > a+b){
            throw new Exception("Non è un triangolo!");
        }
        this.a = a;
        this.b = b;
        this.c = c;
    }
    public void eEquilatero() {
        if (a == b && b == c) {
            System.out.println("Il triangolo è equilatero");
        } else {
            System.out.println("Il triangolo NON è equilatero");
        }
    }
    public void eIsoscele() {
        if (a == b || b == c || a == c) {
            System.out.println("Il triangolo è isoscele");
        } else {
            System.out.println("Il triangolo NON è isoscele");
        }
    }
    public int perimetro(){
        return a+b+c;
    }
    public int area(){
        int area = 5;
        return area;
    }

    }
