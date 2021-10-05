/*
Nel file instagram.csv trovate alcuni dati esportati dal vostro account Instagram.
Ogni riga del file corrisponde ad un post pubblicato nel 2020 e su ogni riga trovate in ordine: mese, giorno del mese,
identificativo del post, numero di like.
Scrivere un programma in C, che faccia uso della allocazione dinamica e della aritmetica dei 
puntatori (requisiti obbligatori): il programma deve richiedere all'utente il nome di un mese e poi deve fornire in 
output il numero di post di quel mese ed il numero totale di like ricevuto durante quel mese.

NOTA: non è possibile accedere agli elementi degli array utilizzando le parentesi [ ].

CONSEGNARE SOLTANTO IL FILE SORGENTE .C ADEGUATAMENTE COMMENTATO. IL FILE .C DEVE AVERE NOME: COGNOME_NOME.c
*/

#include <stdgl.h>

#define MAX_CARATTERI_PER_RIGA 200
#define MAX_CARATTERI_PER_MESE 300

typedef struct s_post{
    char* mese;
    int giorno;
    int id_post;
    int numero_like;
    struct s_post *puntatore_al_prossimo_post;
    
}post;

FILE* aperturaFile();
int acquisizioneDati(FILE* file_csv,post* prima_foto);
int numeroPostPubblicati(post* prima_foto, int n_foto, char* mese);
int numeroLikeRicevuti(post* prima_foto, int n_foto, char* mese);

int main(){

    post* prima_foto = (post*)malloc(sizeof(post));

    FILE* file_csv = aperturaFile();
    
    int n_post = acquisizioneDati(file_csv, prima_foto);

    char mese[MAX_CARATTERI_PER_MESE];
    scanfString("inserire il mese di cui si vuole ottenere informazioni: ", mese);

    printf("il numero di post pubblicati nel mese di %s è %d\n", mese, numeroPostPubblicati(prima_foto, n_post, mese));
    printf("il numero di like ricevuti nel mese di %s è %d\n", mese, numeroLikeRicevuti(prima_foto, n_post, mese));

    fclose(file_csv);
    free(prima_foto);

    return 0;
}

FILE* aperturaFile(){   //funzione per lettura del file
    FILE* file_csv = fopen("instagram.csv", "r");

    if(file_csv==NULL){  //se non riesce a leggerlo chiudo il file
        fclose(file_csv);
    }
    return file_csv;
}

int acquisizioneDati(FILE* file_csv,post* prima_foto){
    
    char riga[MAX_CARATTERI_PER_RIGA];

    post* foto;
    foto=prima_foto;

    char* pezzo_di_riga;

    int i=0;

    fgets(riga, MAX_CARATTERI_PER_RIGA, file_csv);

    for(i=0; fgets(riga, MAX_CARATTERI_PER_RIGA, file_csv)!=NULL; i++){  //for che va avanti fino a che non finisce di leggere il file.csv

        /*memorizzo mese*/
        pezzo_di_riga=strtok(riga, ",");
        foto->mese=strdup(pezzo_di_riga);

        /*memorizzo giorno*/
        pezzo_di_riga=strtok(NULL, ",");
        foto->giorno=ctoi(pezzo_di_riga);

        /*memorizzo id_post*/
        pezzo_di_riga=strtok(NULL, ",");
        foto->id_post=ctoi(pezzo_di_riga);

        /*memorizzo like_post*/
        pezzo_di_riga=strtok(NULL, ",");
        foto->numero_like=ctoi(pezzo_di_riga);
        
        foto->puntatore_al_prossimo_post=(post*)malloc(sizeof(post));   //creo nuova strutta di tipo post
        foto=foto->puntatore_al_prossimo_post;   //punto alla prossima struttura
    }
    return i;
}

int numeroPostPubblicati(post* prima_foto, int n_foto, char* mese){
    int numero_di_post_pubblicati=0;

    post* foto;
    foto=prima_foto;

    for(int i=0; i<n_foto; i++){   //scorro le diverse strutture e guardo quelle con lo stesso mese attraverso l'if
        if(/*mese==foto->mese*/){   //se il mese inserito dall'utente è uguale a quello in struttura
            numero_di_post_pubblicati++;   //incremento una variabile del numero di post
        }

        foto=foto->puntatore_al_prossimo_post; //punto alla prossima struttura
    }



    return numero_di_post_pubblicati;
}
int numeroLikeRicevuti(post* prima_foto, int n_foto, char* mese){
    int numero_di_like_ricevuti=0;

    post* foto;
    foto=prima_foto;

    for(int i=0; i<n_foto; i++){   //scorro le diverse strutture e guardo quelle con lo stesso mese attraverso l'if
        if(/*mese==foto->mese*/){  //se il mese inserito dall'utente è uguale a quello in struttura
            numero_di_like_ricevuti=numero_di_like_ricevuti+foto->numero_like;    //sommo i like al variabile di numeri di like ricevuti fino ad adesso
        }

        foto=foto->puntatore_al_prossimo_post;  //punto alla prossima struttura
    }

    return numero_di_like_ricevuti;
}