/*
  AdvancedEffects - Efectos LED Avanzados para BM2168
  ==================================================
  
  🎭 EFECTOS DEMOSTRADOS:
  
  1. TRANSICIONES DE COLORES
     - Cambio suave entre colores del arcoíris
     - Usa efecto breathing para transiciones fluidas
     
  2. EFECTO POLICÍA/ALARMA  
     - Alternancia rápida Rojo ↔ Azul
     - Ideal para alertas visuales
     
  3. RESPIRACIÓN MULTICOLOR
     - Ciclo de respiración en diferentes colores
     - Rojo → Verde → Azul
     
  4. ARCOÍRIS CONTINUO
     - Rotación infinita de colores (en loop)
     - Perfecto para modo "standby" o decoración
  
  💡 USO PRÁCTICO:
  - Modo alarma/notificación
  - Indicadores de estado avanzados
  - Efectos decorativos
  - Demostración de capacidades del sensor
  
  🔄 AL TERMINAR LA SECUENCIA:
  - El sketch cambia a modo ARCOÍRIS CONTINUO
  - Los colores rotan automáticamente cada 500ms
*/

#include <BM2168_LED.h>

BM2168_LED fingerLED(D6, D5);

void setup() {
  Serial.begin(115200);
  fingerLED.begin();
  
  Serial.println("🎭 BM2168 Advanced Effects Demo");
  Serial.println("=================================");
  Serial.println("Iniciando secuencia de efectos avanzados...");
  Serial.println("1. Transiciones de colores");
  Serial.println("2. Efecto policía/alarma"); 
  Serial.println("3. Respiración multicolor");
  Serial.println("4. Arcoíris continuo (modo automático)");
  Serial.println("=================================");
  delay(2000);
  
  runAdvancedDemo();
}

void loop() {
  // 🔄 Después de la demo, modo arcoíris continuo
  fingerLED.rainbow(500);  // Cambia color cada 500ms
}

void runAdvancedDemo() {
  Serial.println("\n🎨 1. TRANSICIONES DE COLORES...");
  smoothColorTransition();
  delay(1000);
  
  Serial.println("🚨 2. EFECTO POLICÍA/ALARMA...");
  policeEffect(); 
  delay(1000);
  
  Serial.println("🌈 3. RESPIRACIÓN MULTICOLOR...");
  multiColorBreathing();
  delay(1000);
  
  Serial.println("🔄 4. INICIANDO ARCOÍRIS CONTINUO...");
  Serial.println("    (Los colores rotarán automáticamente)");
  Serial.println("=================================");
}

void smoothColorTransition() {
  uint8_t colors[] = {COLOR_RED, COLOR_YELLOW, COLOR_GREEN, COLOR_CYAN, COLOR_BLUE, COLOR_MAGENTA};
  const char* colorNames[] = {"Rojo", "Amarillo", "Verde", "Cian", "Azul", "Magenta"};
  
  for(int i = 0; i < 6; i++) {
    Serial.print("   → Transición a: ");
    Serial.println(colorNames[i]);
    
    // Efecto breathing para transición suave
    fingerLED.breathing(colors[i], 1);
    delay(4000);  // 4 segundos por transición
  }
}

void policeEffect() {
  Serial.println("   🔴 Azul ↔ Rojo (alternancia rápida)");
  
  for(int i = 0; i < 10; i++) {
    fingerLED.setColor(COLOR_RED);
    delay(200);  // 200ms rojo
    fingerLED.setColor(COLOR_BLUE);
    delay(200);  // 200ms azul
  }
  
  fingerLED.off();
  delay(500);
}

void multiColorBreathing() {
  Serial.println("   🔴 Respiración Roja...");
  fingerLED.breathing(COLOR_RED, 2);
  delay(5000);
  
  Serial.println("   🟢 Respiración Verde...");  
  fingerLED.breathing(COLOR_GREEN, 2);
  delay(5000);
  
  Serial.println("   🔵 Respiración Azul...");
  fingerLED.breathing(COLOR_BLUE, 2);
  delay(5000);
  
  fingerLED.off();
}