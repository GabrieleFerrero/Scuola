import requests
from math import *
from time import sleep

id = int(input('Inserire id client: '))
while True:
    # ricerca operazione
    messaggio = eval(requests.get("http://127.0.0.1:5000/api/v1/svolgi_operazione", params={"id": id}).text)
    print(f'Messaggio: {messaggio}')
    if messaggio['dati'] == 'fine':
        break
    else:

        if type(messaggio['dati']) == dict:
            try: risultato = eval(messaggio['dati']['operazione'])
            except: risultato = 'errore'

            print(f'Risultato: {risultato}')
            requests.get("http://127.0.0.1:5000/api/v1/svolgi_operazione", params={"id":id, 'id_operazione':messaggio['dati']['id_operazione'], 'risultato':risultato}).text

    sleep(5)
print('fine programma')