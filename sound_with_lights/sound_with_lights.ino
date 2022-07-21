/* 
sound_with_lights.ino

This sketch generates square wave tones with blinking LED output.

@bartulem 2022
*/

#define output_pin 13
#define speaker 3
#define N_PINS 3
const int pins[N_PINS] = {2, 3, 4};
int tone_duration = 2;
int freq = 800;
int initial_delay = 10000;
int ipi_delay = 5000;
unsigned long start_time;

void setup()
{
  Serial.begin(115200);
  pinMode(speaker, OUTPUT);
  for(int i=0; i<N_PINS; i++) {
    pinMode(pins[i], OUTPUT);
    digitalWrite(pins[i], LOW);
  }
  delay(initial_delay);
}

void loop()
{
  start_time = millis();
  if( (millis() - start_time) <= tone_duration*1000){
    tone(speaker, freq);
    for(int i=0; i<N_PINS; i++) {
      digitalWrite(pins[i], HIGH);
    }
    digitalWrite(output_pin, HIGH);
  }
  for(int i=0; i<N_PINS; i++) {
    digitalWrite(pins[i], LOW);
  }
  digitalWrite(output_pin, LOW);
  
delay(ipi_delay);
}
