#include <stdgl.h>

typedef struct s_stack_node{
    char elemento;
    struct s_stack_node* next;
}stack_node;


int stack_is_empty(stack_node* head);
void stack_push(stack_node** head, stack_node* element);
stack_node* pop(stack_node **head);
void espulsione(stack_node **head, int n);

int main(){

    stack_node* head=NULL;
    stack_node* element=NULL;

    int c=scanfInt("Inserisci il numero di elementi: ");
    int i=0;
    char t;
    while(i<c){
        t=scanfChar("Inserisci elemento: ");
        element = (stack_node*)malloc(sizeof(stack_node));
        element->elemento=t;
        stack_push(&head, element);
        i++;
    }


    int g = scanfInt("Inserisci numero di elementi da rimuovere: ");
    espulsione(&head, g);




    return 0;
}


int stack_is_empty(stack_node* head){
    if(head==NULL)return 1;
    else return 0;
}


void stack_push(stack_node** head, stack_node* element){
    if(stack_is_empty(*head)){
        *head = element;
        element->next=NULL;
    }else{
        element->next=*head;
        *head=element;
    }
}


stack_node* pop(stack_node **head){
    stack_node* ret=*head;
    if(stack_is_empty(*head)){
        return NULL;
    }else{
        *head=ret->next;
    }
    return ret;
}

void espulsione(stack_node **head, int n){
    bool condizione=true;
    stack_node* struct_return=NULL;
    int i=0;

    while(condizione && i<n){
        struct_return=pop(head);
        if(struct_return==NULL){
            condizione=false;
        }else{
            printf("%c\t",struct_return->elemento);
        }
        i++;
    }
}
