#include <IRremote.hpp>

const int RECEIVER_PIN = 8;

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(RECEIVER_PIN, ENABLE_LED_FEEDBACK);
  Serial.println("Da san sang nhan tin hieu IR...");
}

void loop() {
  if (IrReceiver.decode()) {
    // In truc tiep ma gia ma 32-bit thô tu Remote
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);

    IrReceiver.resume();
  }
}