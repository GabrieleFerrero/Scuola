import socket as sck
import threading


#          SOCKET          #
SERVER_ADDRESS = "192.168.1.51"
SERVER_PORT = 5000
SERVER_DATA = (SERVER_ADDRESS, SERVER_PORT)	
s = sck.socket(sck.AF_INET, sck.SOCK_STREAM)
s.connect(SERVER_DATA) # tupla --> indirizzo ip, porta
# ------------------------ #

nickname = "gabriele"

class Receiver(threading.Thread):
    def __init__(self,sock):
        threading.Thread.__init__(self)
        self.sock = sock
        self.running = True
    def run(self):
        while self.running:
            data = self.sock.recv(4096)
            print("\n"+data.decode()+"\n") 


def main():
    receiver = Receiver(s)
    receiver.start()

    s.sendall(f"Nickname:{nickname}".encode()) 

    print("Il messaggio è strutturato in questo modo: nome_a_cui_si_vuole_inoltrare_il_messaggio, messaggio")
    try:
        while True:
            data = input("")
            ricevente = data.split(",")[0]
            msg = data.split(",")[1]
            s.sendall(f"Sender:{nickname},Receiver:{ricevente},{msg}".encode()) 
    except:
        s.close()
        receiver.join()


if __name__ == "__main__":
    main()