/*

Fare un esercizio nel quale si crea un struttura che contiene 2 parametri:
- una variabile di tipo int
- una variabile di tipo struct * che sarà il puntatore alla prossima struttura

in seguito se dato in input il numero -1 bisogna terminare l'esecuzione del programma; altrimenti 
se dato un numero naturale positivo, si guarda se sono già state allocate delle zone di memoria se no ne alloca una,
la quale sarà la testa della lista, è la testa verrà salvata dentro la variabile lista.
Altrimenti se sono già presenti delle aree di memoria allocata creo un altra area di memoria e lo salvo nel puntatore
alla prossima struttura.
Poi salvo il valore di n dentro la variabile "valore" di tipo int ed in seguito dentro il puntatore alla prossima struct
il valore NULL.

In fine stampo l'area di memoria a cui punta ogni struttura e il valore della variabile int dentro ogni struttura

*/

#include <stdio.h>
#include <stdlib.h>

struct El{
int valore;
struct El* next;
};


int main(){
int n;
struct El* lista;
struct El* l;
lista=NULL; /* inizializzo il puntatore lista (di tipo struct El) a NULL */

do{
printf("Inserisci un naturale o -1 per terminare: ");
scanf("%d",&n);

if(n>=0){

if(lista==NULL){ /* se il puntatore lista è uguale a NULL */
/* alloco al puntatore lista un indirizzo di un area di memoria di tipo struct ; e poi salvo questo indirizzo anche dentro il puntatore l (di tipo struct El) uguagliandolo al puntatore lista */
lista = (struct El*) malloc(sizeof(struct El));
l = lista;
}else{/* altrimenti se il puntatore lista è diverso da NULL e quindi sono già state create delle struct El */
/* inizializzo il puntatore contenuto in l all'indirizzo di una nuova area di memoria di tipo struct El ; ed inseguito aggiorno l'indirizzo del puntatore l alla nuova area di memoria allocata in l->next */
l->next = (struct El*) malloc(sizeof(struct El));
l = l->next;

}

l->valore = n; /* salvo il valore di n dentro la variabile "valore" contenuto in l */
l->next = NULL; /* in seguito setto il valore del puntatore alla prossima struct uguale a NULL */

}
}

while(n>=0);

l=lista; /* setto l'indirizzo del puntatore l all'indirizzo contenuto nel puntatore lista */
printf("numeri inseriti: \n");

while(l!=NULL){
printf("%d - %p \n",l->valore, l->next);
l=l->next; /* aggiorno l'indirizzo contenuto nel puntatore l all'indirizzo contenuto nel puntatore alla prossima struttura  */
}

printf("\n");
return 0;
}