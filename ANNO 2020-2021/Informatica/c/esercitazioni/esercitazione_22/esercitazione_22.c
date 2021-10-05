/*
Raddoppiare le occorrenze delle vocali in una stringa (ciao->ciiaaoo) usare 2 stringhe
*/

#include <stdgl.h>

#define max_lunghezza_stringa 200
#define max_lunghezza_stringa_di_appoggio 400

void acquisizioneStringa(char *stringa);
char* raddoppioVocali(char *stringa, char *stringa_di_appoggio);

int main(){

    char stringa[max_lunghezza_stringa];
    char stringa_di_appoggio[max_lunghezza_stringa_di_appoggio];

    acquisizioneStringa(stringa);

    printf("%s\n", stringa);

    printf("%s\n\n", raddoppioVocali(stringa, stringa_di_appoggio));

    return 0;
}

void acquisizioneStringa(char *stringa){
    scanfString("inserire la frase: ", stringa);   //acquisire stringa
}

char* raddoppioVocali(char *stringa, char *stringa_di_appoggio){
    int y=0;
    for(int i=0; *(stringa+i)!='\0'; i++){   //for per scorrere le celle dell'array acquisito e verificare la presenza di vocali
        switch (*(stringa+i)){
        case 'a':
        *(stringa_di_appoggio+y)=*(stringa+i);
        y++;
        *(stringa_di_appoggio+y)=*(stringa+i);
        y++;
        break;
        case 'e':
        *(stringa_di_appoggio+y)=*(stringa+i);
        y++;
        *(stringa_di_appoggio+y)=*(stringa+i);
        y++;
        break;
        case 'i':
        *(stringa_di_appoggio+y)=*(stringa+i);
        y++;
        *(stringa_di_appoggio+y)=*(stringa+i);
        y++;
        break;
        case 'o':
        *(stringa_di_appoggio+y)=*(stringa+i);
        y++;
        *(stringa_di_appoggio+y)=*(stringa+i);
        y++;
        break;
        case 'u':
        *(stringa_di_appoggio+y)=*(stringa+i);
        y++;
        *(stringa_di_appoggio+y)=*(stringa+i);
        y++;
        break;
        case 'A':
        *(stringa_di_appoggio+y)=*(stringa+i);
        y++;
        *(stringa_di_appoggio+y)=*(stringa+i);
        y++;
        break;
        case 'E':
        *(stringa_di_appoggio+y)=*(stringa+i);
        y++;
        *(stringa_di_appoggio+y)=*(stringa+i);
        y++;
        break;
        case 'I':
        *(stringa_di_appoggio+y)=*(stringa+i);
        y++;
        *(stringa_di_appoggio+y)=*(stringa+i);
        y++;
        break;
        case 'O':
        *(stringa_di_appoggio+y)=*(stringa+i);
        y++;
        *(stringa_di_appoggio+y)=*(stringa+i);
        y++;
        break;
        case 'U':
        *(stringa_di_appoggio+y)=*(stringa+i);
        y++;
        *(stringa_di_appoggio+y)=*(stringa+i);
        y++;
        break;
        default:
        *(stringa_di_appoggio+y)=*(stringa+i);
        y++;
        break;
        }
    }
    *(stringa_di_appoggio+y)='\0';   //inserire alla fine della stringa il terminatore di stringa \0
    return stringa_di_appoggio;
}