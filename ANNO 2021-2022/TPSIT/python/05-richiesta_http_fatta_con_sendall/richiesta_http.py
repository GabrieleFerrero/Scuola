import socket as sck

# SITO: http://www.sistemapiemonte.it/cms/privati/salute/176-la-mia

s = sck.socket(sck.AF_INET, sck.SOCK_STREAM)
s.connect(('158.102.161.250', 80)) # tupla --> indirizzo ip, porta

messaggio_http = "GET /messaggi_error/error404.shtml HTTP/1.1\r\nHost: www.sistemapiemonte.it\r\nScheme: http\r\n\r\n"

print(f"INIZIO MESSAGGIO HTTP:\n{messaggio_http}FINE MESSAGGIO HTTP")

s.sendall(f"{messaggio_http}".encode())
risposta = s.recv(10240)

print(risposta)

s.close()

