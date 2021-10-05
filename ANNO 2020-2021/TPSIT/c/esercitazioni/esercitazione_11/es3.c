/*
Implementare le pile e i metodi pop() e push() utilizzando una coda con i suoi metodi
enqueue() and dequeue().
*/

# include <stdgl.h>

typedef struct s_queue_node{
    char elemento;
    struct s_queue_node* next;
}queue_node;

queue_node* q_tail=NULL;

int is_empty(queue_node* head);
void enqueue(queue_node **head, queue_node **tail, queue_node *element);
queue_node* dequeue(queue_node **head, queue_node **tail);

void push(queue_node** head, queue_node* element);
queue_node* pop(queue_node **head);


int main(){

    /* DEFINIZIONI VARIABILI CODA */
    queue_node* q_head=NULL;
    queue_node* q_struct_return=NULL;    
    queue_node* q_element=NULL;

    /* DEFINIZIONI ALTRE VARIABILI */
    int i=0;
    char dato;

    int numero_elementi_coda = scanfInt("Inserire il numero di elementi che si vogliono inserire dentro la coda: ");

    //acquisizione dati in coda
    while(i<numero_elementi_coda){
        dato = scanfChar("Inserire elemento: ");
        q_element = (queue_node*)malloc(sizeof(queue_node));
        q_element->elemento=dato;
        push(&q_head, q_element);
        i++;
    }

    //estrazioni dati da coda
    printf("Gli elementi inseriti sono: ");
    while((q_struct_return=pop(&q_head))!=NULL){
        printf("%c\t", q_struct_return->elemento);
        free(q_struct_return);
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



void push(queue_node** head, queue_node* element){
    enqueue(head, &q_tail, element);
}


queue_node* pop(queue_node **head){
    queue_node* struct_return;
    int numero_di_elementi=0;
    queue_node* h = NULL;
    queue_node* t = NULL;

    while((struct_return=dequeue(head, &q_tail))!=NULL){
        enqueue(&h, &t, struct_return);
        numero_di_elementi++;
    }

    int i=0;
    while(i<numero_di_elementi-1){
        struct_return=dequeue(&h, &t);
        enqueue(head, &q_tail, struct_return);
        i++;
    }
    struct_return = dequeue(&h, &t);

    return struct_return;
    
}

