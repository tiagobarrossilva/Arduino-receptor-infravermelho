#include <IRremote.h>

const byte IR_RECEIVE_PIN = 3;
byte led1 = 4;

void setup(){
  Serial.begin(115200);
  Serial.println("IR Receive test");
  pinMode(led1,OUTPUT);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
}

void loop(){
  if (IrReceiver.decode()){
    Serial.println(IrReceiver.decodedIRData.command, HEX);
    IrReceiver.resume();
    switch(IrReceiver.decodedIRData.command){
      case 0x10:
      	digitalWrite(led1,HIGH);
      break;
       
      case 0xc:
      	digitalWrite(led1,LOW);
      break;
    }         
  }
}