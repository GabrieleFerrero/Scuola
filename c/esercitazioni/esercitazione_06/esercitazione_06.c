/*
Creare upper(s), funzione che converte in maiuscolo tutti i caratteri di s. Utilizzare la
funzione isMinuscolo(car)
*/

#include <stdio.h>
#include <stdlib.h>

#define max_num_caratteri_stringa 100

char convertitore_da_lettera_minuscola_a_maiuscola(char var);
char convertitore_da_lettera_maiuscola_a_minuscola(char var);

int main(){

    char stringa[max_num_caratteri_stringa];

    printf("inserire la stringa: ");
    scanf("%s", stringa);

    for(int i=0; stringa[i]!='\0'; i++){
        if(((int)(stringa[i]))>=97){
            printf("%c", (int)(stringa[i])-32);    //rendo i caratteri minuscoli in maiuscoli
        }
        else{
            printf("%c", (int)(stringa[i])+32);   //rendo i caratteri maiuscoli in minuscoli
        }
    }

    printf("\n");

    return 0;
}