/*
verificare se il numero inserito è perfetto
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool verificaNumeroPerfetto(int numero_da_verificare);

int main(){
    int numero_acquisito=0;

    printf("inserisci un numero: ");
    scanf("%d", &numero_acquisito);

    if(verificaNumeroPerfetto(numero_acquisito)==true){
        printf("il numero è perfetto\n\n");
    }else{
        printf("il numero non è perfetto\n\n");
    }

    return 0;
}

bool verificaNumeroPerfetto(int numero_da_verificare){
    int resto=0;
    int somma=0;
    int divisore=1;
    while(divisore<numero_da_verificare){    //while per capire se il numero è perfetto
        resto=numero_da_verificare%divisore;   // ottengo il resto e guardo se esso è uguale a 0, se si, sommo alla varabile somma il divisore per cui ho ottenuto un resto = a zero
        if(resto==0){
            somma=somma+divisore;
        }
        divisore++;  //incremento il divisore
    }
    if(somma==numero_da_verificare){     //se somma è uguale a numero da verificare, ritorno true altrimenti ritorno false
        return true;
    }else{
        return false;
    }
}