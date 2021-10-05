/*
Scrivere un programma C che definisca la struttura Data con i campi giorno,
mese e anno e quindi la struttura Persona composta da nome, cognome e data di nascita.
Si richiedano i dati di n persone e una data e si stampino tutte le persone nate in quella data
*/

#include <stdgl.h>

#define max_caratteri_nome 100
#define max_caratteri_cognome 100

typedef struct s_data{
    int giorno;
    int mese;
    int anno;
}data;

typedef struct s_persona{
    char nome[max_caratteri_nome];
    char cognome[max_caratteri_cognome];
    data data_nascita;
}persona;

void acquisizioneNumeroPersone(int *n);
void acquisizioneDatiPersone(int *n, persona *uomo);
void acquisizioneDataDiConfronto(data *data_di_confronto);
void trovarePersoneConLaStessaDataAcquisita(data *data_di_confronto, int *n, persona *uomo);

int main(){

    int n=0;
    persona *uomo;
    data *data_di_confronto;

    acquisizioneNumeroPersone(&n);

    uomo=(persona*)(malloc(sizeof(persona)*n));

    acquisizioneDatiPersone(&n, uomo);

    acquisizioneDataDiConfronto(data_di_confronto);

    trovarePersoneConLaStessaDataAcquisita(data_di_confronto, &n, uomo);

    return 0;
}

void acquisizioneNumeroPersone(int *n){
    scanfInt("quante persone vuoi memorizzare: ", n);
}

void acquisizioneDatiPersone(int *n, persona *uomo){
    for(int i=0; i<*n; i++){
        printf("- Inserire i dati della persona n°%d\n", i);
        scanf("%*c");
        scanfString("inserisci il nome: ", ((uomo+i)->nome));
        scanfString("inserisci il cognome: ", ((uomo+i)->cognome));
        scanfInt("inserire giorno di nascita: ", &((uomo+i)->data_nascita.giorno));
        scanfInt("inserire mese di nascita: ", &((uomo+i)->data_nascita.mese));
        scanfInt("inserire anno di nascita: ", &((uomo+i)->data_nascita.anno));
        printf("\n");
    }
}

void acquisizioneDataDiConfronto(data *data_di_confronto){
    bool verifica=true;

    printf("inserire data di confronto:\n");
    while(verifica==true){   //finche la variabile è uguale a true vuol dire che la data inserita è sbagliata
    scanfInt("inserire giorno di nascita: ", &(data_di_confronto->giorno));
    scanfInt("inserire mese di nascita: ", &(data_di_confronto->mese));
    scanfInt("inserire anno di nascita: ", &(data_di_confronto->anno));
    printf("\n");
    if(((data_di_confronto->giorno>=1) && (data_di_confronto->giorno<=31)) &&
       ((data_di_confronto->mese>=1) && (data_di_confronto->mese<=12)) &&
       ((data_di_confronto->anno>=0) && (data_di_confronto->anno<=2020)))
       {
           verifica=false;
       }else{
           printf("inserire una data corretta!!!\n");
       }
    }
}

void trovarePersoneConLaStessaDataAcquisita(data *data_di_confronto, int *n, persona *uomo){
    bool verifica=true;
    int somma_di_confronto=0;
    somma_di_confronto=(data_di_confronto->anno)*1000000+(data_di_confronto->mese)*1000+(data_di_confronto->giorno);   //creare un numero univoco con la data di confronto

    for(int i=0; i<*n; i++){
        if(somma_di_confronto==((uomo+i)->data_nascita.anno)*1000000+((uomo+i)->data_nascita.mese)*1000+((uomo+i)->data_nascita.giorno)){  //comparo il numero univoco con un altro numero univoco generato dalla data delle persone
        printf("la persona %s %s è nata il giorno %d/%d/%d\n", (uomo+i)->cognome, (uomo+i)->nome, (uomo+i)->data_nascita.giorno, (uomo+i)->data_nascita.mese, (uomo+i)->data_nascita.anno);
        verifica=false;
        }else{

        }
    }
    if(verifica==true){
        printf("nessuna persona è stata trovata con la data di riferimento inserita\n\n");
    }
}

