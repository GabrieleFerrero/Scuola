/*

Fare un esercizio nel quale si crea un struttura che contiene 2 parametri:
- una variabile di tipo int
- una variabile di tipo struct * che sarà il puntatore alla prossima struttura

in seguito se dato in input il numero -1 bisogna terminare l'esecuzione del programma; altrimenti 
se dato un numero naturale positivo, si guarda se sono già state allocate delle zone di memoria se no ne alloca una,
la quale sarà la testa della head, è la testa verrà salvata dentro la variabile head.
Altrimenti se sono già presenti delle aree di memoria allocata creo un altra area di memoria e lo salvo nel puntatore
alla prossima struttura.
Poi salvo il valore di n dentro la variabile "valore" di tipo int ed in seguito dentro il puntatore alla prossima struct
il valore NULL.

In fine stampo l'area di memoria a cui punta ogni struttura e il valore della variabile int dentro ogni struttura

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct S_El{
int valore;
struct S_El* next;
}El;

void push(El* head, int n);
void stampaLista(El* head);

int main(){
int n=0;
El* head;
El* l;
head=NULL; /* inizializzo il puntatore head (di tipo struct El) a NULL */

while(n>=0){

printf("Inserisci un naturale o -1 per terminare: ");
scanf("%d",&n);

if(n>=0){

if(head==NULL){ /* se il puntatore head è uguale a NULL */
/* alloco al puntatore head un indirizzo di un area di memoria di tipo struct ; e poi salvo questo indirizzo anche dentro il puntatore l (di tipo struct El) uguagliandolo al puntatore lista */
head = (El*) malloc(sizeof(El));
l = head;
l->valore=n;
}else{/* altrimenti se il puntatore head è diverso da NULL e quindi sono già state create delle struct El */
push(head, n);
}

}
}

printf("numeri inseriti: \n");
stampaLista(head);

printf("\n");
return 0;
}


void push(El* head, int n){
    
    while(head->next!=NULL){
        head = head->next;
    }
    head->next = (El*) malloc(sizeof(El));
    head->next->valore=n;
    head->next->next = NULL;

}

void stampaLista(El* head){
    while(head!=NULL){
        printf("%d - %p \n",head->valore, head->next);
        head = head->next; 
    }
}