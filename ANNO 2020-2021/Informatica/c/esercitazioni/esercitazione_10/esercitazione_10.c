/*
leggere numeri da terminale, come singolo intero, finchè sono positivi e dire quante volte un numero è maggiore del precedente
*/

#include <stdlib.h>
#include <stdio.h>

#define numero_grande 5000

void numeroVolteNumeroMaggioreInserito(int p, int n, int *numero_di_volte_maggiore);

int main(){

    int numero_acquisito_1=0;
    int numero_acquisito_2=numero_grande;
    int numero_volte_numero_maggiore_inserito=0;

    while(numero_acquisito_1>=0 && numero_acquisito_2>=0){   //while per fare ciclare il programma fino a quando non viene inserito un numero negativo
            printf("inserisci il numero [inserisci un numero negativo per terminare il programma]: ");
            scanf("%d", &numero_acquisito_1);   //acquisizione numero

            if(numero_acquisito_1>0){   //guardo se il numero acquisito è positivo se si eseguo la funzione e acquisisco anche il secondo numero

            numeroVolteNumeroMaggioreInserito(numero_acquisito_1, numero_acquisito_2, &numero_volte_numero_maggiore_inserito);   //eseguo la funzione

            printf("inserisci il numero [inserisci un numero negativo per terminare il programma]: ");
            scanf("%d", &numero_acquisito_2);   //acquisizione il secondo numero

            if(numero_acquisito_2>0){
                numeroVolteNumeroMaggioreInserito(numero_acquisito_2, numero_acquisito_1, &numero_volte_numero_maggiore_inserito);   //eseguo la funzione
            }else{

            }
            }else{

            }
    }

    printf("il numero di volte in cui il numero successivo è stato maggiore di quello prima è: %d\n\n", numero_volte_numero_maggiore_inserito);  //stampo il valore calcolato

    return 0;
}

void numeroVolteNumeroMaggioreInserito(int p, int n, int *numero_di_volte_maggiore){    //corpo funzione
    if(p>n){   //verifico se numero inserito è maggiore di quello prima
        (*numero_di_volte_maggiore)++;   //se si incremento di uno la variabile contatore
    }else{   //altrimenti non faccio nulla
        
    }
}