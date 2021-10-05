/*
Crea la procedura INVERTI(x) che inverte le cifre del suo parametro che deve essere
un intero positivo. Per esempio se x = 12 alla fine x=21. Creare un main che testi
questa funzione.
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(){
    int numero=0;
    int resto=0;
    int esponente=-1;
    int numero_con_cifre_invertite=0;
    
    printf("inserisci il numero di cui vuoi invertire le cifre: ");
    scanf("%d", &numero);

    while(numero!=0){
    resto=numero%10;
    numero = numero/10;
    numero_con_cifre_invertite = numero_con_cifre_invertite*10 + resto;
    }

    printf("il numero invertito è: %d\n", numero_con_cifre_invertite);

    return 0;
}