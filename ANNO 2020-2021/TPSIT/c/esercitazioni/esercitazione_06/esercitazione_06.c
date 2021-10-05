/*
creare un programma di rubrica telefonica
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NUM_CONTATTI 100
#define messaggio_inserimento printf("MENÙ\n\n- digitare '1' per inserire un contatto\n- digitare '2' per trovare un contatto in rubrica\n- digitare '3' per stampare la rubrica\n- digitare '#' per uscire dal programma\n\n");

typedef struct s_contatto{
    int id;
    char nome[64];
    char numero[16];
}contatto;

typedef struct s_rubrica{
    int num_inseriti;
    contatto db[MAX_NUM_CONTATTI];
}rubrica;

int inserisci(rubrica *r, char *nome, char *numero);
char* trova_numero_da_nome(rubrica *r, char *nome);
void stampa_rubrica(rubrica *r);

int main(){

    rubrica r;

    r.num_inseriti=0;

    char carattere_acquisito;
    char nome_contatto[64];
    char numero_contatto[16];
    bool verifica_while=true;

    
    while(verifica_while==true){
    messaggio_inserimento
    scanf("%c", &carattere_acquisito);   
    switch(carattere_acquisito){
        case '1':
        printf("inserire il nome del contatto da aggiungere: ");
        scanf("%s", nome_contatto);
        printf("inserire il numero del nuovo contatto: ");
        scanf("%s", numero_contatto);
        if(inserisci(&r, nome_contatto, numero_contatto)==0){
            printf("numero aggiunto con successo\n");
        }else{
            printf("non è stato possibile aggiungere il numero perché la rubrica è piena\n");
        }
        break;
        case '2':
        printf("inserire il nome da cercare: ");
        scanf("%s", nome_contatto);
        if(trova_numero_da_nome(&r, nome_contatto)==NULL){
            printf("errore, nessun contatto trovato\n");
        }else{
            printf("%s\n", trova_numero_da_nome(&r, nome_contatto));
        }
        break;
        case '3':
        stampa_rubrica(&r);
        break;
        case '#':
        printf("exit...\n\n");
        verifica_while=false;
        break;
        default:
        printf("opzione non riconosciuta!!!\n");
        break;
    }

    scanf("%*c"); //per pulire l'input;

    }

    return 0;
}

int inserisci(rubrica *r, char *nome, char *numero){
    contatto *p;
    if(r->num_inseriti==MAX_NUM_CONTATTI){
        printf("Rubrica piena");
        return -1;
    }
    p=&r->db[r->num_inseriti];

    strcpy(p->nome, nome);
    strcpy(p->numero, numero);
    p->id=r->num_inseriti;
    r->num_inseriti++;
    return 0;
}

char* trova_numero_da_nome(rubrica *r, char *nome){
    int i;
    contatto *p;
    for(i=0; i<MAX_NUM_CONTATTI; i++){
        if(i==r->num_inseriti)
            break;
        p=&r->db[i];

        if(strcmp(p->nome, nome)==0)
            return p->numero;
    }
    return NULL;
}

void stampa_rubrica(rubrica *r){
    int i;
    contatto *p;

    printf("\nStampa rubrica: %d contatti\n", r->num_inseriti);

    for(i=0; i<MAX_NUM_CONTATTI; i++){
        if(i==r->num_inseriti)
            break;
        p=&r->db[i];

        printf("%s, %s\n", p->nome, p->numero);
    }
}
