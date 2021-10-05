/*
Dato un vettore A di interi creare i vettori PARI e DISPARI formati rispettivamente dagli elementi pari e dispari presenti in A
*/

#include "stdgl.h"

#define errore_apertura_file -1

#define max_elementi_array 1000

void divisioneNumeriPariAndDispari(int *array, int *array_pari, int *array_dispari, int dimensione_reale_array, int *dimensione_reale_array_pari, int *dimensione_reale_array_dispari);

int main(){

    FILE *file_input;

    int array[max_elementi_array];
    int array_pari[max_elementi_array];
    int array_dispari[max_elementi_array];
    int i=0;
    int dimensione_reale_array_pari=0;
    int dimensione_reale_array_dispari=0;
    
    if ((file_input=fopen("input.txt", "r"))==NULL){     //verifica corretta apertura del file di input
        printf("errore file input\n");
        return errore_apertura_file;
    }else{
        printf("apertura file avvenuta con successo\n\n");
    }

    for(i=0; !feof(file_input); i++){     //salvataggio numeri file di input in array
        fscanf(file_input, "%d", (array+i));
    }

    i--;
    
    divisioneNumeriPariAndDispari(array, array_pari, array_dispari, i, &dimensione_reale_array_pari, &dimensione_reale_array_dispari);

    for(int h=0; h<i; h++){     //stampa array iniziale
        printf("%d ", *(array+h));
    }
    printf("\n");

    for(int h=0; h<dimensione_reale_array_pari; h++){    //stampa array pari
        printf("%d ", *(array_pari+h));
    }
    printf("\n");

    for(int h=0; h<dimensione_reale_array_dispari; h++){    //stampa array dispari
        printf("%d ", *(array_dispari+h));
    }
    printf("\n");

    return 0;
}

void divisioneNumeriPariAndDispari(int *array, int *array_pari, int *array_dispari, int dimensione_reale_array, int *dimensione_reale_array_pari, int *dimensione_reale_array_dispari){
    int p=0;
    int d=0;
    for(int i=0; i<dimensione_reale_array; i++){    //for per suddividere i numeri pari da quelli dispari
        if((*(array+i)%2)==0){      //se il numero diviso per 2 da resto = 0 vorrà dire che sarà pari, e quindi si andrà a salvare all'interno di array_pari il numero e si incrementa una variabile_1
            *(array_pari+p)=*(array+i);
            p++;
        }else{   //altrimenti salvo il video dentro array_dispari e incremento una varibile_2
            *(array_dispari+d)=*(array+i);
            d++;
        }
    }
    *dimensione_reale_array_pari=p;
    *dimensione_reale_array_dispari=d;
}
