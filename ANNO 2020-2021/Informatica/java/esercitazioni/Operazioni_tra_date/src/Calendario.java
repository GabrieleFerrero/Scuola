public class Calendario {


    public Calendario(){
        System.out.println("Inizializzazione avvenuta con successo");
    }

    public int numeroGiorniInUnAnno(int anno){  // funzione per capire il numero di giorni in un anno in caso sia bisestile (366) o no (365)
        int giorni = 0;
        if(numeroGiorniPerMese(2, anno)==28){
            giorni = 365;
        }else{
            giorni = 366;
        }
        return giorni;
    }

    public long differenzaDataData(int [] data_1, int [] data_2){    // funzione per calcolare la differenza tra due date
        long numero_giorni_data_1 = data_1[0];
        long numero_giorni_data_2 = data_2[0];

        /*
        vado a calcolare il numero di giorni composti da tutte e due le date e poi faccio la differenza
        */
        for(int i=1; i<=data_1[1]; i++){
            numero_giorni_data_1+=numeroGiorniPerMese(i, data_1[2]);
        }

        for(int i=0; i<data_1[2]; i++){
            numero_giorni_data_1+=numeroGiorniInUnAnno(i);
        }

        //calcolo giorni data 2
        for(int i=1; i<=data_2[1]; i++){
            numero_giorni_data_2+=numeroGiorniPerMese(i, data_2[2]);
        }

        for(int i=0; i<data_2[2]; i++){
            numero_giorni_data_2+=numeroGiorniInUnAnno(i);
        }

        return numero_giorni_data_2-numero_giorni_data_1;

    }

    public int[] sommaDataGiorno(int [] data, int giorni){   // funzione per il calcolo della somma tra una data ed un numero
        int [] data_sommata = new int [3];
        boolean uscita_while=false;

            /*
            l'intera funzione si basa su un ciclo while che permette di calcolare il numero di giorni finale
            e il numero di incrementi dati a mesi e anni
            */
            while(uscita_while==false){
                data[0]+=giorni;
                if(data[0]>numeroGiorniPerMese(data[1], data[2])){
                    giorni=data[0]-numeroGiorniPerMese(data[1], data[2]);
                    data[0]=0;
                    data[1]++;
                    if(data[1]>12){
                        data[1]=1;
                        data[2]++;
                    }
                }else{
                    uscita_while=true;
                }
            }

            data_sommata[0]=data[0];
            
            data_sommata[1]=data[1];

            data_sommata[2]=data[2];


        return data_sommata;
    }

    public int numeroGiorniPerMese(int mese, int anno){   // funzione che ritorna dato un mese ed un anno il numero di giorni in quel mese
        int numero_giorni=0;
        switch(mese){
            case 1:
            numero_giorni=31;
            break;
            case 2:
            if(anno%4==0){
                if(anno%100==0){
                    if(anno%400==0){
                        numero_giorni=29; 
                    }else{
                        numero_giorni=28;
                    }
                }else{
                    numero_giorni=29;
                }
            }else{
                numero_giorni=28;
            }
            break;
            case 3:
            numero_giorni=31;
            break;
            case 4:
            numero_giorni=30;
            break;
            case 5:
            numero_giorni=31;
            break;
            case 6:
            numero_giorni=30;
            break;
            case 7:
            numero_giorni=31;
            break;
            case 8:
            numero_giorni=31;
            break;
            case 9:
            numero_giorni=30;
            break;
            case 10:
            numero_giorni=31;
            break;
            case 11:
            numero_giorni=30;
            break;
            case 12:
            numero_giorni=31;
            break;
            default:
            break;
        }
        return numero_giorni;
    }

    public int[] conversioneDataNumero(String data)throws Exception{   // funzione per convertire la data in un numero
        String[] data_separata = data.split(" ");

        int GIORNO=0, MESE=0, ANNO=0;

        int [] data_return = new int [3];

        switch(data_separata[1]){  //switch per assegnare ad ogni mese un numero
            case "gennaio":
            MESE=1;
            break;
            case "febbraio":
            MESE=2;
            break;
            case "marzo":
            MESE=3;
            break;
            case "aprile":
            MESE=4;
            break;
            case "maggio":
            MESE=5;
            break;
            case "giugno":
            MESE=6;
            break;
            case "luglio":
            MESE=7;
            break;
            case "agosto":
            MESE=8;
            break;
            case "settembre":
            MESE=9;
            break;
            case "ottobre":
            MESE=10;
            break;
            case "novembre":
            MESE=11;
            break;
            case "dicembre":
            MESE=12;
            break;
            default:
            throw new Exception("Mese inserito non corretto");
        }

        // funzione per convertire l'anno inserito in un numero
        try{
            ANNO = Integer.parseInt(data_separata[2]);
        }catch(Exception e){
            throw new Exception("Anno inserito non corretto");
        }
        
        //verifica del fatto che l'anno inserito sia maggiore o uguale a 0
        if(ANNO<0){
            throw new Exception("Anno inserito non corretto");
        }
        

        // verifica del fatto che i giorni inseriti siano corretti

        int giorni_max = numeroGiorniPerMese(MESE, ANNO);

        GIORNO = Integer.parseInt(data_separata[0]);
        if(GIORNO > giorni_max || GIORNO<=0){
            throw new Exception("Giorno inserito non corretto");
        }

        data_return[0]=GIORNO;
        data_return[1]=MESE;
        data_return[2]=ANNO;

        return data_return;
    }

    public String conversioneNumeroData(int [] data){  // funzione per convertire un numero in una data sotto forma di stringa
        String mese="";

        switch(data[1]){
            case 1:
            mese="gennaio";
            break;
            case 2:
            mese="febbraio";
            break;
            case 3:
            mese="marzo";
            break;
            case 4:
            mese="aprile";
            break;
            case 5:
            mese="maggio";
            break;
            case 6:
            mese="giugno";
            break;
            case 7:
            mese="luglio";
            break;
            case 8:
            mese="agosto";
            break;
            case 9:
            mese="settembre";
            break;
            case 10:
            mese="ottobre";
            break;
            case 11:
            mese="novembre";
            break;
            case 12:
            mese="dicembre";
            break;
            default:
            break;
        }
        return(data[0] +" "+ mese +" "+ data[2]);
    }
    
}
