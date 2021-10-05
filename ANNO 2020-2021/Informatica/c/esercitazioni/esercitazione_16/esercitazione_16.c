/*
Invertire un vettore A senza usare un vettore di appoggio
*/

#include <stdlib.h>
#include <stdio.h>

#define grandezza_massima_stringa_estratta_da_file 500
#define max 500

#define errore_apertura_file -1

void inversioneStringa(int *array);

int main(){

    int numero_da_file=0;
    int vettore[max];
    int i=0;

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

    for(i=0; !feof(file_input); i++ ){
        fscanf(file_input, "%d", &numero_da_file);    //acquisizione stringa
        *(vettore+i)=numero_da_file;
    }

    *(vettore+i-1)='\0';   // pongo l'ultima cella + 1 in cui ha salvato un numero = a terminatore di stringa

    inversioneStringa(vettore);   //esecuzione funzione per inversione stringa

    for(int k=0; *(vettore+k); k++){
        fprintf(file_output, "%d ", *(vettore+k));   //stampo sitrnga invertita nel file di input
    }
    
    return 0;
}

void inversioneStringa(int *array){

        int variabile_di_appoggio=0;
        int lunghezza_array=0;

        for(lunghezza_array=0; *(array+lunghezza_array)!='\0'; lunghezza_array++){}    // calcolatore lunghezza array

        for(int k=0; k<(lunghezza_array/2); k++){    //se ci sono un numero dispari di numeri, e come se andassi a sostiruire il numero centrale con il numero centrale quindi io quello lo lascio stare percè dentro l'array è già salvato come centrale
            variabile_di_appoggio=*(array+k);   //salvo il numero iniziale in una variabile
            *(array+k)=*(array+lunghezza_array-k-1);   //salvo il numero finale al posto del numero iniziale, e alla cella del numero finale sottraggo anche 1 perché lunghezza array non tiene conto del fatto che gli array iniziano a contare da 0 e non da 1
            *(array+lunghezza_array-k-1)=variabile_di_appoggio;  //salvo la varabile al posto del numero finale
        }
        
}