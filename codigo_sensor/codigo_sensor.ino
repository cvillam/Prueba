#include "DHT.h"
#include <LiquidCrystal.h>
#define DHTPIN 15 //Analog 1
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
	
         lcd.begin(16, 2);
	dht.begin();
}
void loop() {
	float h = dht.readHumidity();
	float t = dht.readTemperature();
	if (isnan(t) || isnan(h)) {
		lcd.println("Sensor desconectado");
	} else {
		lcd.setCursor(0, 0);
                lcd.print("Temp: ");
                lcd.print(t);
                lcd.print(" *C");
                lcd.setCursor(0, 1);
                lcd.print("HR: ");
                lcd.print(h);
                lcd.print(" %");
		delay(3000);
                //lcd.clear();
	}
}
