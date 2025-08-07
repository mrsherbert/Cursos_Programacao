// Link Thinkercad
// https://www.tinkercad.com/things/5iwu0aUMtBo-timer

#include "Adafruit_LEDBackpack.h"
Adafruit_7segment dis = Adafruit_7segment();

int hora = 0;   // Hora inicial
int minuto = 0;  // Minuto inicial
int time = 0;

void setup() {
 dis.begin(0x70);
}
void loop() {
  while(1){
    time = hora*100 + minuto;
    dis.println(time);
    delay(1000);
    //delay(60000); // medidor de hora, 60000 milis == 1 minuto
    dis.writeDisplay();
    minuto++;
    if(minuto == 60){
      	hora++;
      	minuto = 0;
    }
    if(hora == 13){
      	hora = 0;
    }
  }
}