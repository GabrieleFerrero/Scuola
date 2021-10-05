/*
Scrivere una funzione che inverta una coda, ovvero produca una coda invertendo l’ordine
degli elementi della coda di partenza. Suggerimento: utilizzare una pila.
*/


# include <stdgl.h>

typedef struct s_queue_node{
    char elemento;
    struct s_queue_node* next;
}queue_node;

typedef struct s_pila{
    char elemento;
    struct s_pila* next;
}pila;


int is_empty(queue_node* head);
void enqueue(queue_node **head, queue_node **tail, queue_node *element);
queue_node* dequeue(queue_node **head, queue_node **tail);

int p_is_empty(pila* head);
void push(pila** head, pila* element);
pila* pop(pila **head);


int main(){

    /* DEFINIZIONI VARIABILI CODA */
    queue_node* q_head=NULL;
    queue_node* q_tail=NULL;
    queue_node* q_struct_return=NULL;    
    queue_node* q_element=NULL;

    /* DEFINIZIONI VARIABILI PILA */
    pila* p_head=NULL;
    pila* p_element=NULL;
    pila* p_struct_return=NULL;

    /* DEFINIZIONI ALTRE VARIABILI */
    int i=0;
    char dato;

    int numero_elementi_coda = scanfInt("Inserire il numero di elementi che si vogliono inserire dentro la coda: ");

    //acquisizione dati in coda
    while(i<numero_elementi_coda){
        dato = scanfChar("Inserire elemento: ");
        q_element = (queue_node*)malloc(sizeof(queue_node));
        q_element->elemento=dato;
        enqueue(&q_head, &q_tail, q_element);
        i++;
    }

    //estrazione dati da coda e salvataggio in pila
    while((q_struct_return=dequeue(&q_head, &q_tail))!=NULL){
        p_element=(pila*)malloc(sizeof(pila));
        p_element->elemento=q_struct_return->elemento;
        push(&p_head, p_element);
    }

    //estrazioni dati da pila
    printf("Gli elementi invertiti sono: ");
    while((p_struct_return=pop(&p_head))!=NULL){
        printf("%c\t", p_struct_return->elemento);
        free(p_struct_return);
    }
    printf("\n");

    return 0;
}


int is_empty(queue_node* head){
    if(head==NULL) return 1;
    else return 0;
}

/*
*head e *tail si possono vedere come due celle fisiche a cui si cambiano valori interni
*/

void enqueue(queue_node **head, queue_node **tail, queue_node *element){ //con il doppio asterisco mi riferisco al puntatore passato per referenza dato che voglio modificarlo
    if(is_empty(*head)){
        *head = element;
    }else{
        (*tail)->next = element;
    }
    *tail = element;
    element->next=NULL;
}


queue_node* dequeue(queue_node **head, queue_node **tail){  //bisogna anche fare l'eleminazione dell'elemento con free(), ma bisogna farlo fuori dalla funzione
    queue_node* ret = *head;

    if(is_empty(*head)){
        return NULL;
    }else{
        *head = ret->next;
    }

    if(*head ==NULL){
        *tail = NULL;
    }

    return ret;
}


int p_is_empty(pila* head){
    if(head==NULL) return 1;
    else return 0;
}


void push(pila** head, pila* element){
    if(p_is_empty(*head)){
        *head = element;
        element->next=NULL;
    }else{
        element->next=*head;
        *head=element;
    }
}


pila* pop(pila **head){
    pila* ret=*head;
    if(p_is_empty(*head)){
        return NULL;
    }else{
        *head=ret->next;
    }
    return ret;
}

