const int redPin = 11;
const int greenPin = 10;
const int bluePin = 9;

void setRGB(int r, int g, int b) {
  analogWrite(redPin, r);
  analogWrite(greenPin, g);
  analogWrite(bluePin, b);
}

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  setRGB(255, 0, 0); delay(1000); // Sáng Đỏ
  setRGB(0, 255, 0); delay(1000); // Sáng Xanh lá
  setRGB(0, 0, 255); delay(1000); // Sáng Xanh dương
}