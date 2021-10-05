public class Libro {

    private int quante;
    private int numPagine;
    private Stampabile[] pagine;  //in questo caso io non istanzio nulla solo creo lo spazio per essere istaziate

    public Libro(int numPagine){
        pagine = new Stampabile[numPagine];
        this.numPagine=numPagine;
        this.quante=0;
    }

    public void aggiungiPagina(Stampabile s)throws Exception{
        if(quante>=numPagine){
            throw new Exception("Numero pagine massimo raggiunto");
        }
        else {
            pagine[quante+=1]=s;
        }
    }

    public void rimuoviPagina(int quale){
        for(int i=quale; i<quante-1; i++){
            pagine[i]=pagine[i+1];
        }
        quante--;
    }

    public String toString(){
        String stringa="";  //istanzio una stringa vuota
        for(int i=0; i<quante; i++){
            stringa += "pagina"+(i)+": "+pagine[i].mostra();
        }
        return stringa;
    }


}
