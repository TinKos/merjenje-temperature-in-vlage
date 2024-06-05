# Arduino merjenje temperature in vlage
### Projektna naloga pri predmetu MRE


## Opis delovanja

Naprava za merjenje temperature in vlage uporablja senzor DHT11, ki periodično meri temperaturo in vlago v okolju. Izmerjene vrednosti se prikažejo na 20x4 I2C LCD zaslonu, kjer je vlaga zapisana v odstotkih (%) in temperatura v stopinjah Celzija (°C). Poleg tega naprava vključuje tri LED diode (modra, zelena, rdeča), ki se prižgejo glede na izmerjeno temperaturo: modra LED dioda se prižge pri nizki temperaturi, zelena pri normalni temperaturi in rdeča pri visoki temperaturi. Mejne vrednosti za vklop LED diod so nastavljene v programski kodi v programu Arduino IDE.

[DHT11 Datasheet](https://www.mouser.com/datasheet/2/758/DHT11-Technical-Data-Sheet-Translated-Version-1143054.pdf)

## Kosovnica 

Podrobni seznam uporabljenega materiala je na voljo tukaj: [Kosovnica](kosovnica.xlsx)

## Vezalna shema
### Fritzing
[Vezalna shema - Fritzing](vezalna_shema_Fritzing.png)

### EasyEDA

[Vezalna shema - EasyEDA](vezalna_shema_EasyEDA.png)

## Arduino programska koda

Programsko kodo lahko najdete tukaj: [Arduino program](MRE_merjenje_temperature_vlage.ino)


Kliknite na povezavo in prenesite datoteko na svoj računalnik. Če še nimate nameščene aplikacije Arduino IDE, jo prenesite in namestite iz [uradne spletne strani Arduino](https://www.arduino.cc/en/software). Nato zaženite Arduino IDE in kliknite na File > Open, da izberete preneseno datoteko s kodo. S pomočjo USB kabla povežite svojo Arduino ploščico z računalnikom. V Arduino IDE kliknite na Tools > Board in izberite svojo Arduino ploščico (npr. Arduino Uno). Nato kliknite na Tools > Port in izberite ustrezen COM port, ki je dodeljen vaši ploščici. Ko ste nastavili ploščico in vrata, kliknite na gumb Upload (puščica desno) v Arduino IDE, da naložite kodo na vašo Arduino ploščico. Počakajte, da se nalaganje zaključi. Ko je postopek uspešno zaključen, bo na dnu Arduino IDE okna prikazano sporočilo "Done uploading".

## Videoposnetek delovanja

## Ocena natančnosti

## Komentar
Naprava deluje, tako kot je bilo načrtovano.

Za izboljšanje te naprave, bi lahko uporabili drug DHT senzor (npr. DHT22), ki bi omogočil izpis temperature na 0.1°C natančno, namesto na 1°C, ki ga omogoča senzor DHT11.
Namesto Arduino UNO REV3 mikrokontrolerja, bi lahko uporabili npr. Arduino UNO REV4 WiFi, ESP32, MKR WiFi, Portenta H7 itd., ki bi omogčili nadzor nad temperaturo in vlago preko Arduino Clouda.




