public class Data {
    private int giorno;
    private int mese;
    private int anno;

    Data(int giorno, int mese, int anno)throws Exception{

        this.setMese(mese);
        this.setGiorno(mese, giorno);
        this.setAnno(anno);
    }

    public void setMese(int mese)throws Exception{
        if(mese > 12 || mese < 1){
            throw new Exception("mese non valido");
        }

        this.mese = mese;
    }
    public int getMese(){
        return this.mese;
    }

    public void setAnno(int anno) throws Exception {
        if(anno > 2020){
            throw new Exception("anno non valido!");
        }
        this.anno = anno;
    }
    public int getAnno(){
        return this.anno;
    }
    public void setGiorno(int mese, int giorno) throws Exception {
        switch (mese){
            case 2:
                if(giorno > 29){
                    throw new Exception("mese non valido!");
                }
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                if(giorno > 30){
                    throw new Exception("mese non valido!");
                }
                break;
            default:
                if(giorno > 31){
                    throw new Exception("mese non valido!");
                }
                break;
        }

        this.giorno = giorno;
    }
    public int getGiorno(){
        return this.giorno;
    }

}
