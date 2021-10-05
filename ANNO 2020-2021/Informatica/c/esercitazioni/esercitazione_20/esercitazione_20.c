/*
Dopo aver caricato un vettore di numeri interi con N elementi, contare gli elementi che hanno 
valore superiore ad un X letto da file
*/

#include "stdgl.h"

#define errore_apertura_file -1

#define max_elementi_array 1000

int function(int *array, int X, int dimensione_reale_array);

int main(){

    FILE *file_input;

    int array[max_elementi_array];
    int i=0;
    int numero_letto_da_file=0;
    
    if ((file_input=fopen("input.txt", "r"))==NULL){     //verifica corretta apertura del file di input
        printf("errore file input\n");
        return errore_apertura_file;
    }else{
        printf("apertura file avvenuta con successo\n\n");
    }

    fscanf(file_input, "%d", &numero_letto_da_file);   //acquisizione valore di confronto

    for(i=0; (i<max_elementi_array) && ((*(array+i-1))!=-99); i++){   //acquisizione numeri da confrontare
        scanfInt("inserire il numero [per terminare l'acquisizione digitare -99]: ", (array+i));
    }
    i--;   //diminuisco la i di uno perché nel ciclo for alla fine viene sempre incrementata di uno
    
    printf("%d\n", function(array, numero_letto_da_file, i));

    return 0;
}

int function(int *array, int X, int dimensione_reale_array){
    int valore_di_ritorno=0;
    for(int i=0; i<dimensione_reale_array; i++){    //for per capire quandi numeri sono maggiori di X
        if(*(array+i)>X){   //se il numero contenuto dentro la cella è maggiore dell'array incremento una variabile
            valore_di_ritorno++;
        }
    }
    return valore_di_ritorno;   //ritorno la variabile
}