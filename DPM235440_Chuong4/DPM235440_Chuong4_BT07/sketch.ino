#include <LiquidCrystal.h>

int mq2 = A0;
int rel = 13;
int buz = 10;
int d;
float p;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  pinMode(rel, OUTPUT);
  pinMode(buz, OUTPUT);
  digitalWrite(rel, LOW);
  digitalWrite(buz, LOW);
  
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print(" LPG DETECTOR ");
  lcd.setCursor(0, 1);
  lcd.print(" INITIALIZING...");
  delay(2000);
  lcd.clear();
}

void loop() {
  d = analogRead(mq2);

  if (d < 60) {
    p = 0;
  } else {
    p = (float)(d - 60) * 100.0 / (1023.0 - 60.0);
  }

  lcd.setCursor(0, 0);
  lcd.print("LPG: ");
  lcd.print(p, 1);
  lcd.print("%     ");

  lcd.setCursor(0, 1);
  if (p > 20.0) { 
    digitalWrite(rel, HIGH);
    tone(buz, 1000);          // Kích hoạt âm thanh tần số 1000Hz
    lcd.print("Status: DANGER! ");
  } else {
    digitalWrite(rel, LOW);
    noTone(buz);              // Tắt còi
    lcd.print("Status: NORMAL  ");
  }

  delay(300);
}