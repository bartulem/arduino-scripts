/* 
sound_with_lights.ino

This sketch generates square wave tones with blinking LED output.

@bartulem 2022
*/

#define output_pin 7
#define speaker 13
#define N_PINS 3
const int pins[N_PINS] = {2, 3, 4};
int freq = 800;
int initial_delay = 2000;
int ipi_delay = 3000;
int tone_delay = 2000; 
unsigned long on_time;
unsigned long off_time;

void setup()
{
  Serial.begin(115200);
  for(int i=0; i<N_PINS; i++) {
    pinMode(pins[i], OUTPUT);
    digitalWrite(pins[i], LOW);
  }
  pinMode(speaker, OUTPUT);
  pinMode(output_pin, OUTPUT);
  digitalWrite(output_pin, LOW);
  delay(initial_delay);
}

void loop()
{
  on_time = millis();
  while (millis()-on_time <= tone_delay) {
    for(int i=0; i<N_PINS; i++){digitalWrite(pins[i], HIGH);}
    digitalWrite(output_pin, HIGH);
    tone(speaker, freq);
  }
  
  off_time = millis();
  while (millis()-off_time <= ipi_delay) {
    for(int i=0; i<N_PINS; i++){digitalWrite(pins[i], LOW);}
    digitalWrite(output_pin, LOW);
    noTone(speaker);
    } 
}
