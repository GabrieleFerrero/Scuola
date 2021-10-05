# fare una funzione che permette di fare muovere la tartaruga come vuoi

import turtle
from turtle import width

altezza=500
larghezza=500

turtle.screensize(altezza, larghezza)

coordinata_x=0
coordinata_y=0
movimento=20

turtle.goto(coordinata_x, coordinata_y)
turtle.clear()

#la turtle crea un campo con coordinate dei vertici ([-400,400] ; [400,400] ; [400,-400] ; [-400,-400])
#immaginando un quadrato che ha come vertici come A,B,C,D
#dove A è il vertice in alto a sinistra, B è il vertice in alto a destra, C è il vertice in basso a destra, D è il vertice in basso a sinistra

def up():   #funzione per permettere un movimento verso il basso
    global coordinata_y
    global coordinata_x
    global movimento
    if(coordinata_y+movimento>altezza/2):  #verfico che se vado su ancora di un movimento andrei fuori dal bordo se si stampo errore
        print("errore")
    else:   #altrimenti aumento la coordinata di un movimento e poi faccio andare la turtle alle nuove coordinate
        coordinata_y+=movimento
        print("sù")
        turtle.goto(coordinata_x, coordinata_y)
    
    

def down():
    global coordinata_y
    global coordinata_x
    global movimento
    if(coordinata_y-movimento<-(altezza/2)):
        print("errore")
    else:
        coordinata_y-=movimento
        print("giù")
        turtle.goto(coordinata_x, coordinata_y)

def left():
    global coordinata_y
    global coordinata_x
    global movimento
    if(coordinata_x-movimento<-(larghezza/2)):
        print("errore")
    else:
        coordinata_x-=movimento
        print("sinistra")
        turtle.goto(coordinata_x, coordinata_y)

def right():
    global coordinata_y
    global coordinata_x
    global movimento
    if(coordinata_x+movimento>larghezza/2):
        print("errore")
    else:
        coordinata_x+=movimento
        print("destra")
        turtle.goto(coordinata_x, coordinata_y)



turtle.listen()   #si mette in ascolto di pressioni di tasti
turtle.onkey(up, "Up")   
turtle.onkey(down, "Down")  
turtle.onkey(left, "Left")   
turtle.onkey(right, "Right")   

turtle.mainloop()
