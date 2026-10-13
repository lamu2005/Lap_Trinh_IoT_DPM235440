const int Pot = A0;
const int Led = 9;

void setup() {
  // put your setup code here, to run once:
  pinMode(Pot, INPUT);
  pinMode(Led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int ledBrightness;
  int sensorValue = 0;

  sensorValue = analogRead(Pot);
  ledBrightness = map(sensorValue, 0, 1023, 0, 255);
  analogWrite(Led, ledBrightness);
}
