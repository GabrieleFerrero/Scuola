/*
creare l'algoritmo di acquisizione e riproduzione randomica di spotify gratuito, con allocazione dinamica
*/

#include <stdgl.h>

#define max_lunghezza_riga 500
#define max_caratteri_array_di_appoggio 100
#define dimensione_struct_song sizeof(song)
#define max_lunghezza_titolo 100
#define max_lunghezza_autore 100

#define errore_apertura_file -1
#define esito_corretto 0



typedef struct s_song{
    int numero_in_playlist;
    int numero_di_riproduzione;
    char *autore_canzone;
    char *titolo_canzone;
    struct s_song *puntatore_alla_prossima_struttura;   //non uso song perché non è ancora stato definito
}song;




FILE* definizionePuntatoreFile();
void estrazioneAndSalvataggioDati(song *puntatore_alla_prima_struct, FILE *file_fp);
void assegnazioneNumeroRandomAndRiproduzioneCanzone(song *puntatore_alla_prima_struct);





int main(){

    FILE *fp;

    song *puntatore_alla_prima_struttura;
    puntatore_alla_prima_struttura=(song*)(malloc(dimensione_struct_song));
    
    fp=definizionePuntatoreFile();

    if(fp==NULL){
        return errore_apertura_file;
    }

    estrazioneAndSalvataggioDati(puntatore_alla_prima_struttura, fp);

    printf("ehi");

    assegnazioneNumeroRandomAndRiproduzioneCanzone(puntatore_alla_prima_struttura);

    fclose(fp);

    free(puntatore_alla_prima_struttura);  //in automatico si perdono anche tutte le successive

    return esito_corretto;
}





FILE* definizionePuntatoreFile(){
    FILE *fp;
    fp=fopen("playlist.csv", "r");
    if(fp==NULL){
        printf("errore apertura file playlist.csv\n");
        fclose(fp);
    }else{
        printf("corretta apertura del file playlist.csv\n");
    }

    return fp;
}

void estrazioneAndSalvataggioDati(song *puntatore_alla_prima_struct, FILE *file_fp){

    song *canzone;
    canzone=puntatore_alla_prima_struct;

    /* definizione variabile di tipo song* per poterci salvare all'interno l'indirizzo della struct di tipo song creata nel main */


    char *puntatore_a_pezzo_estratto;
    char array_salvataggio_temporaneo[max_lunghezza_riga];
    int numero_canzone=0;
    

    while(feof(file_fp)!=EOF){

        fgets(array_salvataggio_temporaneo, max_lunghezza_riga, file_fp);
        printf("coo");
        printf("%s", array_salvataggio_temporaneo);

        /* inizio acquisizione numero canzone in playlist */        
        
        puntatore_a_pezzo_estratto=strtok(array_salvataggio_temporaneo, ",");
        
        numero_canzone=ctoi(puntatore_a_pezzo_estratto);    // conversione numero char in int

        printf("%d\n", numero_canzone); 

        canzone->numero_in_playlist=numero_canzone;   //salvataggio del numero della canzone del file.csv
            
        /* fine acquizione numero canzone in playlist */



        /* inizio acquisizione titolo canzone */

        puntatore_a_pezzo_estratto=strtok(NULL, ",");
        canzone->titolo_canzone=strdup(puntatore_a_pezzo_estratto);

        /* fine acquisizione titolo canzone */



        /* inizio acquizione autore canzone */

        puntatore_a_pezzo_estratto=strtok(NULL, ",");
        canzone->autore_canzone=strdup(puntatore_a_pezzo_estratto);

        /* fine acquizione autore canzone */



        /* stampaggio autore e titolo di una canzone attraverso vettore di appoggio */

        printf("%s\n", canzone->titolo_canzone);
        printf("%s\n\n", canzone->autore_canzone);


        /* creazione array con accesso a puntatore */
        printf("\n\nhola\n\n");
        printf("car");
        canzone->puntatore_alla_prossima_struttura=(song*)(malloc(dimensione_struct_song));  
        /* salvo dentro la variabile canzone->puntatore_alla_prossima_struttura l'indirizzo della prossima locazione di memoria */
        printf("ca2");
        canzone=canzone->puntatore_alla_prossima_struttura;
        /* e alla fine associo alla variabile canzone l'indirizzo della nuova locazione di memoria */
        printf("ciao");
        printf("\n\n\n%p\n\n\n", canzone);
        
    }
    printf("y");
    canzone=NULL;
    printf("gou");
    
}

void assegnazioneNumeroRandomAndRiproduzioneCanzone(song *puntatore_alla_prima_struct){
    int indice_array = 0;
    int numeri_random[100];
    int numero_random = 0;
    bool numero_diverso = false;

    song *canzone;   //inizializzazione variabile di tipo song*
    canzone=puntatore_alla_prima_struct;

    song* ultima_canzone_analizzata;

    int n_song=0;

    while(canzone!=NULL){   //calcolo numero di canzoni
        canzone=canzone->puntatore_alla_prossima_struttura;
        n_song++;
    }



    canzone=puntatore_alla_prima_struct;  //riinizializzazione alla prima struct

    while(canzone!=NULL){    //while per generare numero random
        printf("ciao");
        numero_random=rand()%(n_song);   //generazione numero random
        for(int b=0; b<indice_array; b++){   //guardare se il numero appena generato è diverso dai numeri generati prima
            if(numero_random==numeri_random[b]){  //se è uguale pongo la variabile numero_diverso = true
                numero_diverso = true;
            }
        }
        if(numero_diverso==true){   //se numero_diverso è uguale a true capisco che il numero generato è nuovo e lo copio dentro alla variabile numero_di_riproduzione della canzone e poi incremento la variabile i
        }else{
            numeri_random[indice_array]=numero_random;
            canzone->numero_di_riproduzione=numero_random;
            canzone=canzone->puntatore_alla_prossima_struttura;   //inizializzo il puntatore canzone con l'indirizzo della prossiama struttura
            indice_array++;
        }
        numero_diverso=false;
    }



    for(int i=0; i<n_song; i++){   //while per la riproduzione delle canzoni
        canzone=puntatore_alla_prima_struct;  //inizializzazione alla prima struct
        while(canzone!=NULL){   // for per scorrere i numeri di riproduzione delle cazoni
            if(canzone->numero_di_riproduzione==i){   // e se sono uguali a n vengono stampati titolo e autore della canzone e viene incrementato n
                printf("%s\t", canzone->titolo_canzone);
                printf("%s\n\n", canzone->autore_canzone);
                canzone=canzone->puntatore_alla_prossima_struttura;  //inizializzo il puntatore canzone con l'indirizzo della prossiama struttura
            }
        }
    }
}
