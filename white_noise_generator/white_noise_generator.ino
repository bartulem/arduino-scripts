/* 

white_noise_generator.ino

This arduino sketch generates white noise to be played on a speaker for 5s upon clicking the "+" button on the
infrared receiver controller and sends the sound ON/OFF state to another device.

@bartulem 2020

*/

#include <IRremote.h>
#define speakerPin 8
#define soundPin 2

boolean flag = true;
const int RECV_PIN = 7;
unsigned long key = 0;
int state = 0;

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup(){
  Serial.begin(115200);
  pinMode(speakerPin, OUTPUT);
  pinMode(soundPin, OUTPUT);
  irrecv.enableIRIn();
  irrecv.blink13(true);
}

void loop(){
  if (irrecv.decode(&results)){
    key = results.value;
    // the "+" sign code is 0xFFA857
    if (key == 0xFFA857){
      state = 1;
    }
    irrecv.resume();
  }
  if (state == 1) {
    // a loop of length 1230 lasts five seconds
    for (int i=0; i<1230; i++){ 
      digitalWrite(speakerPin, HIGH);
      delayMicroseconds(random(1000, 3000));
      digitalWrite(speakerPin, LOW);
      delayMicroseconds(random(1000, 3000));
      digitalWrite(soundPin, HIGH);
    }
    state = 0;
  } 
  digitalWrite(soundPin, LOW);
}
