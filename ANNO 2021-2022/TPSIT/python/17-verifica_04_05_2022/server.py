from flask import Flask, jsonify, request
import sqlite3
from pathlib import Path


dir_path = str(Path(__file__).parent.resolve())

app = Flask(__name__)
app.config["DEBUG"] = True


@app.route("/api/v1/get_id_grandezza", methods=["GET"])
def get_id_grandezza():
    """
    End poin al quale si passa un parametro che contiene il nome della grandezza: nome
    """

    errore = "Nessun errore"
    dati = {}


    if "nome" in request.args:
        nome = request.args["nome"].lower()

        con = sqlite3.connect(f'{dir_path}/meteo_db.db')
        cur = con.cursor()

        ris = cur.execute(f'SELECT id_misura FROM grandezze WHERE grandezza_misurata = ?', [nome]).fetchall()
        con.close()

        if len(ris) > 0:
            id = ris[0][0]
            dati["id"] = id

        else: errore = "Nome non trovato all'interno del db"

    else:
        errore = "Richiesta mal formulata"


    return jsonify({'errore': errore, 'dati': dati})


@app.route("/api/v1/get_id_stazione", methods=["GET"])
def get_id_stazione():
    """
    End poin al quale si passa un parametro che contiene il nome della stazione: nome
    """

    errore = "Nessun errore"
    dati = {}


    if "nome" in request.args:
        nome = request.args["nome"].lower()

        con = sqlite3.connect(f'{dir_path}/meteo_db.db')
        cur = con.cursor()

        ris = cur.execute('SELECT id_stazione FROM stazioni WHERE nome = ?', [nome]).fetchall()
        con.close()

        if len(ris) > 0:
            id = ris[0][0]
            dati["id"] = id

        else: errore = "Nome non trovato all'interno del db"

    else:
        errore = "Richiesta mal formulata"


    return jsonify({'errore': errore, 'dati': dati})

@app.route("/api/v1/upload_misurazione", methods=["GET"])
def upload_misurazione():
    """
    End poin al quale si passano 3 parametri: grandezza, id_grandezza, id_stazione, data_ora
    """

    errore = "Nessun errore"
    dati = {}


    if "misurazione" in request.args and "id_grandezza" in request.args and "id_stazione" in request.args and "data_ora" in request.args:

        try:misurazione = float(request.args["misurazione"])
        except:
            errore = "Misurazione non è un float"
            print(request.args["misurazione"])

        try:id_grandezza = int(request.args["id_grandezza"])
        except:
            errore = "Id_grandezza non è un int"
            print(request.args["id_grandezza"])

        try:id_stazione = int(request.args["id_stazione"])
        except:
            errore = "Id_stazione non è un int"
            print(request.args["id_stazione"])
            
        data_ora = request.args["data_ora"]


        if errore == "Nessun errore":
            con = sqlite3.connect(f'{dir_path}/meteo_db.db')
            cur = con.cursor()
            cur.execute('INSERT INTO misurazioni (id_stazione, id_grandezza, data_ora, valore) VALUES (?, ?, ?, ?)', [id_stazione, id_grandezza, data_ora, misurazione])
            con.commit()
            con.close()

    else:
        errore = "Richiesta mal formulata"

    return jsonify({'errore': errore, 'dati': dati})



@app.route("/api/v1/get_informazioni", methods=["GET"])
def get_informazioni():
    """
    End poin al quale si passano 2 parametri: id_stazione, id_grandezza
    """

    errore = "Nessun errore"
    dati = {}


    if "id_stazione" in request.args and "id_grandezza" in request.args:
        try:id_grandezza = int(request.args["id_grandezza"])
        except:
            errore = "Id_grandezza non è un int"
            print(request.args["id_grandezza"])

        try:id_stazione = int(request.args["id_stazione"])
        except:
            errore = "Id_stazione non è un int"
            print(request.args["id_stazione"])


        if errore == "Nessun errore":
            con = sqlite3.connect(f'{dir_path}/meteo_db.db')
            cur = con.cursor()

            ris = cur.execute('SELECT MIN(valore), MAX(valore), AVG(valore) FROM misurazioni WHERE id_stazione = ? AND id_grandezza = ?', [id_stazione, id_grandezza]).fetchall()
            con.close()

            if len(ris) > 0:
                min = ris[0][0]
                max = ris[0][1]
                media = ris[0][2]

                if min == None or max == None or media == None:
                    errore = "Parametri non trovati o nessun dato ancora caricato"

                dati["min"] = min
                dati["max"] = max
                dati["media"] = media

            else: errore = "Parametri non trovati o nessun dato ancora caricato"

    else:
        errore = "Richiesta mal formulata"


    return jsonify({'errore': errore, 'dati': dati})


def main():
    app.run()

if __name__ == "__main__":
    main()