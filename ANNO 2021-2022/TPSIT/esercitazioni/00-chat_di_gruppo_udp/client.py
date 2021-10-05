import socket as sck
import time
import threading


#          SOCKET          #
SERVER_ADDRESS = "192.168.88.67"
SERVER_PORT = 5000
SERVER_DATA = (SERVER_ADDRESS, SERVER_PORT)	
s = sck.socket(sck.AF_INET, sck.SOCK_DGRAM)
# ------------------------ #

nickname = "gabriele"

class Receiver(threading.Thread):
    def __init__(self,sock):
        threading.Thread.__init__(self)
        self.sock = sock
        self.running = True
    def run(self):
        while self.running:
            data, addr = self.sock.recvfrom(4096)
            print("\n"+data.decode()+"\n") 


def main():
    receiver = Receiver(s)
    receiver.start()

    s.sendto(f"Nickname:{nickname}".encode(), SERVER_DATA) 

    print("Il messaggio è strutturato in questo modo: nome_a_cui_si_vuole_inoltrare_il_messaggio, messaggio")
    try:
        while True:
            data = input("")
            ricevente = data.split(",")[0]
            msg = data.split(",")[1]
            s.sendto(f"Sender:{nickname},Receiver:{ricevente},{msg}".encode(), SERVER_DATA) 
    except:
        s.close()


if __name__ == "__main__":
    main()