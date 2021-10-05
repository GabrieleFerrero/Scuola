/*
Dato in input un numero intero n, sommare i primi n numeri dispari e verificare che tale somma è uguale al quadrato di n
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool function(int n);

int main(){

    int numero_acquisito=0;

    printf("inserisci numero: ");
    scanf("%d", &numero_acquisito);

    if(function(numero_acquisito)==true){
        printf("la somma dei primi n numeri dispari è uguale al quadrato di n\n");
    }else{
        printf("la somma dei primi n numeri dispari non è uguale al quadrato di n\n");
    }

    return 0;
}

bool function(int n){  //funzione per la varifica del problema
    int var=0;
    for(int i=0; i<n; i++){   // for per sommare tutti i primi n numeri dispari
        var=var+((2*i)+1);  //utilizzo il generatore di numeri dispari
    }

    if(var==n*n){   // verifica per vedere se la somma è uguale al quadrato di n
        return true;
    }else{
        return false;
    }
}
