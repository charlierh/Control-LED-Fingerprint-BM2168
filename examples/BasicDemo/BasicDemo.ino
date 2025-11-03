/*
  BasicDemo - Ejemplo básico para BM2168 LED Control
  Demuestra los efectos básicos del LED.
*/

#include <BM2168_LED.h>

// Definir pines (RX, TX) - Conectar D6 a TX del sensor, D5 a RX del sensor
BM2168_LED fingerLED(D6, D5);

void setup() {
  Serial.begin(115200);
  fingerLED.begin();
  
  Serial.println("BM2168 LED Control - Basic Demo");
  
  // Esperar 2 segundos antes de empezar
  delay(2000);
  
  // Encender en rojo
  fingerLED.setColor(0x04); // Rojo
  delay(2000);
  
  // Respiración azul por 3 ciclos
  fingerLED.breathing(0x01, 3); // Azul, 3 ciclos
  delay(10000); // Esperar a que termine la respiración (aprox 10 segundos)
  
  // Parpadeo verde 5 veces
  fingerLED.flash(0x02, 5); // Verde, 5 ciclos
  delay(6000); // 5 ciclos * ~1 segundo cada uno
  
  // Apagar
  fingerLED.off();
}

void loop() {
  // No hacer nada en loop
}