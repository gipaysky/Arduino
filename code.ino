#include <Wire.h>

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
#include <DHT.h>
int Suhu;
int nilai;
float t;
#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

const byte
RELAY1(3);


void setup()
{
  Serial.begin(9600);
  pinMode(RELAY1, OUTPUT);

  lcd.init();
  lcd.backlight();
  lcd.blink_on();
}

void loop()
{
  dht.begin();
  Suhu = digitalRead(DHT22);
  delay(2000);
  float t = dht.readTemperature();

  Serial.print("Suhu: ");
  Serial.print(t);
  Serial.println(" *C");

  String disp = String(t);
  lcd.clear();
  lcd.setCursor(5, 0);
  lcd.print("Suhu:");
  lcd.setCursor(4, 1);
  lcd.print(disp);
  lcd.print(" *C");

  if (t >= 50)
  {
    digitalWrite(RELAY1, HIGH);
    delay(100);
    digitalWrite(RELAY1, LOW);
    delay(100);
  }

  if (t < 50)
  {
    digitalWrite(RELAY1, LOW);
  }
}