/*
Dato un numero n calcolarne il fattoriale ricordando che 0!=1 1!=1 n!=n*(n-1)*(n-2)*…*2*1
*/

#include <stdlib.h>
#include <stdio.h>
#include "stdgl.h"

int calcoloFattoriale(int numero);

int main(){

    int numero_acquisito=0;

    scanfInt("inserisci numero: ", &numero_acquisito);

    printf("il fattoriale di %d è %d\n\n", numero_acquisito, calcoloFattoriale(numero_acquisito));

    return 0;
}

int calcoloFattoriale(int numero){   //funzione per il calcolo del fattoriale
    int numero_di_ritorno=1;
    for(int i=0; i<numero; i++){
        numero_di_ritorno=numero_di_ritorno*(numero-i);  // vado a moltiplicare alla variabile numero di ritorno il numero acquisito meno i
    }

    return numero_di_ritorno;
}