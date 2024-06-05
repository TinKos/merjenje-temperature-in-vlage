// Arduino - Merjenje temperature in vlage 
// Projektna naloga pri predmetu MRE
// Avtorja: Robert Tomić in Tin Kos

#include <DHT.h>  // Knjižnica za DHT senzor        
#include <LiquidCrystal_I2C.h>  // Knjižnica za I2C LCD zaslon 

#define DHTPIN A0  // Določitev pina za DHT senzor
#define DHTTYPE DHT11  // Določitev tipa DHT senzorja

// Določitev pinov za LED diode
#define LED_RD 7
#define LED_ZE 8
#define LED_MO 9

DHT dht(DHTPIN, DHTTYPE);  // Inicializacija DHT senzorja

LiquidCrystal_I2C lcd(0x27, 20, 4);  // Inicializacija I2C LCD zaslona 

byte stopinje[8] = {  // Znak za stopinje
  B01100,
  B10010,
  B10010,
  B01100,
  B00000,
  B00000,
  B00000,
};

void setup() {

  dht.begin();  // Inicializacija DHT senzorja
  
  // Vklop ozadja LCD zaslona in inicializacija
  lcd.backlight();
  lcd.init();
  
  lcd.createChar(0, stopinje);  // Ustvarjanje znaka za stopinje

  // Inicializacija pinov za LED diode kot izhodni pini
  pinMode(LED_MO, OUTPUT);
  pinMode(LED_RD, OUTPUT);
  pinMode(LED_ZE, OUTPUT);
}

void loop() {

  // Branje vrednosti temperature in vlage iz DHT senzorja
  float v = dht.readHumidity();
  float t = dht.readTemperature();

  // Izpis temperature na LCD zaslonu
  lcd.setCursor(0, 0);
  lcd.print("Tempeartura: ");
  lcd.print(t);
  lcd.write(stopinje); // Dodajanje simbola za stopinje
  lcd.print("C");
  
  // Izpis vlage na LCD zaslonu
  lcd.setCursor(0, 2);
  lcd.print("Vlaga: ");
  lcd.print(v);
  lcd.print("%");
  
  // Pogojno vklapljanje LED diod glede na izmerjeno temperaturo
  if (t > 22 && t < 25) {        // Temperatura med 22°C in 25 °C
    digitalWrite(LED_RD, HIGH);  // Prižgi rdečo LED diodo
    digitalWrite(LED_ZE, LOW);   // Ugasni zeleno LED diodo
    digitalWrite(LED_MO, LOW);   // Ugasni modro LED diodo
  }
  else if (t >= 25 && t < 28) {  // Temperatura med 25°C in 28 °C
    digitalWrite(LED_ZE, HIGH);  // Prižgi zeleno LED diodo
    digitalWrite(LED_RD, LOW);   // Ugasni rdečo LED diodo
    digitalWrite(LED_MO, LOW);   // Ugasni modro LED diodo
  }
  else if (t >= 28) {            // Temperatura, višja od 28°C 
    digitalWrite(LED_MO, HIGH);  // Prižgi modro LED diodo
    digitalWrite(LED_RD, LOW);   // Ugasni rdečo LED diodo
    digitalWrite(LED_ZE, LOW);   // Ugasni zeleno LED diodo
  }
  
  // Delay
  delay(10);
}
