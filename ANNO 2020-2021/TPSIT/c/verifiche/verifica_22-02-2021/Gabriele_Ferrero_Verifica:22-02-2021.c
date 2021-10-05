/*

*/

#include <stdgl.h>

#define NUMERO_CARTE 53
#define NUMERO_SEMI 4

typedef struct s_carta{
    char seme;
    int numero_carta;
    struct s_carta* next;
}carta;

int queue_is_empty(carta* head);
void enqueue(carta **head, carta **tail, carta *element);
carta* dequeue(carta **head, carta **tail);
carta* estrazione(carta** head, carta** tail);
void ricollocazione(carta** head, carta** tail, carta* carta_da_aggiungere);

int main(){

    //Una struttura dati di tipo FIFO è una coda è per gestire una coda ho bisogno di una head e di una tail
    carta* head = NULL;
    carta* tail = NULL;

    carta* struct_return = NULL;
    carta* card = NULL;

    //Inizializzazione altre variabili
    bool condizione_solo_piu_carte_rosse = false;
    int indice=0;

    char semi[NUMERO_SEMI];
    semi[0]='C';
    semi[1]='P';
    semi[2]='D';
    semi[3]='F';

    char semi_usciti[NUMERO_CARTE];
    int numeri_carte_uscite[NUMERO_CARTE];

    int numero_carta=0;
    char seme;

    int indice_verifica=0;
    bool trovato_doppione=false;

    //Inserimento carte dentro il mazzo
    while(indice<NUMERO_CARTE){
        numero_carta=rand()%13 + 1;
        seme = semi[(rand()%NUMERO_SEMI)];

        indice_verifica=0;
        trovato_doppione=false;

        //Verifica di non presenza numeri estratti
        while(indice_verifica<indice){
            if(numero_carta == numeri_carte_uscite[indice_verifica] and seme == semi_usciti[indice_verifica]){
                trovato_doppione=true;
            }
            indice_verifica++;
        }

        //Se non viene trovato alcun doppione si alloca un area di memoria di grandezza carta e gli si associa i valori estratti ed infine vengono inserti dentro il mazzo
        if(trovato_doppione==false){ 
            semi_usciti[indice]=seme;
            numeri_carte_uscite[indice]=numero_carta;
            card=(carta*)malloc(sizeof(carta));
            card->seme=seme;
            card->numero_carta=numero_carta;
            enqueue(&head, &tail, card);
            indice++;
        }
    }


    //Verifica presenza solo più carte rosse
    while(condizione_solo_piu_carte_rosse!=true){
        indice=0;
        condizione_solo_piu_carte_rosse=true;
        while((struct_return=estrazione(&head, &tail))!=NULL and indice<NUMERO_CARTE){  //Scorre completamente l'array una volta e verifica se ci sono certe di fiori o di picche
            if(struct_return->seme=='F' || struct_return->seme=='P'){
                condizione_solo_piu_carte_rosse=false;
                free(struct_return);
            }else{
                ricollocazione(&head, &tail, struct_return);
            }
            indice++;
        }
    }

    //Stampaggio carte
    printf("Le carte rimaste dentro il mazzo sono:\n");
    while((struct_return=estrazione(&head, &tail))!=NULL){
        printf("- La carta numero %d di %c\n", struct_return->numero_carta, struct_return->seme);
        free(struct_return);
    }
    printf("\n");

    return 0;
}


int is_empty(carta* head){
    if(head==NULL) return 1;
    else return 0;
}

void enqueue(carta **head, carta **tail, carta *element){ 
    if(is_empty(*head)){
        *head = element;
    }else{
        (*tail)->next = element;
    }
    *tail = element;
    element->next=NULL;
}


carta* dequeue(carta **head, carta **tail){  
    carta* ret = *head;

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


carta* estrazione(carta** head, carta** tail){
    carta* struct_return;
    carta* h = NULL;
    carta* t = NULL;
    int numero_di_elementi=0;

    while((struct_return=dequeue(head, tail))!=NULL){
        enqueue(&h, &t, struct_return);
        numero_di_elementi++;
    }

    int i=0;
    while(i<numero_di_elementi-1){
        struct_return=dequeue(&h, &t);
        enqueue(head, tail, struct_return);
        i++;
    }
    struct_return = dequeue(&h, &t);

    return struct_return;
    
}

void ricollocazione(carta** head, carta** tail, carta* carta_da_aggiungere){
    carta* struct_return;
    carta* h = NULL;
    carta* t = NULL;
    int numero_di_elementi=0;

    while((struct_return=dequeue(head, tail))!=NULL){
        enqueue(&h, &t, struct_return);
        numero_di_elementi++;
    }

    enqueue(head, tail, carta_da_aggiungere);

    int i=0;
    while(i<numero_di_elementi){
        struct_return=dequeue(&h, &t);
        enqueue(head, tail, struct_return);
        i++;
    }
}