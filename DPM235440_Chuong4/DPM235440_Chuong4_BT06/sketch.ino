#include <IRremote.hpp>

const int receiverPin = 8;
const int ledPin[] = {3, 4, 5, 6, 7, 9, 10, 11, 12, 13};

boolean stateledPin3 = false;
boolean stateledPin4 = false;
boolean stateledPin5 = false;
boolean stateledPin6 = false;
boolean stateledPin7 = false;
boolean stateledPin9 = false;
boolean stateledPin10 = false;
boolean stateledPin11 = false;
boolean stateledPin12 = false;
boolean stateledPin13 = false;

void setup() {
  Serial.begin(9600);
  
  // Tắt tính năng tự nháy Pin 13 để trả lại Pin 13 cho stateledPin13
  IrReceiver.begin(receiverPin, DISABLE_LED_FEEDBACK);
  
  for (int i = 0; i < 10; i++) {
    pinMode(ledPin[i], OUTPUT);
    digitalWrite(ledPin[i], LOW);
  }
}

// Hàm tái tạo mã HEX 32-bit đầy đủ dạng 0xFF00... chuẩn NEC
uint32_t getFullHexCode() {
  uint8_t cmd = IrReceiver.decodedIRData.command;
  uint8_t invCmd = ~cmd; // Byte đảo của Command
  return 0xFF000000UL | ((uint32_t)cmd << 8) | invCmd;
}

void translateIR() {
  uint32_t fullCode = getFullHexCode();

  switch (fullCode) {
    case 0xFF006897: // Nút 0
      stateledPin3 = !stateledPin3;
      digitalWrite(ledPin[0], stateledPin3);
      break;

    case 0xFF0030CF: // Nút 1
      stateledPin4 = !stateledPin4;
      digitalWrite(ledPin[1], stateledPin4);
      break;

    case 0xFF0018E7: // Nút 2
      stateledPin5 = !stateledPin5;
      digitalWrite(ledPin[2], stateledPin5);
      break;

    case 0xFF007A85: // Nút 3
      stateledPin6 = !stateledPin6;
      digitalWrite(ledPin[3], stateledPin6);
      break;

    case 0xFF0010EF: // Nút 4
      stateledPin7 = !stateledPin7;
      digitalWrite(ledPin[4], stateledPin7);
      break;

    case 0xFF0038C7: // Nút 5
      stateledPin9 = !stateledPin9;
      digitalWrite(ledPin[5], stateledPin9);
      break;

    case 0xFF005AA5: // Nút 6
      stateledPin10 = !stateledPin10;
      digitalWrite(ledPin[6], stateledPin10);
      break;

    case 0xFF0042BD: // Nút 7
      stateledPin11 = !stateledPin11;
      digitalWrite(ledPin[7], stateledPin11);
      break;

    case 0xFF004AB5: // Nút 8
      stateledPin12 = !stateledPin12;
      digitalWrite(ledPin[8], stateledPin12);
      break;

    case 0xFF0052AD: // Nút 9
      stateledPin13 = !stateledPin13;
      digitalWrite(ledPin[9], stateledPin13);
      break;
  }
}

void loop() {
  if (IrReceiver.decode()) {
    translateIR();
    Serial.print("Toi la bede, so bao danh la 0x");
    Serial.println(getFullHexCode(), HEX);
    
    IrReceiver.resume(); // Nhận tín hiệu tiếp theo
  }
}