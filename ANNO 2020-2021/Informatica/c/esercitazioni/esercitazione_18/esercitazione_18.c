/*
convertire in una stringa i caratteri minuscoli in maiuscoli
*/

#include <stdlib.h>
#include <stdio.h>
#include "stdgl.h"
#include <string.h>

#define grandezza_array 500

void convertitoreStringa(char *stringa);

int main(){

    char riga[grandezza_array];

    scanfString("inserisci stringa: ", riga);

    convertitoreStringa(riga);

    printf("%s\n", riga);

    return 0;
}

void convertitoreStringa(char *stringa){    //funzione per convertire la stringa da minuscola a maiuscola

    int carattere=0;

    for(int i=0; *(stringa+i)!='\0'; i++){   //for che va avanti finche non arriva alla fine dell'array
        if(*(stringa+i)>='a' && *(stringa+i)<='z'){   // se la cella è compresa tra a e z converto il carattere dentro la cella in un intero, secondo la codifica ascii, gli vado poi a sottrarre 32, e poi lo riconverto in char e lo salvo dentro la stessa cella dell'array
            carattere=(int)(*(stringa+i));
            *(stringa+i)=(char)(carattere-32);
        }
    }
}