public class ContoCorrente {
    private float saldo;
    ContoCorrente(float saldo) throws Exception {
        if (saldo < 0) {
            throw new Exception("saldo negativo");
        }
        this.saldo = saldo;
    }

    public void deposita(float input) throws Exception {
        if(input < 0){
            throw new Exception("Il valore deve essere positivo!");
        }
        saldo = saldo + input;
    }
    public void stampa(){
        System.out.println("Il saldo è "+saldo);
    }
    public void preleva(float input) throws Exception {
        if(input < 0){
            throw new Exception("Il valore deve essere positivo!");
        }
        saldo = saldo - input;
    }
}
