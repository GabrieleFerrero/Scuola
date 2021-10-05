/* 
fare un programma per osservare la variabile dell'indice di contagio
*/


#include "stdlib.h"
#include "stdio.h"
#include "math.h"

#define max_numero_giorni_in_cui_tutti_possono_essere_contagiati 500

int main(){
    int N=0, numero_giorno=0;
    float numero_contagiati=1, R=0;

    float contagi_per_giorno[max_numero_giorni_in_cui_tutti_possono_essere_contagiati];   //definizione array

    printf("inserisci il numero di persone che contagia una sola persona: ");  //acquisizione R
    scanf("%f", &R);
    printf("\n");

    printf("inserisci il numero di persone da contagiare: "); //acquisizione N
    scanf("%d", &N);
    printf("\n");

    while(numero_contagiati<N){    //ciclo per calcolare i contagi per giorno
        contagi_per_giorno[numero_giorno]=numero_contagiati;
        printf("nel giorno %d il numero di contagiati è: %d\n", numero_giorno, (int)contagi_per_giorno[numero_giorno]);
        numero_contagiati=pow(R,numero_giorno);
        numero_giorno++;
    }

    if(numero_contagiati==N){     //se i numero dei contagiati è uguale a N decremento numero_giorno di 1
        numero_giorno--;
    }
    else{   //altrimenti pongo ancora all'interno dei contagi dell'ultimo giorno il numero di contagi avvenuti senza limitazioni del numero N
    contagi_per_giorno[numero_giorno]=numero_contagiati;
    }

    // calcolo numero ore con proporzione n.ore = (24*var)/differenza_contagiati_tra_ultimo_e_penultimo_giorno   altrimenti    24:differenza_contagiati_tra_ultimo_e_penultimo_giorno=n.ore:var
    float differenza_contagiati_tra_ultimo_e_penultimo_giorno = contagi_per_giorno[numero_giorno] - contagi_per_giorno[numero_giorno-1];
    float var = (float)N - contagi_per_giorno[numero_giorno-1];

    int numero_ore_per_completare_il_contagio_nell_ultimo_giorno = (24*var)/differenza_contagiati_tra_ultimo_e_penultimo_giorno;

    printf("il contagio è avvenuto in %d giorni/o e %d ore/a\n", numero_giorno++, numero_ore_per_completare_il_contagio_nell_ultimo_giorno);

    
    return 0;
}
