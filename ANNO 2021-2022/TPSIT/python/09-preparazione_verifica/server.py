# LIBRERIE #
from flask import Flask, render_template, request, redirect, url_for, make_response
import sqlite3
import datetime
from pathlib import Path
from re import U
import uuid
from sympy import *
#-----------#
# LOGIN #
token = str(uuid.uuid1())
print(token)
#-----------#


dir_path = str(Path(__file__).parent.resolve())
print(dir_path)


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


@app.route(f'/{token}', methods = ['GET', 'POST'])
def index():
    username = request.cookies.get('username')
    risultato = None

    if request.method == 'POST':
        dict_dati = request.form.to_dict(flat=False) # conversione oggetto immutablemultidict a dict
        print(dict_dati)
        if "d_funzione" in dict_dati:
            # integrale definito

            # verifica estremi
            estremo_i = 0
            estremo_s = 0
            try:
                estremo_i = int(dict_dati["d_estremo_i"][0])
                estremo_s = int(dict_dati["d_estremo_s"][0])
            except:
                risultato = "ERRORE ESTREMI DI INTEGRAZIONE"
            
            # calcolo integrale
            try:
                funzione = dict_dati["d_funzione"][0]
                x,y = symbols('x y') 
                expr=eval(funzione)
                risultato = str(integrate(expr, (x, estremo_i, estremo_s)))
                save_log_operazioni(username=username, tipo_integrale="DEFINITO", risultato=risultato, funzione=funzione, estremo_i=estremo_i, estremo_s=estremo_s)
            except Exception as e:
                print(e)
                risultato = "ERRORE CALCOLO INTEGRALE DEFINITO"

        else:
            # integrale indefinito

            # calcolo integrale
            try:
                funzione = dict_dati["i_funzione"][0]
                print(funzione)
                x,y = symbols('x y') 
                expr=eval(funzione)
                risultato = str(integrate(expr, x))
                save_log_operazioni(username=username, tipo_integrale="INDEFINITO", risultato=risultato, funzione=funzione)
            except Exception as e:
                print(e)
                risultato = "ERRORE CALCOLO INTEGRALE INDEFINITO"

    return render_template('index.html', risultato=risultato)



def save_log_operazioni(username, tipo_integrale, risultato, funzione, estremo_i=None, estremo_s=None):
    # ----------------
    data_orario = str(datetime.datetime.now())
    con = sqlite3.connect(f'{dir_path}/db.db')
    cur = con.cursor()

    # Insert a row of data
    cur.execute(f"SELECT ID FROM USERS WHERE USERNAME = '{username}'") # trovo id utente che ha fatto l'accesso
    id_utente = cur.fetchall()[0][0]
    if estremo_i == None or estremo_s == None:
        cur.execute(f"INSERT INTO LOG_OPERAZIONI (ID_UTENTE, DATA_ORA, TIPO_INTEGRALE, FUNZIONE, RISULTATO) VALUES ({id_utente}, '{data_orario}', '{tipo_integrale}', '{funzione}', '{risultato}')")
    else:
        cur.execute(f"INSERT INTO LOG_OPERAZIONI (ID_UTENTE, DATA_ORA, TIPO_INTEGRALE, FUNZIONE, ESTREMO_INFERIORE, ESTREMO_SUPERIORE, RISULTATO) VALUES ({id_utente}, '{data_orario}', '{tipo_integrale}', '{funzione}', {estremo_i}, {estremo_s}, '{risultato}')")        
    
    # Save (commit) the changes
    con.commit()
    con.close()
    # ---------------



if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0')