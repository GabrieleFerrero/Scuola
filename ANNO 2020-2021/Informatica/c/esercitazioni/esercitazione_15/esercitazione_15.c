/*
capire se il numero inserito dentro il file di input è un numero primo
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define errore_apertura_file -1

bool numeroPrimo(int numero);

int main(){

    int numero_estratto_da_file=0;

    FILE *file_input;
    FILE *file_output;

    if ((file_input=fopen("input.txt", "r"))==NULL){     //verifica corretta apertura del file di input
        printf("errore file input\n");
        return errore_apertura_file;
    }else{
        printf("apertura file avvenuta con successo\n\n");
    }

    if ((file_output=fopen("output.txt", "w"))==NULL){     //verifica corretta apertura del file di output
        printf("errore file output\n");
        return errore_apertura_file;
    }else{
        printf("apertura file avvenuta con successo\n\n");
    }

    fscanf(file_input, "%d", &numero_estratto_da_file);   //acquisizione numero dal file di input

    if(numeroPrimo(numero_estratto_da_file)==true){     //verificare il valore di ritorno della funzione
        fprintf(file_output, "il numero %d è primo\n", numero_estratto_da_file);   //se = true stampo all'interno del file di output che il numero è primo
    }else{
       fprintf(file_output, "il numero %d non è primo\n", numero_estratto_da_file);   //altrimenti stampo che non è un numero primo
    }

    fclose(file_input);   //chiusura file di input
    fclose(file_output);   //chiusura file di output

    return 0;
}

bool numeroPrimo(int numero){    //funzione per verificare se il numero è primo
    int verifica=0;
    for(int i=2; i<numero; i++){    //for per osservare se il numero è divisibile per i numeri minori di lui
        if((numero%i)==0){   //se il numero è divisibile per i incremento la variabile verifica di uno
            verifica++;
        }else{   //altrimenti non faccio niente

        }
    }

    if(verifica==0){    //se la variabile verifica è uguale a 0 vuol dire che il resto di ogni divisione non era uguale a zero quindi il numero è primo
        return true;  //quindi return true dato che il numero è primo
    }else{
        return false;   //altrimenti return false
    }
}
