#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int sensorPin = A0;

const int minRawValue = 400;
const int maxRawValue = 900;
const int noiseThreshold = 20;

int readSensor() {
  return analogRead(sensorPin);
}

int calculateLevel(int sensorValue) {
  int difference = abs(sensorValue - minRawValue);

  if (difference < noiseThreshold) {
    return 0;
  }

  sensorValue = constrain(sensorValue, minRawValue, maxRawValue);

  return map(sensorValue, minRawValue, maxRawValue, 1, 10);
}

void displayLevel(int level) {
  lcd.setCursor(0, 0);
  lcd.print("Seismic Level:");

  lcd.setCursor(0, 1);
  lcd.print("                ");

  lcd.setCursor(0, 1);
  lcd.print(level);
  lcd.print(" / 10");
}

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);

  lcd.print("Seismograph Mk2");
  delay(1500);
  lcd.clear();
}

void loop() {
  int sensorValue = readSensor();
  int level = calculateLevel(sensorValue);

  displayLevel(level);

  Serial.print("Sensor: ");
  Serial.print(sensorValue);
  Serial.print(" | Level: ");
  Serial.println(level);

  delay(300);
}
