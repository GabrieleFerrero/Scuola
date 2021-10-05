/*
Creare un programma che dato un numero intero, avente un numero arbitrario di cifre inserite
dall’utente, lo scriva in output con le cifre in ordine inverso. Utilizzare una pila e le implementazioni
dei metodi push e pop.


Si deve fare una PILA FIFO = LISTA
*/

#include <stdgl.h>

typedef struct nodo{
    int valore;
    struct nodo* next;
}Nodo;


Nodo* push(Nodo* head, int elemento);
Nodo* pop(Nodo *head);


int main(){
    int numero=0;
    int cont=0;
    Nodo* head=NULL;
    scanfInt("Inserire un numero: ", &numero);

    while(numero!=0){
        head=push(head,numero%10);
        numero/=10;
        cont++;
    }

    printf("Il numero invertito è ");
    for(int i=0; i<cont; i++){
        printf("%d", head->valore);
        head=pop(head);
    }
    printf("\n");

    return 0;
}


Nodo* push(Nodo* head, int elemento){
    Nodo* copia_head=head;
    if(head==NULL){
        head=(Nodo*)malloc(sizeof(Nodo));
        head->valore=elemento;
        head->next=NULL;
        copia_head=head;
    }else{
        while(head->next!=NULL){
        head=head->next;
        }

        head->next=(Nodo*)malloc(sizeof(Nodo));
        head->next->valore=elemento;
        head->next->next=NULL;
    }
    return copia_head;
}


Nodo* pop(Nodo *head){
    Nodo* copia_next=head->next;
    free(head);
    return copia_next;
}