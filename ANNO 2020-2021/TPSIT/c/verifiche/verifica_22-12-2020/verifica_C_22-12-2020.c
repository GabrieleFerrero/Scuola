/*

*/

#include <stdgl.h>

typedef struct s_prova{
    int valore;
    struct  s_prova* next;
}prova;

int primo_Dispari(prova* head);
prova* eliminaElementi(prova* head, int n);
prova* push(prova* lista, int x);
int lunghezza(prova* head);

int main(){
    prova *prova_1, *prova_2, *prova_3;


    prova_1 = (prova*)malloc(sizeof(prova));
    prova_1->valore=1;
    prova_2 = (prova*)malloc(sizeof(prova));
    prova_1->next=prova_2;
    prova_2->valore=4;
    prova_3 = (prova*)malloc(sizeof(prova));
    prova_2->next=prova_3;
    prova_3->valore=5;
    prova_3->next=NULL;

    //esercizio 1
    printf("%d\n", primo_Dispari(prova_1));

    //esercizio 2
    printf("%p\t%p\t%p\n", prova_1,prova_2,prova_3);
    printf("%p\n", eliminaElementi(prova_1, 2));


    //esercizio 3

    prova* var;
    prova* new;
    var = prova_1;

    int lung = lunghezza(prova_1);

    int array[lung];

    for(int i=0; var!=NULL; i++){
        array[i]=var->valore;
        var=var->next;
    }
    var =new;
    for(int i=0; i<lung; i++){
        var=push(var, array[i]);
    }

    return 0;
}


int primo_Dispari(prova* head){
    if(head==NULL){
        printf("la lista è vuota\n");
    }else{
        if((head->valore)%2!=0){
            return head->valore;
        }else{
            primo_Dispari(head->next);
        }
    }
}


prova* eliminaElementi(prova* head, int n){
    int cont = 0;
    while(head!=NULL && cont<n){
        cont++;
        head=head->next;
    }
    if(cont!=n){
        printf("numero inserito non corretto");
    }else{
        return head;
    }
}


int lunghezza(prova* head){
    if(head==NULL){
        return 0;
    }else{
        return 1 + lunghezza(head->next);
    }
}