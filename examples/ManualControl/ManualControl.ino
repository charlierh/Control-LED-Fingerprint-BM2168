/*
  CommandTester - Utilidad para probar comandos
  Útil para debugging y desarrollo
*/

#include <BM2168_LED.h>

BM2168_LED fingerLED(D6, D5);

void setup() {
  Serial.begin(115200);
  fingerLED.begin();
  
  Serial.println("BM2168 Command Tester");
  Serial.println("Comandos: r=Rojo, g=Verde, b=Azul, y=Amarillo, c=Cian, m=Magenta, w=Blanco, 0=Apagar");
  Serial.println("Efectos: 1=Breathing, 2=Flashing, 3=Rainbow, 4=Fast Flashing red (100ms), 5=Fast Flashing blue (50ms), 6=Non-blocking green blink (75ms) - use '7' to stop, 7=Flashing stoped, 8=Adafruit Sintaxis");
  Serial.println("IMPORTANTE: La opción 6 (Non-blocking) necesita update() en loop");   // ✅ CRÍTICO: Actualizar efectos no bloqueantes fingerLED.update();
}

void loop() {
  // ✅ CRÍTICO: Actualizar efectos no bloqueantes
  fingerLED.update();
  
  if (Serial.available()) {
    char command = Serial.read();
    
    switch(command) {
      case 'r': 
        fingerLED.setColor(COLOR_RED); 
        Serial.println("🔴 Rojo fijo");
        break;
      case 'g': 
        fingerLED.setColor(COLOR_GREEN); 
        Serial.println("🟢 Verde fijo");
        break;
      case 'b': 
        fingerLED.setColor(COLOR_BLUE); 
        Serial.println("🔵 Azul fijo");
        break;
      case 'y': 
        fingerLED.setColor(COLOR_YELLOW); 
        Serial.println("🟡 Amarillo fijo");
        break;
      case 'c': 
        fingerLED.setColor(COLOR_CYAN); 
        Serial.println("🔷 Cian fijo");
        break;
      case 'm': 
        fingerLED.setColor(COLOR_MAGENTA); 
        Serial.println("🟣 Magenta fijo");
        break;
      case 'w': 
        fingerLED.setColor(COLOR_WHITE); 
        Serial.println("⚪ Blanco fijo");
        break;
      case '0': 
        fingerLED.off(); 
        Serial.println("⚫ Apagado");
        break;
      case '1': 
        fingerLED.breathing(COLOR_BLUE, 0); 
        Serial.println("💙 Respiración azul (infinito)");
        break;
      case '2': 
        fingerLED.flash(COLOR_RED, 10); 
        Serial.println("🔴 Parpadeo rojo nativo (10 ciclos)");
        break;
      case '3': 
        fingerLED.rainbow(300); 
        Serial.println("🌈 Arcoíris cada 300ms");
        break;
      case '4': 
        fingerLED.fastFlash(COLOR_RED, 100, 100, 10); 
        Serial.println("🔴 FastFlash rojo (100ms, 10 veces)");
        break;
      case '5': 
        fingerLED.fastFlash(COLOR_BLUE, 50, 50, 15); 
        Serial.println("🔵 FastFlash azul (50ms, 15 veces)");
        break;
      case '6': 
        fingerLED.startFastFlash(COLOR_GREEN, 75, 75);
        Serial.println("🟢 Non-blocking verde (75ms) - ENCIENDE");
        Serial.println("   Usa '7' para detener");
        break;
      case '7': 
        fingerLED.stopFastFlash();
        Serial.println("⏹️  Non-blocking DETENIDO");
        break;
      case '8': 
        fingerLED.ledControl(FINGERPRINT_LED_FLASHING, 50, FINGERPRINT_LED_RED, 5);
        Serial.println("🎛️  Sintaxis Adafruit: Parpadeo rápido rojo");
        break;
      default: 
        Serial.println("❌ Comando no reconocido");
        break;
    }
  }
  
  delay(10); // Pequeña pausa para estabilidad
}