// Link Thinkercad
// https://www.tinkercad.com/things/5iwu0aUMtBo-timer

#include "Adafruit_LEDBackpack.h"
Adafruit_7segment dis = Adafruit_7segment();

int minuto = 0;   // Hora inicial
int segundos = 0;  // Minuto inicial
int time = 0;

void setup() {
 dis.begin(0x70);
}
void loop() {
  while(1){
    time = minuto*100 + segundos;
    dis.println(time);
    delay(1000);
    //delay(60000); // medidor de hora, 60000 milis == 1 minuto
    dis.writeDisplay();
    segundos++;
    if(segundos == 60){
      	minuto++;
      	segundos = 0;
    }
  }
}