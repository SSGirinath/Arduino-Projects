#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int startStopPin = 6;
const int increasePin = 7;
const int decreasePin = 8;
const int buzzerPin = 9;

long totalSeconds = 0;
bool isRunning = false;

unsigned long lastTick = 0;
unsigned long buttonPressStart = 0;

bool startStopHeld = false;

const unsigned long longPressTime = 1000;

void setup() {
  lcd.begin(16, 2);

  pinMode(startStopPin, INPUT_PULLUP);
  pinMode(increasePin, INPUT_PULLUP);
  pinMode(decreasePin, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);

  lcd.print("Digital Timer");
  delay(1000);
  lcd.clear();
}

void loop() {
  handleStartStop();

  if (!isRunning) {
    handleAdjustment();
  }

  if (isRunning) {
    updateTimer();
  }

  displayTime();

  delay(50);
}

void handleStartStop() {
  bool pressed = digitalRead(startStopPin) == LOW;

  if (pressed && !startStopHeld) {
    startStopHeld = true;
    buttonPressStart = millis();
  }

  if (!pressed && startStopHeld) {
    startStopHeld = false;

    unsigned long pressTime = millis() - buttonPressStart;

    if (pressTime >= longPressTime) {
      totalSeconds = 0;
      isRunning = false;
    }
    else {
      isRunning = !isRunning;
      lastTick = millis();
    }
  }
}

void handleAdjustment() {
  if (digitalRead(increasePin) == LOW) {
    totalSeconds += 60;
    delay(200);
  }

  if (digitalRead(decreasePin) == LOW) {
    if (totalSeconds >= 60) {
      totalSeconds -= 60;
    }

    delay(200);
  }
}

void updateTimer() {
  if (millis() - lastTick >= 1000) {
    lastTick = millis();

    if (totalSeconds > 0) {
      totalSeconds--;
    }

    if (totalSeconds == 0) {
      isRunning = false;

      digitalWrite(buzzerPin, HIGH);
      delay(1000);
      digitalWrite(buzzerPin, LOW);
    }
  }
}

void displayTime() {
  int minutes = totalSeconds / 60;
  int seconds = totalSeconds % 60;

  lcd.setCursor(0, 0);
  lcd.print("Timer:          ");

  lcd.setCursor(0, 1);

  if (minutes < 10) {
    lcd.print("0");
  }

  lcd.print(minutes);
  lcd.print(":");

  if (seconds < 10) {
    lcd.print("0");
  }

  lcd.print(seconds);
  lcd.print("     ");
}