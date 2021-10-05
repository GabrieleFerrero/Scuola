public class Principale {

    public static void main(String[] args){
        ContoCorrente cc;
        CLInput cli = new CLInput();
        Float x = cli.readFloat("Inserisci una stringa: ");
        try{
            cc = new ContoCorrente(100);
            cc.stampa();
            cc.deposita(cli.readFloat("Inserisci una stringa: "));
            cc.stampa();
        }
        catch (Exception e){
            System.out.println("Il saldo deve essere positivo!");
        }
    }
}
