#include <DHT.h> //zahrne knihovnu "DHT sensor library" ! musi se nainstalovat z library manager
#include <Wire.h> //nemusi se instalovat
#include <LiquidCrystal_I2C.h> //musi se nainstalovat: https://github.com/johnrickman/LiquidCrystal_I2C/archive/refs/heads/master.zip
                                //vlozit a extrahovat do: C:\Users\student\Documents\Arduino\libraries

#define DHTPIN 2 //pin na kterem je pripojený singnál pin sensoru

#define DHTTYPE DHT11 //sensor je typu DHT11, při použití DTH22 stací přepsat

DHT dht(DHTPIN, DHTTYPE); //deklarace sensoru


LiquidCrystal_I2C lcd(0x27,20,4); // deklarace displaye 20 znaku, 4 radky, lze zmenit

void setup()
{
    Serial.begin(9600); //zahajit seriovy monitor
    dht.begin(); //zahajit prenos pro sensor
 
    lcd.init(); //inicializuje display
    lcd.backlight(); //zapne podsviceni
    lcd.setCursor(0,0); //nastavi cursor na 0x0
}
void loop()
{
    int teplota = dht.readTemperature(); //precist teplotu
    Serial.println(teplota); //napsat teplotu

    lcd.clear(); //smaže předešlý text z displaye 
    lcd.print(teplota); //napiše teplotu na display

    delay(300); 
}