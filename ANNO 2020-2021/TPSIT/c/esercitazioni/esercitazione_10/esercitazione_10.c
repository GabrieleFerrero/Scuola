/*
Scrivere un programma che chieda all’utente una stringa composta da parentesi aperte e chiuse: (,),[,],{,} e
che verifichi se le coppie e l’ordine delle (,),[,],{,} sono corretti. Utilizzare uno stack.
*/

#include <stdgl.h>

typedef struct nodo{
    char valore;
    struct nodo* before;
}Nodo;


int is_empty(Nodo* head);
Nodo* push(Nodo* head, char elemento);
Nodo* pop(Nodo* head);
bool carattereCorretto(char* carattere);


int main(){

    char* stringa;
    bool condizione=true;
    Nodo* head=NULL;

    stringa=scanfString("Inserire una stringa formata da parentesi: ");

    for(int i=0; *(stringa+i)!='\0' && condizione; i++){
        if(carattereCorretto((stringa+i))){
            head=push(head, *(stringa+i));
        }
        else{
            if((head->valore is '(' and *(stringa+i) is ')') or (head->valore is '[' and *(stringa+i) is ']') or (head->valore is '{' and *(stringa+i) is '}')){}
            else{
                condizione=false;
            }
            head=pop(head);
        }
    }

    if(condizione){
        printf("Le parentesi sono state aperte e chiuse correttamente\n");
    }else{
        printf("Le parentesi non sono state aperte e chiuse correttamente\n");
    }
    
    return 0;
}



int is_empty(Nodo* head){
    if(head==NULL) return 1;
    else return 0;
}


Nodo* push(Nodo* head, char elemento){
    Nodo* new_head; 
    if(is_empty(head)){
        new_head = (Nodo*)malloc(sizeof(Nodo));
        new_head->valore=elemento;
        new_head->before=NULL;
    }else{
        new_head=(Nodo*)malloc(sizeof(Nodo));
        new_head->before=head;
    }
    return new_head;
}


Nodo* pop(Nodo* head){
    Nodo* new_head=head->before;
    if(is_empty(head)){
        return NULL;
    }else{
        free(head);
        return new_head;
    }
}

bool carattereCorretto(char* carattere){
    bool giusto=true;

    if(*carattere=='(' || *carattere=='[' || *carattere=='{'){}
    else{ giusto=false;}

    return giusto;
}