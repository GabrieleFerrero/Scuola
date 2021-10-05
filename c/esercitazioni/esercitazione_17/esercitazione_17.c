/*
leggere numeri da array finchè sono positivi e dire quante volte un numero è maggiore del precedente
*/

#include <stdlib.h>
#include <stdio.h>
#include "stdgl.h"

#define numero_grande 5000
#define grandezza_array 500

#define errore_apertura_file -1

void numeroVolteNumeroMaggioreInserito(int p, int n, int *numero_di_volte_maggiore);
int acquisizioneNumeri(int *array);

int main(){

    int numero_acquisito_1=0;
    int numero_acquisito_2=numero_grande;
    int numero_volte_numero_maggiore_inserito=0;
    int numero_elementi_array=0;

    int array[grandezza_array];

    numero_elementi_array=acquisizioneNumeri(array);

    for(int i=0; i<numero_elementi_array; i++){   //for per fare ciclare il programma fino a quando il puntatore non arriva alla fine del array

            numero_acquisito_1=*(array+i);
            
            if(numero_acquisito_1>0){   //guardo se il numero acquisito è positivo se si eseguo la funzione e acquisisco anche il secondo numero

            numeroVolteNumeroMaggioreInserito(numero_acquisito_1, numero_acquisito_2, &numero_volte_numero_maggiore_inserito);   //eseguo la funzione
            if(i<numero_elementi_array-1){ //metto questo controllo in modo che se arrivo alla fine io non vado avanti in una cella dell'array che non esiste
                i++;
            numero_acquisito_2=*(array+i);

            if(numero_acquisito_2>0){
                numeroVolteNumeroMaggioreInserito(numero_acquisito_2, numero_acquisito_1, &numero_volte_numero_maggiore_inserito);   //eseguo la funzione
            }else{

            }
            }
            }else{

            }
    }

    printf("%d\n", numero_volte_numero_maggiore_inserito);
    
    return 0;
}

void numeroVolteNumeroMaggioreInserito(int p, int n, int *numero_di_volte_maggiore){    //corpo funzione
    if(p>n){   //verifico se numero inserito è maggiore di quello prima
        (*numero_di_volte_maggiore)++;   //se si incremento di uno la variabile contatore
    }else{   //altrimenti non faccio nulla
        
    }
}

int acquisizioneNumeri(int *array){

    int i=0;

    printf("acquisizone numeri fino alla digitazione del numero -99\n");

    for(i=0; (*(array+i-1)!=-99) && i<grandezza_array; i++){   //for per l'acquisizione dei caratteri
    /*metto -1 perché altrimenti va a leggere sempre una cella dopo*/
        scanfInt("inserisci numero: ", (array+i));
    }

    return i--;
}


