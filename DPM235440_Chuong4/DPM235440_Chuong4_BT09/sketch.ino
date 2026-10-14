#include "DHT.h"

#define DHTPIN A0
#define DHTTYPE DHT22 

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  Serial.println("Humidity (%)\tTemp (C)\tTemp (F)");
}

void loop() {
  delay(2000); // Cảm biến DHT11 cần khoảng 2 giây để cập nhật dữ liệu

  float h = dht.readHumidity();
  float t = dht.readTemperature();        // Đọc độ C
  float f = dht.readTemperature(true);    // Đọc độ F

  // Kiểm tra nếu cảm biến bị lỗi đọc dữ liệu
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Loi doc du lieu tu cam bien DHT!");
    return;
  }

  Serial.print(h, 1);
  Serial.print("\t\t");
  Serial.print(t, 1);
  Serial.print("\t\t");
  Serial.println(f, 1);
}