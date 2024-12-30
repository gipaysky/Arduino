# Auto Alarm on Stability Temperature
 - This Project Using Wokwi.com as a Project Simulator

## Description:
 - DHT22 is a low-cost, digital sensor that measures temperature and humidity. It uses a thermistor and a capacitive humidity sensor to measure the surrounding air and sends a digital signal to a data pin.

## Component
 - Arduino Uno = 1 Unit, - Sensor DHT22 = 1 Unit, - Relay Module = 1 Unit, - Buzzer = 1 Unit, - LED = 1 Unit, - Resistor = 1 Unit, - LCD 16x2 = 1 Unit.
   
## Circuit Schematic:
<img width="400" alt="Screenshot 2024-12-30 095730" src="https://github.com/user-attachments/assets/79194c5c-78a4-4419-82fb-b5fc9bb02255" />

## Skecth Code Program

```cpp
/* Program Auto Alarm On Stability Temperature */

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
