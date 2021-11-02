import socket as sck
import AlphaBot as ab
from time import sleep

# COSTANTI #
TEMPO_PER_CURVARE_DI_90_GRADI = 0.5
# -----------#
# ROBOT #
gestione_motori = ab.AlphaBot()
gestione_motori.stop()
# -----------#
# SOCKET #
s = sck.socket(sck.AF_INET, sck.SOCK_STREAM)
s.bind(("0.0.0.0", 5000))
s.listen(1)
# -----------#


def left(angolo):
    # 90:0.5 = angolo: secondi
    secondi = int(angolo)*TEMPO_PER_CURVARE_DI_90_GRADI/90
    gestione_motori.left()
    sleep(secondi)
    gestione_motori.stop()

def right(angolo):
    secondi = int(angolo)*TEMPO_PER_CURVARE_DI_90_GRADI/90
    gestione_motori.right()
    sleep(secondi)
    gestione_motori.stop()


comandi = {
    "l": left,
    "r": right,
    "f": gestione_motori.forward,
    "b": gestione_motori.backward,
    "s": gestione_motori.stop,
    "PWMA": gestione_motori.setPWMA,
    "PWMB": gestione_motori.setPWMB
}

def main():
    connection, address = s.accept()

    try:
        while True:
            dato = connection.recv(4096).decode()
            print(dato)
            try:
                if "l" in dato or "r" in dato:
                    comandi[dato.split(",")[0]](dato.split(",")[1])
                else:
                    comandi[dato]()
            except:
                print("Dato ricevuto non valido!!!")
    except:
        connection.close()
        s.close()

if __name__ == "__main__":
    main()



