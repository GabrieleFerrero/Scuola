public class Massimo {
    private int max_numero;
    private boolean primo_numero;

    Massimo(){   //dentro il costruttore in questo caso io inizializzo la variabile buleana
        this.primo_numero=true;
    }

    private void Verifica(int numero_appena_inserito){
        if(numero_appena_inserito>this.max_numero){
            this.max_numero=numero_appena_inserito;
        }
    }

    public void setNumero(int input){   //serve per settare il numero
        if(this.primo_numero==true){
            this.max_numero=input;
            this.primo_numero=false;
        }else{
            Verifica(input);
        }
    }

    public String getNumeroMax(){   //serve per ottenere il numero maggiore
        return ("Il numero max è "+ this.max_numero);
    }

}
