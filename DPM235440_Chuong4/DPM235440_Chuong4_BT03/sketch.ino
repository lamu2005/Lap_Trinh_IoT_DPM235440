const int TRIG_PIN = 9;
const int ECHO_PIN = 8;
const int LED_PIN  = 13;

// Ngưỡng khoảng cách phát hiện vật cản (10 cm)
const float THRESHOLD_CM = 10.0;

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // Phát xung siêu âm 10us
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Đo thời gian phản hồi
  long duration = pulseIn(ECHO_PIN, HIGH);
  float distance = duration * 0.0343 / 2.0;

  Serial.print("Khoang cach: ");
  Serial.print(distance);
  Serial.print(" cm -> ");

  // Hoạt động như Công tắc tiệm cận: Khoảng cách < 10cm thì BẬT công tắc (Sáng LED)
  if (distance > 0 && distance < THRESHOLD_CM) {
    digitalWrite(LED_PIN, HIGH);
    Serial.println("[CONG TAC BAT] Phat hien vat can -> LED ON");
  } else {
    digitalWrite(LED_PIN, LOW);
    Serial.println("An toan -> LED OFF");
  }

  delay(200);
}