const int sensorPin = A1;
const float BETA = 3950; // Hệ số Beta mặc định của cảm biến NTC trên Wokwi

void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
}

void loop() {
  int analogValue = analogRead(sensorPin);

  // Công thức chuyển đổi giá trị Analog sang nhiệt độ Độ C cho NTC
  float tempC = 1 / (log(1 / (1023.0 / analogValue - 1)) / BETA + 1.0 / 298.15) - 273.15;
  float tempF = (tempC * 1.8) + 32;

  Serial.print("in DegreeC = \t");
  Serial.print(tempC, 1);
  Serial.println(" °C");

  Serial.print("in Fahrenheit = \t");
  Serial.print(tempF, 1);
  Serial.println(" °F");

  delay(1000);
}