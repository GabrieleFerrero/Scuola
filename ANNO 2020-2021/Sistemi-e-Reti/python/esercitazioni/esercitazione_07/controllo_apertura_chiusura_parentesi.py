def push_(pila, elemento):
    pila.append(elemento)

def pop_(pila):
    return pila.pop()

def main():
    sequenza_parentesi = input("Inserire un sequenza di parentesi: ")
    stack=[]
    giusto = True
    for i in sequenza_parentesi:
        if(i=="(" or i=="[" or i=="{"):
            push_(stack, i)
        elif(i==")" or i=="]" or i=="}"):
            x=pop_(stack)
            if((x=="(" and i==")") or (x=="[" and i=="]") or (x=="{" and i=="}")):
                pass
            else:
                giusto=False
        else:
            print("Carattere inserito non corretto")
            giusto=False

    if(giusto):
        print("Parentesi aperte e chiuse correttamente")
    else:
        print("Parentesi aperte e chiuse non correttamente")

if __name__ == "__main__":
    main()