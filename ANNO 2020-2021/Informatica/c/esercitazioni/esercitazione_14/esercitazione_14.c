/*
leggere numeri da un file, finchè sono positivi e dire quante volte un numero è maggiore del precedente
*/

#include <stdlib.h>
#include <stdio.h>

#define numero_grande 5000
#define errore_apertura_file -1

void numeroVolteNumeroMaggioreInserito(int p, int n, int *numero_di_volte_maggiore);

int main(){

    int numero_acquisito_1=0;
    int numero_acquisito_2=numero_grande;
    int numero_volte_numero_maggiore_inserito=0;

    FILE *file_input;
    FILE *file_output;

    if ((file_input=fopen("input.txt", "r"))==NULL){    //verificare la corretta apertura del file di input 
        printf("errore file input\n");
        return errore_apertura_file;
    }else{
        printf("apertura file avvenuta con successo\n\n");
    }

    if ((file_output=fopen("output.txt", "w"))==NULL){   //verificare la corretta apertura del file di output
        printf("errore file output\n");
        return errore_apertura_file;
    }else{
        printf("apertura file avvenuta con successo\n\n");
    }



    while(!feof(file_input)){   //while per fare ciclare il programma fino a quando il puntatore non arriva alla fine del file
            
            fscanf(file_input, "%d", &numero_acquisito_1);   //acquisizione numero da file

            if(numero_acquisito_1>0){   //guardo se il numero acquisito è positivo se si eseguo la funzione e acquisisco anche il secondo numero

            numeroVolteNumeroMaggioreInserito(numero_acquisito_1, numero_acquisito_2, &numero_volte_numero_maggiore_inserito);   //eseguo la funzione

            fscanf(file_input, "%d", &numero_acquisito_2); //acquisizione numero da file 

            if(numero_acquisito_2>0){
                numeroVolteNumeroMaggioreInserito(numero_acquisito_2, numero_acquisito_1, &numero_volte_numero_maggiore_inserito);   //eseguo la funzione
            }else{    //per usicre dal while principale se il numero letto è minore finisco la lettura dei dati ma senza più processarli dentro la funzione
                while(!feof(file_input)){
                    fscanf(file_input, "%d", &numero_acquisito_2);
                }
            }
            }else{     //per usicre dal while principale se il numero letto è minore finisco la lettura dei dati ma senza più processarli dentro la funzione
                while(!feof(file_input)){
                    fscanf(file_input, "%d", &numero_acquisito_1);
                }
            }
    }

    fprintf(file_output, "%d", numero_volte_numero_maggiore_inserito);
    
    fclose(file_input);
    fclose(file_output);

    return 0;
}






void numeroVolteNumeroMaggioreInserito(int p, int n, int *numero_di_volte_maggiore){    //corpo funzione
    if(p>n){   //verifico se numero inserito è maggiore di quello prima
        (*numero_di_volte_maggiore)++;   //se si incremento di uno la variabile contatore
    }else{   //altrimenti non faccio nulla
        
    }
}