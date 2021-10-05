/*
stabilire il numero di nucleutidi e il numero
*/

//#include "stdgl.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define errore_apertura_file_rna -1
#define errore_lettura_nucleotidi -2
#define corretta_esecuzione_del_programma 0

#define numero_max_caratteri_per_riga 300
#define numero_max_caratteri_per_parte_di_riga 100
#define numero_parti_per_riga 6
#define numero_caratteri_per_parte_di_riga 10
#define numero_max_caratteri_vettore_secondario 10

bool numeroAndTipoNeuclotidiTrovati(int *a, int *t, int *c, int *g, char *riga);

int main(){

    int numero_nucleotidi_a=0;
    int numero_nucleotidi_t=0;
    int numero_nucleotidi_c=0;
    int numero_nucleotidi_g=0;

    char riga[numero_max_caratteri_per_riga];

    FILE *file_rna;

    if ((file_rna=fopen("rna.txt", "r"))==NULL){     //verifica corretta apertura del file di input
        printf("errore file rna\n");
        return errore_apertura_file_rna;
    }else{
        printf("apertura file avvenuta con successo\n\n");
    }

    fgets(riga, numero_max_caratteri_per_riga, file_rna);

    while(!feof(file_rna)){    //lettura riga da file e passaggio della riga a funzione
        if(numeroAndTipoNeuclotidiTrovati(&numero_nucleotidi_a, &numero_nucleotidi_t, &numero_nucleotidi_c, &numero_nucleotidi_g, riga)==false){
            return errore_lettura_nucleotidi;
        }
    }

    printf("numero di nucleotidi a: %d\n", numero_nucleotidi_a);
    printf("numero di nucleotidi t: %d\n", numero_nucleotidi_t);
    printf("numero di nucleotidi c: %d\n", numero_nucleotidi_c);
    printf("numero di nucleotidi g: %d\n\n", numero_nucleotidi_g);

    return corretta_esecuzione_del_programma;
}

bool numeroAndTipoNeuclotidiTrovati(int *a, int *t, int *c, int *g, char *riga){    //funzione per contare il numero di nucleotidi all'interno di una riga
    char *parte_di_riga;
    char vettore_secondario[numero_max_caratteri_vettore_secondario];

    parte_di_riga=strtok(riga, ' ');   //salto acquisizione numero all'inizio della riga

    for(int i=0; i<numero_parti_per_riga; i++){   //for per dividere la riga in diversi parti separate dallo spazio
        parte_di_riga=strtok(NULL, ' ');  // il carattere 32 corrisponde in tabella ascii al carattere spazio, separazione riga in piu parti
        vettore_secondario=strdup(parte_di_riga);    // copia parte di riga acquisita in un vettore secondario
        for(int k=0; k<numero_caratteri_per_parte_di_riga; k++){   //lettura cella per cella del vettore secondario e conteggio numero dei diversi tipi di nucleotidi
            switch (*(vettore_secondario+k)){
                case 'a':
                (*a)++;
                break;
                case 't':
                (*t)++;
                break;
                case 'c':
                (*c)++;
                break;
                case 'g':
                (*g)++;
                break;
                default:
                return false;
                break;
            }
        }
    }

    return true;

}