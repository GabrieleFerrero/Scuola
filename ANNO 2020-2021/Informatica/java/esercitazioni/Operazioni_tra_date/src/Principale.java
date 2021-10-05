/*
1. Programma da console che permette di lavorare con le date 
(fare la differenza tra date e sommare un numero di giorni ad una data) senza 
utilizzare GregorianCalendar ma con una vostra classe (e considerando gli anni bisestili).
Aiuto: Sono da considerare bisestili gli anni divisibili per 4. Tra gli anni divisibili per 
4 non sono bisestili quelli divisibili per 100. Tra quelli divisibili per 
100 sono comunque bisestili quelli divisibili per 400.
*/
public class Principale {

    private CLInput cli;
    private Calendario data; 

    Principale(){
        cli = new CLInput();
        data = new Calendario();
    }

    public static void main(String[] args){
        Principale p = new Principale();
        int [] data_convertita_1 = new int [3];
        int [] data_convertita_2 = new int [3];
        char scelta_menu;
        int giorni_acquisiti=0;
        boolean condizone_while = true;

            /*
            while che serve per continuare a eseguire il programma e cambiare scelta
            */
            while(condizone_while==true){
                scelta_menu=p.cli.readChar("MENÙ:\n- digitare '1' per fare la somma di una data e di un numero di giorni\n- digitare '2' per sapere la differenza di giorni tra due date\n- digitare '3' per uscire\n\nInserire numero: ");
                switch(scelta_menu){  // switch per scegliere l'azione che si vuole fare
                    case '1':  // somma tra data e numero di giorni
                    try{  // se genera un errore l'acquisizione della data esce dal programma altrimenti continua e chiede il numero di giorni da sommargli
                        data_convertita_1 = p.data.conversioneDataNumero(p.cli.readString("Inserire una data [esempio: 15 luglio 2009]: "));
                        }catch(Exception e){
                            System.out.println("Data inserita non corretta\nEXIT...");
                            condizone_while=false;
                        }
                    if(condizone_while==true){
                        giorni_acquisiti = p.cli.readInt("Inserire il numero di giorni da sommare alla data: ");
                        if(giorni_acquisiti>=0){  // se il numero di giorni inserito va bene il programma calcola la somma
                            System.out.println("Il risultato è " + p.data.conversioneNumeroData(p.data.sommaDataGiorno(data_convertita_1, giorni_acquisiti)));
                        }else{
                            System.out.println("Numero di giorni inserito non corretto\nEXIT...");
                            condizone_while=false;
                        }
                    }
                    break;
                    case '2':  // nella scella numero 2 avviene la differenza di giorni tra due date
                    try{  // vengono fatti i controlli come nell'esercizio prima sulle date inserita ma in più sta volta viene anche previsto che la prima data inserita deve essere quella minore
                        data_convertita_1 = p.data.conversioneDataNumero(p.cli.readString("Inserire una data [esempio: 15 luglio 2009 , e la prima data che viene inserita deve essere quella minore]: "));
                        }catch(Exception e){
                            System.out.println("Data inserita non corretta\nEXIT...");
                            condizone_while=false;
                        }
                    if(condizone_while==true){
                        try{  // acquisizione seconda data
                            data_convertita_2 = p.data.conversioneDataNumero(p.cli.readString("Inserire una seconda data [esempio: 16 luglio 2009]: "));
                            }catch(Exception e){
                                System.out.println("Data inserita non corretta\nEXIT...");
                                condizone_while=false;
                            }
                        if(condizone_while==true){
                            if((data_convertita_1[0]*1+data_convertita_1[1]*1000+data_convertita_1[2]*1000000)>(data_convertita_2[0]*1+data_convertita_2[1]*1000+data_convertita_2[2]*1000000)){  // controllo che la data inserita per prima sia minore di quella inserita dopo altrimenti esco dal programma 
                                System.out.println("Data precedente maggiore di quella inserita dopo\nEXIT...");
                                condizone_while=false;
                            }else{
                            System.out.println("Il risultato è "+p.data.differenzaDataData(data_convertita_1, data_convertita_2)+" giorni");
                            }
                        }
                    }
                    break;
                    case '3':  // l'ultima scelta è per uscire dal programma
                    condizone_while=false;
                    System.out.println("EXIT...");
                    break;
                    default:
                    System.out.println("[numero inserito non corretto]");
                    break;

                }

            }
            
    }
}
