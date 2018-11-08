//example testing sketch for various DHT humidity/temperature sensors
//Written by ladyada, public domain
#include<DHT.h>
#include<LiquidCrystal.h>//i
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);//
creates an LCD object.Parameters:(rs,enable,d4,d5,d6,d7)
#define DHTPIN 8 // what pin we are connected to
//uncomment whatever type you are using!
#define DHTTYPE DHT22  // DHT22(AM2302)
#define dataPin 8
//#define DHTTYPE DHT21  //DHT21(AM2301)
DHT dht(DHTPIN, DHTTYPE);
void setup() {
 
  // put your setup code here, to run once:
lcd.begin(16,2);
Serial.begin(9600);
lcd.setCursor(0,0);
lcd.print("Presented by");
delay(1500);
lcd.setCursor(0,1);
lcd.print("LALU ROHIT");// you can enter your name
delay(100);
lcd.setCursor(0,0);
lcd.print("Calibrating");
for(int i=0;i<14;i++){
  if(i==4)
  {
    lcd.setCursor(0,1);
    lcd.print(".");
  }
  else lcd.print(".");
  delay(1000);
}
lcd.setCursor(6,1);
lcd.print("done");
delay(1500);
lcd.clear();
lcd.setCursor(1,0);
lcd.print("SENSOR ACTIVE");
delay(3000);
}

void loop() {
  // put your main code here, to run repeatedly:
// wait a few seconds between measurements.
delay(2000);
float h = dht.readHumidity();
//Read temperature as celsius(the default)
float t = dht.readTemperature();
// read temperature as Fahrenheit(is Fahrenheit=true)
lcd.setCursor(0,0);
lcd.print("Temp....");
lcd.print(t);
lcd.print("*c");
lcd.setCursor(0,1);
lcd.print("Humidity");
lcd.print(h);
lcd.print("%");
}
