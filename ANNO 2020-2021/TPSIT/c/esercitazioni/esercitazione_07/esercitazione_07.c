/*
Creare un programma in C che facendo uso di array dinamici e della aritmetica dei puntatori (OBBLIGATORIO),
legga il file https://raw.githubusercontent.com/conradis/TPSIT-classi-quarte/main/Esercitazioni/data.csv
e lo carichi in memoria.
Successivamente calcolare:
1) top 3 delle regioni per numero di ricoveri in terapia intensiva
2) totale dei ricoverati in terapia intensiva
3) top 3 delle regioni con meno casi totali positivi.
*/

#include <stdgl.h>

#define max_lunghezza_per_sigla_stato 3
#define errore_apertura_file -1
#define max_dimensione_riga_file 2000
#define max_caratteri_latitudine 100
#define max_caratteri_longitudine 100
#define max_caratteri_dominazione_regione 50
#define max_caratteri_codice_regione 50
#define max_numero_contagiati_per_regione 6000

typedef struct s_data{
    int anno;
    int mese;
    int giorno;
    int ora;
    int minuti;
    int secondi;
}data;

typedef struct s_regione{
    data data_odierna;
    char stato[max_lunghezza_per_sigla_stato];
    char codice_regione[max_caratteri_codice_regione];
    char denominazione_regione[max_caratteri_dominazione_regione];
    char latitudine[max_caratteri_latitudine];
    char longitudine[max_caratteri_longitudine];
    int ricoverati_con_sintomi;
    int terapia_intensiva;
    int totale_ospedalizzati;
    int isolamento_domiciliare;
    int totale_positivi;
    int variazione_totale_positivi;
    int nuovi_positivi;
    int dimessi_guariti;
    int deceduti;
    int casi_da_sospetto_diagnostico;
    int casi_da_screening;
    int totale_casi;
    int tamponi;
    int casi_testati;
    bool letto;
    struct s_regione* puntatore_alla_prossima_regione;
}regione;

FILE* aperturaFile(char *nome_file_csv);
int acquisizioneDati(regione* regione_iniziale, FILE* file_csv);
void topTreRegioniRicoverati(regione* regione_iniziale, int numero_di_regioni);
void numeroDiRicoverati(regione* regione_iniziale, int numero_di_regioni);
void numeroTreRegioniMenoContagiate(regione* regione_iniziale, int numero_di_regioni);

int main(int argc, char **argv){
    
    FILE* file_csv=aperturaFile(*(argv+1));

    if(file_csv==NULL){
        return errore_apertura_file;
    }

    regione* regione_iniziale = (regione*)malloc(sizeof(regione));

    int numero_regioni=acquisizioneDati(regione_iniziale, file_csv);
    topTreRegioniRicoverati(regione_iniziale, numero_regioni);
    numeroDiRicoverati(regione_iniziale, numero_regioni);
    numeroTreRegioniMenoContagiate(regione_iniziale, numero_regioni);

    free(regione_iniziale);

    return 0;
}

FILE* aperturaFile(char *nome_file_csv){
    FILE* fp;

    fp = fopen(nome_file_csv, "r");

    if(fp==NULL){
        fclose(fp);
    }

    return fp;
}

