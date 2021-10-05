public class ListaNumeri {
    private  int quanti = 0;
    private int[] lista_numeri;

    ListaNumeri(int dim_array) throws Exception{
        if(dim_array<=0){
            throw new Exception("Lunghezza array inserita non corretta");
        }else{
            this.lista_numeri = new int[dim_array];
        }
    }

    public int trova(int numero_da_trovare){
        int pos=-1;
        for(int i=0; i<this.quanti; i++){
            if(this.lista_numeri[i]==numero_da_trovare){
                pos=i;
                i=this.quanti;
            }
        }
        return pos;
    }

    public boolean ePalindromo(){
        boolean ris = true;

        for(int i=0; i<this.quanti/2; i++){
            if(this.lista_numeri[i]!=this.lista_numeri[this.quanti-1-i]){
                ris = false;
            }
        }
        return ris;
    }

    public int[] intersezioneVuota(ListaNumeri other_lista){
        int[] elementi_comuni = new int[this.quanti];
        int pos=0;
        int q=0;

        for(int i=0; i<this.quanti; i++){
            pos = other_lista.trova(lista_numeri[i]);
            if(pos!=1){
                elementi_comuni[q++]=this.lista_numeri[i];
            }
        }
        return elementi_comuni;
    }

    public void inserisciElemento(int numero){
        if(numero<=0 || numero>0){
            this.lista_numeri[quanti++]=numero;
        }
    }
}
