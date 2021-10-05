/*
Prendere in input un numero n>0 e calcolare la somma delle sue cifre
*/


#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int sommaCifre(int numero);

int main(){

    int numero_acquisito=0;
    int return_function_somma=0;

    bool condizione_di_ciclo=true;

    while(condizione_di_ciclo==true){    //verifico se il risultato inserito è corretto, se si, esco dal while
        printf("inserisci numero: ");
        scanf("%d", &numero_acquisito);
        if(numero_acquisito>=0){
            condizione_di_ciclo=false;
        }else{
            printf("inserisci un numero maggiore o uguale a 0!!!\n");
        }
    }

    return_function_somma=sommaCifre(numero_acquisito);

    printf("la somma delle cifre del numero inserito è: %d", return_function_somma);

    printf("\n\n");

    return 0;
}

int sommaCifre(int numero){
    int resto=0;
    int somma_cifre=0;
    while(numero!=0){  //finche numero è diverso da 0 calcolo il resto del numero/10, divido numero per 10 e infine sommo alla variabile somma_cifre il resto
        resto=numero%10;
        numero=numero/10;
        somma_cifre=somma_cifre+resto;
    }

    return somma_cifre;
}
