/*
verificare il numero maggiore e minore di una sequenza di numeri inseriti
*/

#include <stdio.h>
#include <stdlib.h>

#define dimensione_max_array 100
#define errore 200
#define max 999999
#define min -999999

int searchMaxNumber(int *array_of_number, int dim_array);
int searchMinNumber(int *array_of_number, int dim_arrray);
int convertCharInt(char *carattere);

int main(){

    int contenitore_numeri[dimensione_max_array];
    int i=0;

    for(i=0; contenitore_numeri[i-1]!=-9; i++){   //acquisizione carattere
        printf("inserisci il numero (per smettere di inserire numeri digitare -9): ");
        scanf("%d", &contenitore_numeri[i]);
    }

    printf("il numero maggiore tra quelli inseriti è: %d\n", searchMaxNumber(contenitore_numeri, i-1));
    printf("il numero minore tra quelli inseriti è: %d\n\n", searchMinNumber(contenitore_numeri, i-1));

    return 0;
}


int searchMaxNumber(int *array_of_number, int dim_array){   //cerco il numero maggiore
    int max_number=min;

    for(int i=0; i<dim_array; i++){    //for per cercare il numero maggiore, se il numero dell'array è maggiore del numero dentro la varabile max_number, salvo il valore dell'array dentro la varabile max_number
        if(*(array_of_number+i)>max_number){
            max_number=*(array_of_number+i);
        }else{

        }
    }
    
    return max_number;
}

int searchMinNumber(int *array_of_number, int dim_array){   //cerco il numero minore
    int min_number=max;

    for(int i=0; i<dim_array; i++){   //for per cercare il numero minore, se il numero dell'array è minore del numero dentro la varabile min_number, salvo il valore dell'array dentro la varabile min_number
        if(*(array_of_number+i)<min_number){
            min_number=*(array_of_number+i);
        }else{

        }
    }

    return min_number;
}