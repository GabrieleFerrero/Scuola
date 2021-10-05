import matplotlib.pyplot as plt
import csv



def estrazioneDati():
    mesi = []
    temperature_min = []
    temperature_max = []
    giorni_per_mese_che_si_indossa_la_giacca = []
    giorni_per_mese_in_cui_si_va_a_scuola = []
    giorni_per_mese_in_cui_gioco_ai_videogiochi = []

    with open('/home/gabriele/Scrivania/gabriele/scuola/sistemi_e_reti/python/esercitazioni/esercitazione_11/temperature.csv', 'r') as file:
        reader = csv.reader(file, delimiter=",")
        next(reader)
        for row in reader:
            print(row)
            mesi.append(row[0])
            temperature_min.append(float(row[1]))
            temperature_max.append(float(row[2]))
            giorni_per_mese_che_si_indossa_la_giacca.append(int(row[3]))
            giorni_per_mese_in_cui_si_va_a_scuola.append(int(row[4]))
            giorni_per_mese_in_cui_gioco_ai_videogiochi.append(int(row[5]))

    return mesi, temperature_min, temperature_max, giorni_per_mese_che_si_indossa_la_giacca, giorni_per_mese_in_cui_si_va_a_scuola, giorni_per_mese_in_cui_gioco_ai_videogiochi

def calcoloTemperatureMedie(temperature_min, temperature_max):
    temperature = list(zip(temperature_min, temperature_max))
    temperature_medie = []
    for temp_min_max in temperature:
        temperature_medie.append((float(temp_min_max[0])+float(temp_min_max[1])/2))
    return temperature_medie


def creazioneGrafico(dati_x, dati_y, titolo_grafico, scritta_asse_x, scritta_asse_y, togli_linee = False):
    fig, ax1 = plt.subplots(1, 1)
    fig.suptitle(titolo_grafico)

    if togli_linee: ax1.plot(dati_x, dati_y, 'og')
    else: ax1.plot(dati_x, dati_y, 'o-g')

    ax1.set_xlabel(scritta_asse_x)
    ax1.set_ylabel(scritta_asse_y)

def main():
    mesi, temperature_min, temperature_max, giorni_per_mese_che_si_indossa_la_giacca, giorni_per_mese_in_cui_si_va_a_scuola, giorni_per_mese_in_cui_gioco_ai_videogiochi = estrazioneDati()
    temperature_medie = calcoloTemperatureMedie(temperature_min, temperature_max)
    creazioneGrafico(mesi, temperature_medie, "Temperature medie per mese dell'anno", "Mese", "Temperature medie\nC°")
    creazioneGrafico(mesi, giorni_per_mese_che_si_indossa_la_giacca, "Giorni in cui indosso la giacca per mesi dell'anno", "Mese", "Giorni in cui indosso la giacca per mese")
    creazioneGrafico(mesi, giorni_per_mese_in_cui_si_va_a_scuola, "Giorni in cui vado a scuola per mesi dell'anno", "Mese", "Giorni in cui vado a scuola per mese")
    creazioneGrafico(mesi, giorni_per_mese_in_cui_gioco_ai_videogiochi, "Giorni in cui gioco ai videogiochi per mesi dell'anno", "Mese", "Giorni in cui gioco ai videogiochi per mese")
    
    creazioneGrafico(temperature_medie, giorni_per_mese_che_si_indossa_la_giacca, "Temperatura media e giorni in cui indosso la giacca", "Temperature medie\nC°", "Giorni in cui indosso la giacca per mese", True)
    creazioneGrafico(temperature_medie, giorni_per_mese_in_cui_si_va_a_scuola, "Temperatura media e giorni in cui vado a scuola", "Temperature medie\nC°", "Giorni in cui vado a scuola per mese", True)
    creazioneGrafico(temperature_medie, giorni_per_mese_in_cui_gioco_ai_videogiochi, "Temperatura media e giorni in cui gioco ai videogiochi","Temperature medie\nC°", "Giorni in cui gioco ai videogiochi per mese", True)
    creazioneGrafico(giorni_per_mese_che_si_indossa_la_giacca, giorni_per_mese_in_cui_si_va_a_scuola, "Giorni in cui si indossa la giacca e giorni in cui vado a scuola", "Giorni in cui indosso la giacca per mese", "Giorni in cui vado a scuola per mese", True)
    creazioneGrafico(giorni_per_mese_che_si_indossa_la_giacca, giorni_per_mese_in_cui_gioco_ai_videogiochi, "Giorni in cui indosso la giacca e giorni in cui gioco ai videogiochi", "Giorni in cui indosso la giacca per mese", "Giorni in cui gioco ai videogiochi per mese", True)
    creazioneGrafico(giorni_per_mese_in_cui_si_va_a_scuola, giorni_per_mese_in_cui_gioco_ai_videogiochi, "Giorni in cui vado a scuola e giorni in cui gioco ai videogiochi", "Giorni in cui vado a scuola per mese", "Giorni in cui gioco ai videogiochi per mese", True)

    plt.show()

if __name__ == '__main__':
    main()