public class Giocatore {
    private String nome;
    private int eta;
    private double punteggio;

    public Giocatore(String nome, int eta, double punteggio)throws Exception{
        this.nome=nome;
        this.eta=eta;
        try{
            this.setEta(eta);
        }catch(Exception e){
            throw new Exception("Età inserita non valida");
        }
        
    }

    public Giocatore(String nome, int eta){
        this(nome, eta, 0);
    }

    public String getNome(){
        return this.nome;
    }

    public int getEta(){
        return this.eta;
    }

    public double getPunteggio(){
        return this.punteggio;
    }
    public void setNome(String nome){
        this.nome=nome;
    }

    public void setEta(int eta)throws Exception{
        if(eta > 0){
            this.eta=eta;
        }else{
            throw new Exception("Età inserita non valida");
        }
    }

    public void setPunteggio(double punteggio){
        this.punteggio=punteggio;
    }

    public String toString(){
        return this.nome + " " + this.eta + " " + this.punteggio;
    }


}
