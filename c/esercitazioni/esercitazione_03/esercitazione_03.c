/* Fare un programma che letto un numero non negativo N e un carattere C, stampi a
video N volte C Per esempio se N=4 e C= &#39;A&#39; a schermo compare
AAAA
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int main(){
    int a=1;
    char car;

    printf("inserisci un numero intero positivo: ");
    scanf("%d", &a);

    scanf("%*c");  //serve per eliminare l'acquisizione del carettere invio alla scanf dopo

    printf("inserisci un carattere: ");
    scanf("%c", &car);

    for(int i=0; i<a; i++){
        printf("%c\n", car);
    }

    printf("\n\n");
    
    return 0;
}