int acquisizioneDati(regione* regione_iniziale, FILE* file_csv){
    regione *reg;
    reg=regione_iniziale;

    char* stringa_divisa;
    int numero_regioni=0;

    char riga_file[max_dimensione_riga_file];
    fgets(riga_file, max_dimensione_riga_file, file_csv);

    for(numero_regioni=0; fgets(riga_file, max_dimensione_riga_file, file_csv)!=NULL; numero_regioni++){

        //acquisizione anno
        stringa_divisa=strtok(riga_file, "-");
        reg->data_odierna.anno=ctoi(stringa_divisa);
        //acquizione mese
        stringa_divisa=strtok(NULL, "-");
        reg->data_odierna.mese=ctoi(stringa_divisa);
        //acquisizione giorno
        stringa_divisa=strtok(NULL, "T");
        reg->data_odierna.giorno=ctoi(stringa_divisa);
        //acquisizione ora
        stringa_divisa=strtok(NULL, ":");
        reg->data_odierna.ora=ctoi(stringa_divisa);
        //acquisizione minuti
        stringa_divisa=strtok(NULL, ":");
        reg->data_odierna.minuti=ctoi(stringa_divisa);
        //acquisizione secondi
        stringa_divisa=strtok(NULL, ",");
        reg->data_odierna.secondi=ctoi(stringa_divisa);

        //acquisizione stato
        stringa_divisa=strtok(NULL, ",");
        strcpy(reg->stato, stringa_divisa);

        //acquisizione codice_regione
        stringa_divisa=strtok(NULL, ",");
        strcpy(reg->codice_regione, stringa_divisa);

        //acquisizione denominazione_regione
        stringa_divisa=strtok(NULL, ",");
        strcpy(reg->denominazione_regione, stringa_divisa);

        //acquisizione latitudine
        stringa_divisa=strtok(NULL, ",");
        strcpy(reg->latitudine, stringa_divisa);

        //acquisizione longitudine
        stringa_divisa=strtok(NULL, ",");
        strcpy(reg->longitudine, stringa_divisa);

        //acquisizione ricoverati_con_sintomi
        stringa_divisa=strtok(NULL, ",");
        reg->ricoverati_con_sintomi=ctoi(stringa_divisa);

        //acquisizione terapia_intensiva
        stringa_divisa=strtok(NULL, ",");
        reg->ricoverati_con_sintomi=ctoi(stringa_divisa);

        //acquisizione totale_ospedalizzati
        stringa_divisa=strtok(NULL, ",");
        reg->totale_ospedalizzati=ctoi(stringa_divisa);

        //acquisizione isolamento_domiciliare
        stringa_divisa=strtok(NULL, ",");
        reg->isolamento_domiciliare=ctoi(stringa_divisa);

        //acquisizione totale_positivi
        stringa_divisa=strtok(NULL, ",");
        reg->totale_positivi=ctoi(stringa_divisa);

        //acquisizione variazione_totale_positivi
        stringa_divisa=strtok(NULL, ",");
        reg->variazione_totale_positivi=ctoi(stringa_divisa);

        //acquisizione nuovi_positivi
        stringa_divisa=strtok(NULL, ",");
        reg->nuovi_positivi=ctoi(stringa_divisa);

        //acquisizione dimessi_guariti
        stringa_divisa=strtok(NULL, ",");
        reg->dimessi_guariti=ctoi(stringa_divisa);

        //acquisizione deceduti
        stringa_divisa=strtok(NULL, ",");
        reg->deceduti=ctoi(stringa_divisa);

        //acquisizione casi_da_sospetto_diagnostico
        stringa_divisa=strtok(NULL, ",");
        reg->casi_da_sospetto_diagnostico=ctoi(stringa_divisa);

        //acquisizione casi_da_screening
        stringa_divisa=strtok(NULL, ",");
        reg->casi_da_screening=ctoi(stringa_divisa);

        //acquisizione totale_casi
        stringa_divisa=strtok(NULL, ",");
        reg->totale_casi=ctoi(stringa_divisa);

        //acquisizione tamponi
        stringa_divisa=strtok(NULL, ",");
        reg->tamponi=ctoi(stringa_divisa);

        //acquisizione casi_testati
        stringa_divisa=strtok(NULL, ",");
        reg->casi_testati=ctoi(stringa_divisa);

        reg->puntatore_alla_prossima_regione=(regione*)malloc(sizeof(regione));
        reg=reg->puntatore_alla_prossima_regione;

    }
    return numero_regioni;
}

