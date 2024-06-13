# Arduino merjenje temperature in vlage
### Projektna naloga pri predmetu MRE


## Opis delovanja

Naprava za merjenje temperature in vlage uporablja senzor DHT11, ki periodično meri temperaturo in vlago v okolju. Izmerjene vrednosti se prikažejo na 20x4 I2C LCD zaslonu, kjer je vlaga zapisana v odstotkih (%) in temperatura v stopinjah Celzija (°C). Poleg tega naprava vključuje tri LED diode (modra, zelena, rdeča), ki se prižgejo glede na izmerjeno temperaturo: modra LED dioda se prižge pri nizki temperaturi, zelena pri normalni temperaturi in rdeča pri visoki temperaturi. Mejne vrednosti za vklop LED diod so nastavljene v programski kodi v programu Arduino IDE.

[DHT11 Datasheet](https://www.mouser.com/datasheet/2/758/DHT11-Technical-Data-Sheet-Translated-Version-1143054.pdf)

## Kosovnica 

Podroben seznam uporabljenega materiala je na voljo tukaj: [Kosovnica](kosovnica_materiala.xlsx)
|Sestavni del|Št. kosov|
|---|---|
|Arduino UNO R3|   1   |
|Protoboard|   1   |
|I2C LCD zaslon|   1   |
|DHT11 senzor|   1   |
|LED diode|   3   |
|Upor|   3   |
|Povezovalne žice|   12   |
|Ohišje - PLA filament|   /   |

## Vezalna shema
### Fritzing
[Vezalna shema - Fritzing](vezalna_shema_Fritzing.png)

### EasyEDA

[Vezalna shema - EasyEDA](vezalna_shema_EasyEDA.png)

## Uporabljane enačbe

PDF datoteko z vsemi uporabljenimi enačbami in izračuni za predupore LED diod je na voljo tukaj: [Uporabljene enačbe](enacbe_predupori.pdf)

## Arduino programska koda

Programsko kodo lahko najdete tukaj: [Arduino program](MRE_merjenje_temperature_vlage.ino)


Kliknite na povezavo in prenesite datoteko na svoj računalnik. Če še nimate nameščene aplikacije Arduino IDE, jo prenesite in namestite iz [uradne spletne strani Arduino](https://www.arduino.cc/en/software). Nato zaženite Arduino IDE in kliknite na File > Open, da izberete preneseno datoteko s kodo. S pomočjo USB kabla povežite svojo Arduino ploščico z računalnikom. V Arduino IDE kliknite na Tools > Board in izberite svojo Arduino ploščico (npr. Arduino Uno). Nato kliknite na Tools > Port in izberite ustrezen COM port, ki je dodeljen vaši ploščici. Ko ste nastavili ploščico in vrata, kliknite na gumb Upload (puščica desno) v Arduino IDE, da naložite kodo na vašo Arduino ploščico. Počakajte, da se nalaganje zaključi. Ko je postopek uspešno zaključen, bo na dnu Arduino IDE okna prikazano sporočilo "Done uploading".

## Ohišje 

STL datoteka ohišja naprave za merjenje temperature in vlage: [STL - ohišje](ohisje_naprava_temperatura_vlaga.stl)


Slika 3D modela ohišja naprave za merjenje temperature in vlage: [Slika 3D modela - ohišje](ohisje_naprava_temperatura_vlaga.png)

## Slika vezave
![IMG_20240612_185038](https://github.com/TinKos/merjenje-temperature-in-vlage/assets/171680852/6418ea62-5ba8-408b-8c4d-2e2b0602fe2c)

## Slika končne naprave

Slika končne naprave je dosegljiva tukaj: [Končna naprava](koncna_naprava.jpg)


## Videoposnetek delovanja

## Ocena natančnosti
__*Podatki natančnosti iz [DHT11 datasheet-a](DHT11_Datasheet.pdf):*__


Natančnost meritve **temperature:** ± 2 °C


Natančnost meritve **vlage:** ± 5 % RH


Temperaturno območje senzorja: 0-50 °C

--------------------------------------------------------------

__*Podatki natančnosti na realnem primeru:*__


Natančnost meritve **temperature:** ± 0 °C (meritev je bila opravljena pri 24 °C)


Natančnost meritve **vlage:** / 


Temperaturno območje senzorja: 0-60 °C

--------------------------------------------------------------

Pri 24 °C je naša naprava točna (razlika med temperaturo, ki jo je izmeril multimeter in tempereaturo, ki jo je izmerila naša naprava, je 0 °C). Z višanjem temperature pa se je ta napaka večala, ker pa je senzor temperaturno omejen na 60 °C (izmerjeno), temperature višje od te ne more zaznati. Prav tako je trajalo več časa, da je senzor samo temperaturo zaznal in jo prikazal na LCD zaslonu. 


Tempeartura je bila izmerjena z uporabo multimetra [Kunzer MY70](MY70_Datasheet.pdf). Natančnost meritve multimetra temperature je ± 1 %.


Vlage nismo mogli izmeriti, saj nismo imeli instrumenta oz. naprave za merjenje vlage, zato podatka o natančnosti realnega primera nimamo.




## Komentar
Naprava deluje v skladu s pričakovanji in izpolnjuje svoj namen. Meritve temperature in vlage so dovolj natančne za uporabo naše naprave namesto drugih primerljivih naprav pri nekih normalnih temperaturah (med 20 °C in 35 °C). Če pa bi želeli opravljati meritve temperature višjih temperatur (med 35 °C in 60 °C), pa bi bila naša naprava premalo natančna. 
Same natančnosti meritve s tem senzorjem ni mogoče izboljšati, ker ga ne moremo kalibrirati. 


Senzor DHT11 ne potrebuje kalibracije, niti ga ne moremo kalibrirati. DHT11 je tovarniško kalibriran in pripravljen za uporabo. To pomeni, da bi moral zagotavljati natančne meritve temperature in vlažnosti takoj po povezavi in inicializaciji. Če se pojavijo težave z natančnostjo, je najpogosteje razlog napačna uporaba ali nepravilne povezave. 

Za izboljšanje te naprave bi lahko uporabili senzor DHT22 namesto DHT11, kar bi omogočilo izpis temperature na 0.1°C natančno, namesto na 1°C, kot ga omogoča senzor DHT11. Poleg tega bi lahko nadgradili mikrokontroler, na primer z uporabo Arduino UNO REV4 WiFi, ESP32, MKR WiFi, Portenta H7 itd. Ti mikrokontrolerji ponujajo dodatne funkcionalnosti, kot je WiFi povezljivost, kar bi omogočilo nadzor nad temperaturo in vlago preko Arduino Clouda. S tem bi lahko shranjevali in analizirali podatke ter imeli dodatne možnosti upravljanja naprave. Te izboljšave bi pripomogle k večji natančnosti, funkcionalnosti in uporabniku prijaznosti naše naprave.






