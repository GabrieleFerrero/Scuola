import string
import random

lettere=string.ascii_letters
codifica = {}
decodifica = {}
estratta=[]

def main():
    global estratta
    global decodifica
    global codifica
    condizione=True

    for _ in range(len(lettere)):
        estratta.append(False) 

    while(condizione==True):
        scelta=int(input("MENÙ:\n- digita '1' per cambiare codifica\n- digita '2' per codificare frase\n- digita '3' per decodificare frase\n- digita '4' per uscire dal programma\n\nScelta: "))
        if(scelta==1): 
            for i in range(len(lettere)):
                estratta[i]=False

            for i in lettere:
                codifica[i]= estrazioneLettera()  

            for chiave, elemento in codifica.items():
                decodifica[elemento]=chiave
                
        elif(scelta==2):
            codificata=""
            stringa = input("Inserire la frase da codificare: ")
            for i in stringa:
                codificata+=str(codifica[i])
            
            print("La frase codificata è "+ codificata)
        elif(scelta==3):
            decodificata=""
            stringa = input("Inserire la frase da decodificare: ")
            for i in stringa:
                decodificata+=str(decodifica[i])

            print("La frase decodificata è "+ decodificata)
        elif(scelta==4):
            print("EXIT...")
            condizione=False
        else:
            print("Carattere inserito non riconosciuto!!")



def estrazioneLettera():
    global estratta
    lettera=""
    condizione=True
    while(condizione==True):
        lettera=random.choice(lettere)
        cont=0
        while(lettere[cont]!=lettera):
            cont+=1

        if(estratta[cont]==False):
            estratta[cont]=True
            condizione=False
    
    return lettera



if __name__ == "__main__":
    main()