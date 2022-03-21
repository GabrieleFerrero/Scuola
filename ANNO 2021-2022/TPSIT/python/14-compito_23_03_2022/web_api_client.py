import requests

while True:

    print("MENÙ:\n- [1] mostra categorie\n- [2] ricerca per categoria\n- [3] ricerca per parola")
    scelta = int(input("Inserire scelta: "))

    if scelta == 1:
        results = requests.get("https://api.chucknorris.io/jokes/categories")
        print(results.text)
    elif scelta == 2:
        categoria = input("Inserire la categoria: ")
        results = requests.get("https://api.chucknorris.io/jokes/random", params={"category":categoria})
        print(eval(results.text)["value"])
    elif scelta == 3:
        parola = input("Inserire la parola: ")
        results = requests.get("https://api.chucknorris.io/jokes/search", params={"query":parola})
        results = eval(results.text)
        for n in range(0,int(results['total'])):
            print(f"Frase n. {n}: {results['result'][n]['value']}")

    else:
        print("SCELTA NONO VALIDA!")