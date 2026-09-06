int rainSensor = A0;
int buzzer = 8;

void setup() {
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int rainValue = analogRead(rainSensor);

  Serial.println(rainValue);

  if (rainValue < 500) {
    digitalWrite(buzzer, HIGH);
  }
  else {
    digitalWrite(buzzer, LOW);
  }

  delay(200);
}
