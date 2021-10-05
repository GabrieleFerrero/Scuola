/* 
Usando le funz/proc create degli esercizi precedenti stampare triangolo fare un
programma che letto un numero non negativo H e un carattere C, stampare a video
un triangolo rettangolo isoscele di altezza H. Per esempio se H = 3
X
XX
XXXA
*/


#include <stdlib.h>
#include <stdio.h>

int main(){
    int altezza_triangolo=0;
    char carattere_composizione_triangolo;

    printf("inserire l'altezza del triangolo: ");
    scanf("%d", &altezza_triangolo);
    printf("inserire la lettera che comporrà il triangolo: ");
    scanf("%*c");
    scanf("%c", &carattere_composizione_triangolo);

    for(int i=0; i<altezza_triangolo; i++){
        for(int j=0; j<i+1; j++){
            printf("%c", carattere_composizione_triangolo);
        }
        printf("\n");
    }

    return 0;
}
