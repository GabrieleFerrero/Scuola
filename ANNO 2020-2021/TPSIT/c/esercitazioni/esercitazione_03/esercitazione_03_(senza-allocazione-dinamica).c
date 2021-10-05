/*
creare l'algoritmo di acquisizione e riproduzione randomica di spotify gratuito
*/

#include "stdgl.h"

#define max_numero_canzoni 100
#define max_lunghezza_titolo 100
#define max_lunghezza_autore 100
#define max_lunghezza_riga 500
#define max_caratteri_array_secondario 100
#define max_caratteri_nome_file_playlist 100

#define errore_apertura_file -1
#define esito_corretto 0

typedef struct t_song{
    int numero_in_playlist;
    int numero_di_riproduzione;
    char titolo_canzone[max_lunghezza_titolo];
    char autore_canzone[max_lunghezza_autore];
}song;

typedef struct t_file_csv{
    song canzone[max_numero_canzoni];
    int numero_canzoni;
}file_csv;

FILE* definizionePuntatoreFile();
void estrazioneAndSalvataggioDati(file_csv *struct_canzone, FILE *file_fp);
void assegnazioneNumeroRandomAndRiproduzioneCanzone(file_csv *struct_canzone);





int main(){

    file_csv file;
    FILE *fp;

    fp=definizionePuntatoreFile();

    estrazioneAndSalvataggioDati(&file, fp);

    assegnazioneNumeroRandomAndRiproduzioneCanzone(&file);

    fclose(fp);

    return esito_corretto;
}





FILE* definizionePuntatoreFile(){
    FILE *fp;
    if ((fp=fopen("playlist.csv", "r"))==NULL){
        printf("errore apertura file playlist.csv");
        return errore_apertura_file;
    }else{
        printf("corretta apertura del file playlist.csv");
    }

    return fp;
}

void estrazioneAndSalvataggioDati(file_csv *struct_canzone, FILE *file_fp){

    char array_salvataggio_temporaneo[max_lunghezza_riga];
    char *puntatore_estrazione_stringa;
    int numero_righe=0;   //faccio partire il numero delle canzoni da 0, anche se andrebbe fatto partire da 1 perche poi alla fine andrebbe decrementato di 1
    int numero_canzone=0;

    for(numero_righe=0; !feof(file_fp); numero_righe++){

        fgets(array_salvataggio_temporaneo, max_lunghezza_riga, file_fp);   //acquisizione stringa da file.csv



        /* inizio acquisizione numero canzone in playlist */        
        
        puntatore_estrazione_stringa=strtok(array_salvataggio_temporaneo, ',');
        
        numero_canzone=ctoi(array_salvataggio_temporaneo);    // conversione numero char in int

        printf("%d\n", numero_canzone); 

        (*struct_canzone).canzone[numero_canzone].numero_in_playlist=numero_canzone;   //salvataggio del numero della canzone del file.csv
            
        /* fine acquizione numero canzone in playlist */



        /* inizio acquisizione titolo canzone */

        puntatore_estrazione_stringa=strtok(NULL, ',');

        strcpy((*struct_canzone).canzone[numero_canzone].titolo_canzone, puntatore_estrazione_stringa);

        /* fine acquisizione titolo canzone */



        /* inizio acquizione autore canzone */

        puntatore_estrazione_stringa=strtok(NULL, ',');

        strcpy((*struct_canzone).canzone[numero_canzone].autore_canzone, puntatore_estrazione_stringa);

        /* fine acquizione autore canzone */

        printf("%s\n", (*struct_canzone).canzone[numero_canzone].titolo_canzone);
        printf("%s\n\n", (*struct_canzone).canzone[numero_canzone].autore_canzone);
    }
    (*struct_canzone).numero_canzoni=numero_righe;
}

void assegnazioneNumeroRandomAndRiproduzioneCanzone(file_csv *struct_canzone){
    int i=0;
    int n=0;
    int numero_random=0;
    bool numero_diverso=true;   //varabile per vedere se il numero appena estratto con random è diverso dai numeri estratti precedentemente

    for(int k=0; k<(*struct_canzone).numero_canzoni; k++){   //azzeramento array salvataggio 
        (*struct_canzone).canzone[k].numero_di_riproduzione=0;
    }

    while(i<(*struct_canzone).numero_canzoni){    //while per genrare numero random
        numero_random=rand()%(struct_canzone->numero_canzoni);   //genrazione numero random
        for(int b=0; b<(*struct_canzone).numero_canzoni; b++){   //guardare se il numero appena generato è diverso dai numeri generati prima
            if(numero_random!=(*struct_canzone).canzone[b].numero_di_riproduzione){  //se è uguale non si fa nulla

            }else{   //se no cambio il valore della variabile numero_diverso da true a false
                numero_diverso=false;
            }
        }
        if(numero_diverso==true){   //se numero_diverso è uguale a true capisco che il numero generato è nuovo e lo copio dentro alla variabile numero_di_riproduzione della canzone e poi incremento la variabile i
            (*struct_canzone).canzone[i].numero_di_riproduzione=numero_random;
            i++;
        }else{

        }
    }

    while(n<(*struct_canzone).numero_canzoni){   //while per la riproduzione delle canzoni
        for(int g=0; g<(*struct_canzone).numero_canzoni; g++){   // for per scorrere i numeri di riproduzione delle cazoni
            if((*struct_canzone).canzone[g].numero_di_riproduzione==n){   // e se sono uguali a n vengono stampati titolo e autore della canzone e viene incrementato n
                printf("%s\t", (*struct_canzone).canzone[g].titolo_canzone);
                printf("%s\n\n", (*struct_canzone).canzone[g].autore_canzone);
                n++;
            }else{

            }
        }
        
    }
    
}