int buzzer = 8;
int LED = 7;
int gas_sensor = A0;  
int threshold = 700; // Ngưỡng chuẩn Wokwi: < 700 An toàn | > 700 Báo động

unsigned long prevBlinkMillis = 0;
unsigned long prevPrintMillis = 0;
bool ledState = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(gas_sensor, INPUT);
}

void loop() {
  unsigned long currentMillis = millis();

  // Đọc tín hiệu Analog liên tục (không bị delay cản trở)
  int gas_val = analogRead(gas_sensor);

  // MỨC NGUY HIỂM: Vượt ngưỡng 700 PPM
  if (gas_val > threshold) {
    
    // Tạo nhịp chớp nháy LED và còi hú mỗi 200ms bằng millis()
    if (currentMillis - prevBlinkMillis >= 200) {
      prevBlinkMillis = currentMillis;
      ledState = !ledState;
      
      digitalWrite(LED, ledState);
      if (ledState) {
        tone(buzzer, 2000);
      } else {
        noTone(buzzer);
      }
    }

    // In ra Serial mỗi 400ms để theo dõi mượt mà
    if (currentMillis - prevPrintMillis >= 400) {
      prevPrintMillis = currentMillis;
      Serial.print("Nong do Gas: ");
      Serial.print(gas_val);
      Serial.println(" -> Chay nhu phi phai...!");
    }

  } 
  // MỨC AN TOÀN: Dưới ngưỡng 700 PPM
  else {
    // Tắt ngay còi và LED tức thì khi kéo slider xuống
    noTone(buzzer);
    digitalWrite(LED, LOW);
    ledState = LOW;

    if (currentMillis - prevPrintMillis >= 400) {
      prevPrintMillis = currentMillis;
      Serial.print("Nong do Gas: ");
      Serial.print(gas_val);
      Serial.println(" -> An toan (No more phi phai)");
    }
  }
}