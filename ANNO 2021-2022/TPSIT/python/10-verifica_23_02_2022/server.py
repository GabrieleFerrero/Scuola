# LIBRERIE #
from flask import Flask, render_template, request, redirect, url_for, make_response
import sqlite3
import datetime
from pathlib import Path
import uuid
from sympy import *
#-----------#
# LOGIN #
token = str(uuid.uuid1())
print(f"token: {token}")
#-----------#


dir_path = str(Path(__file__).parent.resolve())
print(f"dir_path: {dir_path}")


app = Flask(__name__)

def validate(username, password):
    completion = False
    con = sqlite3.connect(f'{dir_path}/db.db')
    cur = con.cursor()
    cur.execute("SELECT * FROM USERS")
    rows = cur.fetchall()
    con.close()
    for row in rows:
        dbUser = row[1]
        dbPass = row[2]
        if dbUser==username:
            completion=check_password(dbPass, password)
    return completion

def check_password(hashed_password, user_password):
    return hashed_password == user_password


@app.route('/', methods=['GET', 'POST'])
def login():
    error = None
    if request.method == 'POST':
        username = request.form['username']
        password = request.form['password']
        completion = validate(username, password)
        if completion == False:
            error = 'Invalid Credentials. Please try again.'
        else:
            # login corretto

            # ----------------
            data_orario = str(datetime.datetime.now())
            con = sqlite3.connect(f'{dir_path}/db.db')
            cur = con.cursor()

            # Insert a row of data
            cur.execute(f"SELECT ID FROM USERS WHERE USERNAME = '{username}'") # trovo id utente che ha fatto l'accesso
            id_utente = cur.fetchall()[0][0]
            cur.execute(f"INSERT INTO LOG_ACCESSI (ID_UTENTE, DATA_ORA) VALUES ({id_utente}, '{data_orario}')")

            # Save (commit) the changes
            con.commit()
            con.close()
            # ---------------

            resp = make_response(redirect(url_for('index')))
            resp.set_cookie('username', username)
            return resp

    return render_template('login.html', error=error)


@app.route(f'/registrazione', methods = ['GET', 'POST'])
def registrazione():

    error = None

    if request.method == 'POST':

        username = request.form["username"]
        password = request.form["password"]
        conferma_password = request.form["conferma_password"]

        data_orario = str(datetime.datetime.now())
        con = sqlite3.connect(f'{dir_path}/db.db')
        cur = con.cursor()

        cur.execute(f"SELECT ID FROM USERS WHERE USERNAME = '{username}'") # trovo id utente che ha fatto l'accesso
        presenza_utente = cur.fetchall()

        if len(presenza_utente) == 0:
            # utente non ancora registrato
            if password != "":
                if password == conferma_password:
                    cur.execute(f"INSERT INTO USERS (USERNAME, PASSWORD, DATA_ORA_CREAZIONE_USER) VALUES ('{username}', '{password}', '{data_orario}')")
                    error = "REGISTRAZIONE EFFETTUATA CON SUCCESSO"
                else:
                    error = "LE DUE PASSWORD NON COINCIDONO"
            else:
                error = "PASSWORD NON INSERITA"
        else:
            error = "NOME UTENTE GIÀ UTILIZZATO"

        # Save (commit) the changes
        con.commit()
        con.close()
        # ---------------

    return render_template('registrazione.html', error=error)


@app.route(f'/{token}', methods = ['GET', 'POST'])
def index():
    username = request.cookies.get('username')

    contenuto_stato_randomico = None
    utente_stato_randomico = None

    if request.method == 'POST':
        if request.form["pulsante"] == "CONFERMA":
            cont_s = request.form["cont_s"][0:80]
            # ----------------
            data_orario = str(datetime.datetime.now())
            con = sqlite3.connect(f'{dir_path}/db.db')
            cur = con.cursor()

            # Insert a row of data
            cur.execute(f"SELECT ID FROM USERS WHERE USERNAME = '{username}'") # trovo id utente che ha fatto l'accesso
            id_utente = cur.fetchall()[0][0]
        
            cur.execute(f"INSERT INTO STATI (ID_UTENTE, DATA_ORA, CONTENUTO_STATO) VALUES ({id_utente}, '{data_orario}', '{cont_s}')")        
            
            # Save (commit) the changes
            con.commit()
            con.close()
            # ---------------


    # trova stato
    con = sqlite3.connect(f'{dir_path}/db.db')
    cur = con.cursor()

    cur.execute(f"SELECT * FROM STATI, USERS WHERE USERS.USERNAME != '{username}' and USERS.ID = STATI.ID_UTENTE ORDER BY random() LIMIT 1") # estrazione stato in modo randomico senza che esco uno stato dell'utente loggato
    stato = cur.fetchall()[0]
    
    contenuto_stato_randomico = stato[3]

    cur.execute(f"SELECT USERNAME FROM USERS WHERE USERS.ID = {stato[1]}") # estrazione nome utente dello stato randomico
    utente_stato_randomico = cur.fetchall()[0][0]

    con.close()

    return render_template('index.html', stato_randomico=[contenuto_stato_randomico, utente_stato_randomico])



if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0')