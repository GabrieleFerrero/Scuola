/*

Run Length Encoding
Implementare un programma in C che realizzi la cosiddetta run-length encoding
e la sua operazione inversa di decoding.
La run length encoding (RLE) è una semplice forma di algoritmo di
compressione/decompressione dei dati (simile allo zip) nella quale elementi
consecutivi uguali sono sostituiti con un solo valore dell’elemento preceduto dal
numero di occorrenze consecutive di quell’elemento.
Il programma in C deve realizzare run-length encoding e decoding sulle stringhe.
NOTA: le stringhe non devono contenere numeri!
Un esempio di encoding:
"WWWWWWWWWWWWBWWWWWWWWWWWWBBBWWWWWWWWWWWWWWW
WWWWWWWWWB"
-> "12WB12W3B24WB"
Un altro esempio di encoding:
"AABCCCDEEEE" -> "2AB3CD4E
e il corrispondente decoding:
"2AB3CD4E" -> "AABCCCDEEEE"
Il programma deve chiedere all’utente se vuole fare decoding o encoding e in seguito
richiedere all’’utente la stringa di cui fare decoding o encoding e poi stampare il
risultato della stringa codificata o decodificata.
Caricare il programma sul proprio repository Github entro la fine della lezione. Le
consegne non effettuate saranno valutate negativamente.

*/



#include <stdlib.h>
#include <stdio.h>

#define max_lettere 100

char conversione_int_char(int var);
int conversione_char_int(char var);

int main(){

    int numero_lettere_stringa=0;
    int cella_array_zippato_salvataggio_ultimo_dato=0;
    int var_temp=0, p=0, i=0;
    int cella_array_salvataggio_ultimo_dato = 0;
    char stringa[max_lettere];
    char stringa_zippata[max_lettere];
    char scelta_menu;

    while(1==1){
    
    i=0;
    var_temp=0;
    p=0;
    cella_array_salvataggio_ultimo_dato=0;
    numero_lettere_stringa=0;
    cella_array_zippato_salvataggio_ultimo_dato=0;
    
    printf("MENÙ:\n\n- digita il numero '1' per codificare una stringa a tuo piacimento\n- digita il numero '2' per decodificare una stringa a tuo piacimento\n- digita il numero '3' per uscire dal programma\n\n[non si possono inserire spazi o numeri]\n\ninserire dato: ");
    scanf("%c", &scelta_menu);
    printf("\n");
    switch (scelta_menu){

    case '1':     // encoding

    printf("inserisci la stringa che vuoi codificare: ");
    scanf("%s", stringa);
    printf("\n");

    for(int k=0; stringa[k]!='\0'; k++){   //for per capire la lunghezza della stringa
        numero_lettere_stringa++;
    }

        while(cella_array_salvataggio_ultimo_dato<numero_lettere_stringa){   // while per il coding della stringa

        i=cella_array_salvataggio_ultimo_dato;
        
        for(p=cella_array_salvataggio_ultimo_dato; stringa[p]==stringa[i]; p++){
            stringa_zippata[cella_array_zippato_salvataggio_ultimo_dato] = conversione_int_char(var_temp++);   //da controllare perché non si puo salvare intero in char
            stringa_zippata[cella_array_zippato_salvataggio_ultimo_dato+1] = stringa[i];
            
        }

        stringa_zippata[cella_array_zippato_salvataggio_ultimo_dato] = conversione_int_char(var_temp++);

        cella_array_salvataggio_ultimo_dato=p;
        var_temp=0;
        cella_array_zippato_salvataggio_ultimo_dato = cella_array_zippato_salvataggio_ultimo_dato+2;

    }


    numero_lettere_stringa=0;
    for(int k=0; stringa_zippata[k]!='\0'; k++){   //for per capire la lunghezza della stringa zippata
        numero_lettere_stringa++;
    }


    for(int h=0; h<numero_lettere_stringa; h++){    //stampaggio dell'array codificato
        printf("%c", stringa_zippata[h]);
    }

    printf("\n\n");

        break;

    case '2':   //decoding

    printf("inserisci la stringa che vuoi decodificare: ");
    scanf("%s", stringa_zippata);
    printf("\n");

    for(int k=0; stringa_zippata[k]!='\0'; k++){   //for per capire la lunghezza della stringa
        numero_lettere_stringa++;
    }

    for(int i=0; i<numero_lettere_stringa; i=i+2){   //for per decodificare
    p=0;
        while(p<conversione_char_int(stringa_zippata[i])){
            printf("%c", stringa_zippata[i+1]);
            p++;
        }
    }

    printf("\n\n");

        break;

    case '3':   //uscita dal programma

    printf("exit...\n\n");
    return 0;

        break;

    default:    // char inserito non corretto
        printf("carattere inserito non valido!!!\n\n");
        break;
    }

    }
}

char conversione_int_char(int var){
    char valore_di_ritorno;

    switch (var)
    {
    case 0:
        valore_di_ritorno='0';
        break;
    case 1:
        valore_di_ritorno='1';
        break;
    case 2:
        valore_di_ritorno='2';
        break;
    case 3:
        valore_di_ritorno='3';
        break;
    case 4:
        valore_di_ritorno='4';
        break;
    case 5:
        valore_di_ritorno='5';
        break;
    case 6:
        valore_di_ritorno='6';
        break;
    case 7:
        valore_di_ritorno='7';
        break;
    case 8:
        valore_di_ritorno='8';
        break;
    case 9:
        valore_di_ritorno='9';
        break;
    default:
        valore_di_ritorno='#';
        break;
    }

    return valore_di_ritorno;
}

int conversione_char_int(char var){
    int valore_di_ritorno;

    switch (var)
    {
    case '0':
        valore_di_ritorno=0;
        break;
    case '1':
        valore_di_ritorno=1;
        break;
    case '2':
        valore_di_ritorno=2;
        break;
    case '3':
        valore_di_ritorno=3;
        break;
    case '4':
        valore_di_ritorno=4;
        break;
    case '5':
        valore_di_ritorno=5;
        break;
    case '6':
        valore_di_ritorno=6;
        break;
    case '7':
        valore_di_ritorno=7;
        break;
    case '8':
        valore_di_ritorno=8;
        break;
    case '9':
        valore_di_ritorno=9;
        break;
    default:
        valore_di_ritorno='#';
        break;
    }

    return valore_di_ritorno;
}