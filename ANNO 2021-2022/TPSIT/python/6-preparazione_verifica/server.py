# LIBRERIE #
from flask import Flask, render_template, jsonify, request, redirect, url_for
from time import sleep
import sqlite3
import datetime
import socket
from pathlib import Path
#-----------#

dir_path = str(Path(__file__).parent.resolve())
print(dir_path)

app = Flask(__name__)

@app.route('/', methods=['GET', 'POST'])
def index():
    if request.method == 'POST':
        dati = request.form['dati']

        print(dati)

        indirizzo_ip = dati.split("#")[0]
        porta_min = int(dati.split("#")[1])
        porta_max = int(dati.split("#")[2])

        lista_porte_aperte = []

        for porta in range(porta_min, porta_max+1):
            if check_porta(indirizzo_ip, porta):
                lista_porte_aperte.append(porta)

        
        con = sqlite3.connect(f'{dir_path}/db.db')
        cur = con.cursor()

        cur.execute(f"INSERT OR IGNORE INTO INDIRIZZI_IP (INDIRIZZO_IP) VALUES ('{indirizzo_ip}')")
        con.commit()

        cur.execute(f"SELECT INDIRIZZI_IP.ID FROM INDIRIZZI_IP WHERE INDIRIZZI_IP.INDIRIZZO_IP = '{indirizzo_ip}'")
        id = cur.fetchall()[0][0]

        cur.execute(f"INSERT INTO PORTE_APERTE (ID_INDIRIZZO_IP, LISTA_PORTE) VALUES ('{id}','{lista_porte_aperte}')")
        con.commit()
        con.close()


        # redirect("/fine")
        return redirect(url_for("fine"))

    else:
        return render_template("index.html")

@app.route('/fine')
def fine():
    return render_template("fine.html")


def check_porta(indirizzo, porta):
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.settimeout(1)
    result = sock.connect_ex((indirizzo, porta))
    sock.close()
    if result == 0:
        # aperta
        return True
    else:
        # chiusa
        return False



if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0')