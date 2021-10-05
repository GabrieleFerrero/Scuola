# data una lista di numeri interi fornita dall'utente, scrivere il bubble sort che la riordini

lista=[]  #definizione lista
valore_acquisito=0
while(int(valore_acquisito)>=0):
    valore_acquisito=input("inserisci un numero: ")  #acquisisco valore 
    lista.append(valore_acquisito)   #salvo il valore dentro la lista

print("i numeri acquisiti sono: ", lista)

lunghezza = len(lista)
indice=0
cambiamenti=1
while(cambiamenti!=0):   #quando non ci sono più cambiamenti vorra dire che i numeri sono stati riordinati e si puo uscire
    indice2=0
    cambiamenti=0
    for indice2 in range(0,lunghezza-1-1):   # facendo -1 vado ad escludere l'ultimo valore ovvero quello negativo e poi vado anche ad escludere il penultimo, in modo che poi non andra a verificarsi la situazione cosi lista[punultimo_elemento] > lista[ultimo_elemento]
        if(lista[indice2]>lista[indice2+1]):
            lista[indice2], lista[indice2+1] = lista[indice2+1], lista[indice2]
            cambiamenti+=1



print("i numeri riordinati sono: ",lista[0:lunghezza-1])