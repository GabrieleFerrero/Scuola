# fare un programma che disegni dei poligoni regolari

import turtle

win_height = 500
win_lenght = 500

disegno = turtle.Turtle()

turtle.screensize(win_height, win_lenght)

n_lati=input("inserisci il numero di lati di cui si vuole formare la figura: ")
while(n_lati<3):
    print("inserisci un numero di lati maggiore di 2")
    n_lati=input("inserisci il numero di lati di cui si vuole formare la figura: ")
        

lunghezza=input("inserisci la lunghezza del lato: ")
while(lunghezza<0):
    print("la lunghezza deve essere positiva")
    lunghezza=input("inserisci la lunghezza del lato: ")
        

def draw_poly(n_lati, lunghezza):   
    for i in range(n_lati):    
        disegno.home()      
        disegno.forward(lunghezza)       #disegna un lato 
        disegno.left(360/n_lati)      #ruota verso sinistra di un angolo 360/N oppure secondo me (180*(n_lati-2))/n_lati

draw_poly(n_lati, lunghezza)

turtle.mainloop()