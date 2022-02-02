# LIBRERIE #
from flask import Flask, render_template, jsonify, request, redirect, url_for
from time import sleep
import sqlite3
import datetime
import socket
import pandas as pd
from pathlib import Path
#-----------#

dir_path = str(Path(__file__).parent.resolve())
print(dir_path)

porte_servizi = pd.read_csv(f"{dir_path}/service-names-port-numbers.csv")

app = Flask(__name__)

@app.route('/', methods=['GET', 'POST'])
def index():
    if request.method == 'POST':

        tempo_iniziale = datetime.datetime.now()

        dati = request.form['dati']

        print(dati)

        indirizzo_ip = dati.split("#")[0]
        porta_min = int(dati.split("#")[1])
        porta_max = int(dati.split("#")[2])

        lista_porte = []

        for porta in range(porta_min, porta_max+1):
            if check_porta(indirizzo_ip, porta):
                lista_porte.append((porta, "ON"))
            else:
                lista_porte.append((porta, "OFF"))

        
        con = sqlite3.connect(f'{dir_path}/db.db')
        cur = con.cursor()

        cur.execute(f"INSERT OR IGNORE INTO INDIRIZZI_IP (INDIRIZZO_IP) VALUES ('{indirizzo_ip}')")
        con.commit()

        cur.execute(f"SELECT INDIRIZZI_IP.ID FROM INDIRIZZI_IP WHERE INDIRIZZI_IP.INDIRIZZO_IP = '{indirizzo_ip}'")
        id = cur.fetchall()[0][0]

        # CREAZIONE HTML
        page =  f"""<!DOCTYPE html>
                    <html lang="en">
                    <head>
                        <meta charset="UTF-8">
                        <meta http-equiv="X-UA-Compatible" content="IE=edge">
                        <meta name="viewport" content="width=device-width, initial-scale=1.0">
                        <title>Risultato</title>
                    </head>
                    <body>
                        Scansione terminata in {datetime.datetime.now()-tempo_iniziale}
                        <table border="1">
                        <tr>
                            <th>PORTA</th><th>STATO</th><th>SERVIZIO</th>
                        </tr>"""


        for porta_info in lista_porte:
            try:
                servizio = (porte_servizi[porte_servizi["Port Number"] == f"{porta_info[0]}"]["Service Name"].values)[0]
            except:
                servizio = "assente"
            page += f"""<tr>
                            <td>{porta_info[0]}</td><td>{porta_info[1]}</td><td>{servizio}</td>
                        </tr>"""

            cur.execute(f"INSERT INTO PORTE (ID_INDIRIZZO_IP, PORTA, STATO, SERVIZIO) VALUES ({id},{porta_info[0]},'{porta_info[1]}','{servizio}')")
        con.commit()
        con.close()

        page += """</table>
                    </body>
                    </html>"""


        with open(f'{dir_path}/templates/fine.html', 'w') as f:
            f.write(page)

        


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