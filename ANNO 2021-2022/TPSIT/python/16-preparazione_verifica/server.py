from flask import Flask, jsonify, request
import sqlite3
from pathlib import Path


dir_path = str(Path(__file__).parent.resolve())

app = Flask(__name__)
app.config["DEBUG"] = True


@app.route("/api/v1/svolgi_operazione", methods=["GET"])
def svolgi_operazione():

    errore = 1
    dati = None


    if "id" in request.args:
        id = int(request.args["id"])

        con = sqlite3.connect(f'{dir_path}/operations.db')
        cur = con.cursor()

        # verifica id

        ris = cur.execute(f'SELECT id FROM client_ammessi WHERE id = {id}').fetchall()
        if len(ris) > 0:
            # client ammesso
            errore = 0

            if 'risultato' in request.args and 'id_operazione' in request.args:
                # salvo risultato
                risultato = request.args["risultato"]
                id_operazione = int(request.args['id_operazione'])

                cur.execute(f'INSERT INTO risultati_operazioni (id_operazione, id_client) VALUES ({id_operazione}, {id})')
                con.commit()
                cur.execute(f'UPDATE operazioni_matematiche SET risultato = \'{risultato}\' WHERE id = {id_operazione}')
                con.commit()

                dati = 'OK'


            else:
                # assegno operazione
                ris = cur.execute(f'SELECT id, operazione FROM operazioni_matematiche WHERE risultato IS NULL LIMIT 1').fetchall()


                if len(ris) > 0:
                    id_operazione = ris[0][0]
                    operazione = ris[0][1]
                    dati = {'id_operazione': id_operazione, 'operazione':operazione}
                else:
                    dati = 'fine'
        
            
        con.close()


    return jsonify({'errore': errore, 'dati': dati})


app.run()