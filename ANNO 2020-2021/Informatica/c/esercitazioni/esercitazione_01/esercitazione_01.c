/* esercitazione sugli array utilizzando i puntatori */



#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define max_lettere 100

int main(){

    bool palindromo=true;
    char parola[max_lettere];
    int numero_lettere_parola=0;
    printf("inserisci una parola per scoprire se essa è palindorma: ");
    scanf("%s", parola);
    printf("\n");

    for(int k=0; *(parola + k)!='\0'; k++){   //for per capire la lunghezza della parola
        numero_lettere_parola++;
    }

    for(int i=0; i<numero_lettere_parola; i++){  //for per capire se la parola è palindroma
        if(*(parola + i) != *(parola + numero_lettere_parola-i-1)){
            palindromo=false;
        }
    }

    if(palindromo==false){
        printf("la parola %s non è palindroma\n\n", parola);
    }else{
        printf("la parola %s è palindroma\n\n", parola);
    }


    return 0;
}
