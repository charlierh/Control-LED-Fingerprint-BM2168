/*
  FastFlashDemo - Demostración de parpadeos rápidos
  Muestra diferentes velocidades de parpadeo
*/

#include <BM2168_LED.h>

BM2168_LED fingerLED(D6, D5);

void setup() {
  Serial.begin(115200);
  fingerLED.begin();
  
  Serial.println("BM2168 Fast Flash Demo");
  Serial.println("Probando diferentes velocidades...");
  delay(2000);
  
  runFastFlashDemo();
}

void loop() {
  // Demo se ejecuta una vez
  delay(1000);
}

void runFastFlashDemo() {
  Serial.println("\n--- Parpadeo Normal (500ms) ---");
  fingerLED.flash(COLOR_RED, 5);  // 500ms por defecto
  delay(6000);
  
  Serial.println("--- Parpadeo Rápido (200ms) ---");
  fingerLED.fastFlash(COLOR_GREEN, 200, 200, 10);
  delay(5000);
  
  Serial.println("--- Parpadeo Muy Rápido (100ms) ---");
  fingerLED.fastFlash(COLOR_BLUE, 100, 100, 15);
  delay(5000);
  
  Serial.println("--- Parpadeo Súper Rápido (50ms) ---");
  fingerLED.fastFlash(COLOR_YELLOW, 50, 50, 20);
  delay(5000);
  
  Serial.println("--- Parpadeo Ultra Rápido (25ms) ---");
  fingerLED.fastFlash(COLOR_CYAN, 25, 25, 25);
  delay(5000);
  
  Serial.println("--- Parpadeo No Bloqueante (75ms) ---");
  unsigned long startTime = millis();
  fingerLED.startFastFlash(COLOR_MAGENTA, 75, 75);
  
  // Mientras parpadea, podemos hacer otras cosas
  while(millis() - startTime < 10000) { // 10 segundos
    fingerLED.update();
    
    // Aquí podrías ejecutar otro código
    Serial.print(".");
    delay(500);
  }
  
  fingerLED.stopFastFlash();
  Serial.println("\nDemo completado!");
}