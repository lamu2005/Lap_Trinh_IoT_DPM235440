const int Button1 = 2;
const int Button2 = 3;
const int Led = 9;
void setup() {
  // put your setup code here, to run once:
  pinMode(Button1, INPUT);
  pinMode(Button2, INPUT);
  pinMode(Led, OUTPUT);
  digitalWrite(Button1, HIGH);
  digitalWrite(Button2, HIGH);
}

int ledBrightness = 128;

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(Button1) == LOW)
  {
    ledBrightness--;
  } else if(digitalRead(Button2) == LOW)
  {
    ledBrightness++;
  }
  ledBrightness = constrain(ledBrightness, 0 ,255);
  analogWrite(Led, ledBrightness);
  delay(20);
}
