/* 
arduino_mouse_chirps.ino

This sketch generates artificial mouse-like chirps to be played on a speaker.

@bartulem 2022
*/

#define speaker 3
int start_freq = 14000;
int max_freq = 15000;
int end_freq = 14300;
int tone_duration_up = 10;
int tone_duration_down = 30;
int initial_delay = 20000;
int ipi_delay = 10000;

void setup()
{
  Serial.begin(115200);
  pinMode(speaker, OUTPUT);
  delay(initial_delay);
}

void loop()
{
  for (int fr=start_freq; fr<max_freq; fr++)
  {
  tone(speaker, fr, tone_duration_up);
  } 
  for (int fr=max_freq; fr>=end_freq; fr--)
  {
  tone(speaker, fr, tone_duration_down);
  } 
delay(ipi_delay);
}
