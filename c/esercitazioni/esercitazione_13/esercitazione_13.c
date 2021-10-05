/*
Dato un numero binario convertirlo in decimale (inizialmente chiedere da quante cifre è 
composto il numero e poi far inserire una cifra per volta a partire dalla più significativa)
*/

#include <stdlib.h>
#include <stdio.h>
#include "stdgl.h"
#include <math.h>

void conversioneBinDec(int bin, int *dec, int esponente);

int main(){
    int grandezza_numero_binario=0;
    int numero_bin=0;
    int numero_dec=0;

    scanfInt("inserisci il numero di cifre del numero binario: ", &grandezza_numero_binario);

    for(int i=0; i<grandezza_numero_binario; i++){
        scanfInt("inserisci la cifra binaria, partendo dalla più significativa: ", &numero_bin);
        conversioneBinDec(numero_bin, &numero_dec, grandezza_numero_binario-1-i  /* grandezza_numero_binario-1-i --> serve per dare il corretto esponente */);
    }

    printf("il numero convertito in decimale è: %d\n", numero_dec);

    return 0;
}

void conversioneBinDec(int bin, int *dec, int esponente){   // funzione che converte numero binario in numero decimale
    (*dec)=(*dec)+(bin*(pow(2, esponente)));  //numero decimale = numero decimale + numero binario * 2^esponente
}