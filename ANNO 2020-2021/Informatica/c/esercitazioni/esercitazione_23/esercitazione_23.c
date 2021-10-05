/*
Data una stringa letta da tastiera (può contenere spazi),(con elemento tappo\0) creare la stringa con i caratteri invertiti
*/

#include <stdgl.h>

#define max_lunghezza_array 200

void acquisizioneStringa(char *stringa);
void invertireStringa(char *stringa, char *stringa_invertita);

int main(){

    char stringa[max_lunghezza_array];
    char stringa_invertita[max_lunghezza_array];

    acquisizioneStringa(stringa);

    invertireStringa(stringa, stringa_invertita);

    printf("%s\n", stringa_invertita);

    return 0;
}

void acquisizioneStringa(char *stringa){  //acquisizione array
    scanfString("inserire una frase: ", stringa);
}

void invertireStringa(char *stringa, char *stringa_invertita){
    char var;
    int dimensione_array=0;
    int i=0;

    for(dimensione_array=0; *(stringa+dimensione_array)!=0; dimensione_array++){}    //for per trovare la dimensione dell'array 

    for(i=0; i<dimensione_array; i++){    //for per invertire la stringa dentro un altro array
        *(stringa_invertita+dimensione_array-1-i)=*(stringa+i);    // sottraggo anche 1 perché nell'array si parte a contare da 0
    }
    *(stringa_invertita+i)='\0';    // termino la stringa con il terminatore di stringa \0
}