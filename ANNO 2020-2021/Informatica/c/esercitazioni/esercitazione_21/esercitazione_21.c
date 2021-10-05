/*
Calcolare la somma degli elementi di posizione pari e quelli di posizione dispari di un vettore
*/

#include <stdgl.h>

typedef struct s_variabile{
    int numero_di_numeri_acquisiti;  //viene utilizzata solo nella prima struct
    int numero;   //dove adrò a salvare il numero acquisito
    struct s_variabile *puntatore_alla_prossima_variabile;   //puntatore di tipo struct s_variabile * 
}variabile;

void acquisizioneVettore(variabile *puntatore_alla_prima_variabile);   //serve all'acquisizione dei dati e alla creazione di aree di memoria dinamiche dove salvare il dato
void calcoloSomma(variabile *puntatore_alla_prima_variabile);    //calcolo della somma dei diversi numeri in baso alla posizione nell'array

int main(){
    
    variabile *puntatore_alla_prima_variabile;   //creazione di una variabile di tipo variabile* 
    puntatore_alla_prima_variabile=(variabile *)(malloc(sizeof(variabile)));   //e associazione per indirizzo ad un area di memoria di grandezza variabile

    acquisizioneVettore(puntatore_alla_prima_variabile);   //esecuzione funzione per acquisire e salvare numeri

    calcoloSomma(puntatore_alla_prima_variabile);    //esecuzione funzione per fare la somma dei numeri in base alla posizione di acquisizione

    free(puntatore_alla_prima_variabile);   //liberazione della memoria occupata

    return 0;    
}

void acquisizioneVettore(variabile *puntatore_alla_prima_variabile){
    variabile *numero_acquisito;   //creazione di una variabile di tipo variabile, servirà per salvare l'indirizzo della struct su cui si vogliono fare operazioni
    numero_acquisito=puntatore_alla_prima_variabile;   //inizializzazione al inidiizzo della prima locazione di memoria

    int i=0;

    for(puntatore_alla_prima_variabile->numero_di_numeri_acquisiti=0; numero_acquisito->numero!=-9;puntatore_alla_prima_variabile->numero_di_numeri_acquisiti++){ //for per acquisizione dei numeri finche non si inserisce il numero -9
        scanfInt("inserire numero [per smettere di acquisire numeri digitare -9]: ", &(numero_acquisito->numero));   //acquisizione numero e salvataggio dentro numero_acquisito->numero
        if(numero_acquisito->numero==-9){   //se il numero acquisito è uguale a -9 non faccio niente

        }else{  //altrimenti se è diverso creo una nuova locazione di memoria e associo l'indirizzo di essa alla valore di numero_acquisito->puntatore_alla_prossima_struttura
            numero_acquisito->puntatore_alla_prossima_variabile=(variabile *)(malloc(sizeof(variabile)));
            numero_acquisito=numero_acquisito->puntatore_alla_prossima_variabile;  //dopo di che associo l'indirizzo della variabile numero_acquisito all'indirizzo della nuova locazione di memoria
        }
    }
    (puntatore_alla_prima_variabile->numero_di_numeri_acquisiti)--;    //in seguito decremento di uno il conteggio delle aree di memoria perchè l'ultima contiene -9
}

void calcoloSomma(variabile *puntatore_alla_prima_variabile){
    variabile *numero_acquisito;   //creazione di una variabile di tipo variabile, servirà per salvare l'indirizzo della struct su cui si vogliono fare operazioni
    numero_acquisito=puntatore_alla_prima_variabile;   //inizializzazione al inidiizzo della prima locazione di memoria

    int somma_posizione_pari=0;
    int somma_posizione_dispari=0;

    for(int i=0; i<puntatore_alla_prima_variabile->numero_di_numeri_acquisiti; i++){   //for per andare a sommare i numeri in posizione pari tra di loro e quelli in posizione dispari tra di loro fino a quando i non si arriva al numero di numeri acquisiti 
        if(i%2==0){  //se il resto di i/2 è uguale a 0 vuol dire che è una posizione pari, e si andrà a sommare alla variabile somma_posizione_pari il valore del numero che ce in quella posizione
            somma_posizione_pari=somma_posizione_pari+(numero_acquisito->numero);
        }else{ //stessa cosa per i numeri dispari
            somma_posizione_dispari=somma_posizione_dispari+(numero_acquisito->numero);
        }
        numero_acquisito=numero_acquisito->puntatore_alla_prossima_variabile;   //assocciamento indirizzo della variabile successiva alla variabile attuale
    }

    printf("la somma dei numeri di posizione pari è %d\n", somma_posizione_pari);
    printf("la somma dei numeri di posizione dispari è %d\n\n", somma_posizione_dispari);
}