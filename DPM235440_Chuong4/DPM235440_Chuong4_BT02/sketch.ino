#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int sensorPin = A1;
const float BETA = 3950; // Hệ số Beta mặc định của cảm biến NTC

// Khởi tạo LCD I2C địa chỉ 0x27, 16 cột, 2 dòng
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
  
  // Màn hình chào mừng
  lcd.setCursor(0, 0);
  lcd.print("NHIET DO HE THONG");
  delay(1500);
  lcd.clear();
}

void loop() {
  int analogValue = analogRead(sensorPin);

  // Tính nhiệt độ C từ cảm biến NTC
  float tempC = 1 / (log(1 / (1023.0 / analogValue - 1)) / BETA + 1.0 / 298.15) - 273.15;
  float tempF = (tempC * 1.8) + 32;

  // Dòng 1: Hiển thị độ C
  lcd.setCursor(0, 0);
  lcd.print("Temp C: ");
  lcd.print(tempC, 1);
  lcd.print((char)223); // Ký tự biểu tượng độ (°)
  lcd.print("C   ");

  // Dòng 2: Hiển thị độ F
  lcd.setCursor(0, 1);
  lcd.print("Temp F: ");
  lcd.print(tempF, 1);
  lcd.print((char)223); // Ký tự biểu tượng độ (°)
  lcd.print("F   ");

  delay(500);
}