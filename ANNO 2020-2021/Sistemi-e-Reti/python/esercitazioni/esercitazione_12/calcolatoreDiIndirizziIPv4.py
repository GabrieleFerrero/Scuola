import math

NUM_BIT_IPv4 = 32
NUM_PARTI_INDIRIZZO_IP = 4
NUM_FINALE_INDIRIZZO_IP = 255

def inputIPv4():
    indirizzo = input("Inserire l'indrizzo come IPv4'/'Subnet Mask: ")
    indirizzo_IPv4 = indirizzo.split('/')[0]
    subnet_mask = int(indirizzo.split('/')[1])

    return indirizzo_IPv4, subnet_mask

def calcoloNumeroMassimoDiHost(subnet_mask):
    return int(math.pow(2, NUM_BIT_IPv4-subnet_mask)-2)

def calcoloPrimoHostDisponibile(indirizzoIPv4):
    return calcoloHost(indirizzoIPv4, 1)

def calcoloUltimoHostDisponibile(indirizzoIPv4, num_max_di_host):
    return calcoloHost(indirizzoIPv4, num_max_di_host)

def calcoloHost(indirizzoIPv4, num_host):
    new_host=add_binary_nums(convertitoreDaIndirizzoDecimaleBinario(indirizzoIPv4).replace(".",""), bin(num_host).replace("0b",""))
    new_host=list(new_host)


    # codice per aggiungere zeri, se servono, all'inizio dell'indirizzo
    host_correct = []
    if(len(new_host)<NUM_BIT_IPv4):
        diff = NUM_BIT_IPv4-len(new_host)
        for bit_da_aggiugnere in range(len(diff)):
            host_correct.append('0')
        host_correct = host_correct + new_host
    else: host_correct = new_host


    # codice per trasformare host_correct in una stringa aggiungendo i punti
    host = ""
    for n_bit in range(len(host_correct)):
        if(n_bit%(NUM_BIT_IPv4/NUM_PARTI_INDIRIZZO_IP) == 0 and n_bit!=0):
            host+="."
        host+=str(host_correct[n_bit])  


    return str(int(host.split('.')[0],2))+'.'+str(int(host.split('.')[1],2))+'.'+str(int(host.split('.')[2],2))+'.'+str(int(host.split('.')[3],2))
    

def calcoloIndirizzoDiBroadcast(ultimo_host_disponibile):
    return calcoloHost(ultimo_host_disponibile, 1)


def aggiungitoreDiZero(parte_di_indirizzo):
    parte_di_indirizzo_di_return = ""
    if(len(parte_di_indirizzo)<NUM_BIT_IPv4/NUM_PARTI_INDIRIZZO_IP):
        for _ in range(int(NUM_BIT_IPv4/NUM_PARTI_INDIRIZZO_IP-len(parte_di_indirizzo))):
            parte_di_indirizzo_di_return += "0"

    return parte_di_indirizzo_di_return+parte_di_indirizzo
    

def convertitoreDaIndirizzoDecimaleBinario(indirizzo):
    return aggiungitoreDiZero(bin(int(indirizzo.split('.')[0])).replace("0b",""))+'.'+aggiungitoreDiZero(bin(int(indirizzo.split('.')[1])).replace("0b",""))+'.'+aggiungitoreDiZero(bin(int(indirizzo.split('.')[2])).replace("0b",""))+'.'+aggiungitoreDiZero(bin(int(indirizzo.split('.')[3])).replace("0b",""))
    
def add_binary_nums(x,y):
        max_len = max(len(x), len(y))

        x = x.zfill(max_len)
        y = y.zfill(max_len)

        result = ''
        carry = 0

        for i in range(max_len-1, -1, -1):
            r = carry
            r += 1 if x[i] == '1' else 0
            r += 1 if y[i] == '1' else 0
            result = ('1' if r % 2 == 1 else '0') + result
            carry = 0 if r < 2 else 1       

        if carry !=0 : result = '1' + result

        return result.zfill(max_len)

def main():
    indirizzoIPv4, subnet_mask = inputIPv4()
    num_max_di_host = calcoloNumeroMassimoDiHost(subnet_mask)
    primo_host_disponibile = calcoloPrimoHostDisponibile(indirizzoIPv4)
    ultimo_host_disponibile = calcoloUltimoHostDisponibile(indirizzoIPv4, num_max_di_host)
    indrizzo_di_broadcast=calcoloIndirizzoDiBroadcast(ultimo_host_disponibile)

    print("L'indirizzo di rete è: "+str(indirizzoIPv4)+'\n'+"La subnet mask è: "+str(subnet_mask)+'\n'+"Il numero massimo di host disponibili è: "+str(num_max_di_host)+'\n'+"L'indirizzo del primo host disponibile è: "+str(primo_host_disponibile)+'\n'+"L'indirizzo dell'ultimo host disponibile è: "+str(ultimo_host_disponibile)+'\n'+"L'indirizzo di broadcast è: "+str(indrizzo_di_broadcast)+'\n')


if __name__ == "__main__":
    main()


    