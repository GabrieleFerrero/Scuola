import socket as sck

s = sck.socket(sck.AF_INET, sck.SOCK_STREAM)
s.connect(('192.168.0.117',5000))



while True:
    act = input("Insert one of the following actions: (forward, backward, right, left, stop):\n")
    s.sendall(act.encode())

sck.close