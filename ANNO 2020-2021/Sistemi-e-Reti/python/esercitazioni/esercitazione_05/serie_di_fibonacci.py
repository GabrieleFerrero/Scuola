"""
calcolo della serie di fibonacci
"""

def calcoloSerieDiFibonacci(n, serie):
    if(n>0):
        serie.append(serie[-1]+serie[-2])     
    else:
        return serie

    n-=1
    return calcoloSerieDiFibonacci(n,serie)


def main():
    serie = [1,1]
    n=int(input("Inserire il numero di numeri che si vuole ottenere della serie di fibonacci: "))
    n-=2
    serie = calcoloSerieDiFibonacci(n, serie)

    if(n==-1):
        print('1')
    else:
        print(serie)

if __name__ == "__main__":
    main()