void topTreRegioniRicoverati(regione* regione_iniziale, int numero_di_regioni){
    regione* reg;
    regione* reg_trovata;
    reg=regione_iniziale;
    int max=0;

    for(int g=0; g<numero_di_regioni; g++){   //imposazione variabile letto di ogni struct regione = false
        reg->letto=false;
        reg=reg->puntatore_alla_prossima_regione;
    }

    reg=regione_iniziale;   //salvare di nuovo dentro alla variabile reg il puntatore alla prima struct

    for(int y=0; y<3; y++){   //for per cercare le tre regioni
    max=regione_iniziale->terapia_intensiva;    //impostare man = il numero totale di positivi della prima struct, avrei potuto metterlo anche = ad un numero molto piccolo
    for(int i=0; i<numero_di_regioni; i++){   //for per scorrere le diverse struct



        /*se poi il numero di persone in terapia intensiva è maggiore del maggiore letto fino ad ora e non è ancora stato letto (cosi tolgo il caso di leggere già il più piccolo letto prima), impostarlo come maggiore e memorizzare il suo indirizzo*/
        if((reg->terapia_intensiva>max)&&(reg->letto!=true)){
            max=reg->terapia_intensiva;
            reg_trovata=reg;
        }else{

        }
        reg=reg->puntatore_alla_prossima_regione;   //faccio scorrere puntatore array
    }
    printf("la regione numero %d per numero di contagiati è la %s con %d\n", y, reg_trovata->denominazione_regione,max);   //stampo il numero di positivi e il nome della regione e la classificazione
    reg->letto=true;   //poi imposto la variabile letto della variabile con il numero di persone in terapia intensiva più grande = true per non essere più contata al giro successivo
    reg=reg->puntatore_alla_prossima_regione;     //scorro alla prossima struttura
    }
}

void numeroDiRicoverati(regione* regione_iniziale, int numero_di_regioni){
    regione *reg;
    reg=regione_iniziale;

    int somma=0;

    for(int i=0; i<numero_di_regioni; i++){
        somma=somma+reg->terapia_intensiva;
        reg=reg->puntatore_alla_prossima_regione;
    }

    printf("il numero nazionale di persone in terapia intensiva è %d\n", somma);
}

void numeroTreRegioniMenoContagiate(regione* regione_iniziale, int numero_di_regioni){
    regione* reg;
    regione* reg_trovata;
    reg=regione_iniziale;
    int min=0;


    for(int g=0; g<numero_di_regioni; g++){   //imposazione variabile letto di ogni struct regione = false
        reg->letto=false;
        reg=reg->puntatore_alla_prossima_regione;
    }

    reg=regione_iniziale;   //salvare di nuovo dentro alla variabile reg il puntatore alla prima struct

    for(int y=0; y<3; y++){   //for per cercare le tre regioni
    min=reg->totale_positivi;   //impostare min = il numero totale di positivi della prima struct, avrei potuto metterlo anche = ad un numero molto grande
    for(int i=0; i<numero_di_regioni; i++){  //for per scorrere le diverse struct


        /*se poi il numero di positivi è minore del minore letto fino ad ora e non è ancora stato letto (cosi tolgo il caso di leggere già il più piccolo letto prima), impostarlo come minore e memorizzare il suo indirizzo*/
        if((reg->totale_positivi<min)||(reg->letto!=true)){ 
            min=reg->totale_positivi;
            reg_trovata=reg;
        }else{

        }
        reg=reg->puntatore_alla_prossima_regione;   //faccio scorrere puntatore array
    }
    printf("la regione numero %d per meno positivi è la %s con %d\n", y, reg_trovata->denominazione_regione,min);   //stampo il numero di positivi e il nome della regione e la classificazione
    reg->letto=true;  //poi imposto la variabile letto della variabile con il numero di positivi più piccolo = true per non essere più contata al giro successivo
    reg=reg->puntatore_alla_prossima_regione;  //scorro alla prossima struttura
    }
}
