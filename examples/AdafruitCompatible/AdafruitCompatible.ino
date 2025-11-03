/*
  AdafruitCompatible - Demostración de sintaxis estilo Adafruit
  Muestra cómo usar la librería con sintaxis familiar
*/

#include <BM2168_LED.h>

BM2168_LED finger(D6, D5);

void setup() {
  Serial.begin(115200);
  finger.begin();
  
  Serial.println("BM2168 - Modo Compatible con Adafruit");
  Serial.println("Usando sintaxis: ledControl(mode, speed, color, cycles)");
  delay(2000);
  
  runAdafruitStyleDemo();
}

void loop() {
  // Demo se ejecuta una vez
  delay(1000);
}

void runAdafruitStyleDemo() {
  Serial.println("\n1. Parpadeo rápido rojo (50ms)");
  finger.ledControl(FINGERPRINT_LED_FLASHING, 50, FINGERPRINT_LED_RED, 5);
  delay(3000);
  
  Serial.println("2. Parpadeo medio azul (200ms)");
  finger.ledControl(FINGERPRINT_LED_FLASHING, 200, FINGERPRINT_LED_BLUE, 5);
  delay(3000);
  
  Serial.println("3. Parpadeo lento verde (500ms)");
  finger.ledControl(FINGERPRINT_LED_FLASHING, 500, FINGERPRINT_LED_GREEN, 5);
  delay(3000);
  
  Serial.println("4. Respiración azul (2 segundos por ciclo)");
  finger.ledControl(FINGERPRINT_LED_BREATHING, 2000, FINGERPRINT_LED_BLUE, 3);
  delay(7000);
  
  Serial.println("5. Encendido fijo blanco");
  finger.ledControl(FINGERPRINT_LED_ON, 0, FINGERPRINT_LED_WHITE, 0);
  delay(2000);
  
  Serial.println("6. Apagar");
  finger.ledControl(FINGERPRINT_LED_OFF, 0, FINGERPRINT_LED_RED, 0);
  
  Serial.println("Demo completado!");
}