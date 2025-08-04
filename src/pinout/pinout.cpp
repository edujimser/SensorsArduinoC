// Include the necessary headers
#include <Arduino.h>

#include "pinout/pinout.h"
/*
 * 🔍 Diagnóstico de pines GPIO como entradas con pull-up
 * Configura cada pin GPIO como INPUT_PULLUP y verifica si está conectado a masa (LOW)
 */
void diagnosticarGPIO() {
    Serial.println("➡️ Verificando pines digitales (GPIO):");

    for (size_t i = 0; i < Pins::NUM_GPIO; ++i) {
        const PinInfo& pin = Pins::GPIO[i];  // Acceso directo al pin actual

        pinMode(pin.numero, INPUT_PULLUP);   // Configura como entrada con resistencia pull-up
        delay(5);                            // Breve espera para estabilizar lectura
        int estado = digitalRead(pin.numero); // Lee el estado del pin

        // Muestra el resultado por Serial
        Serial.print("🔍 ");
        Serial.print(pin.nombre);
        Serial.print(" [Pin ");
        Serial.print(pin.numero);
        Serial.print("] → Estado: ");
        Serial.println(estado == LOW ? "Conectado a masa (LOW)" : "Sin carga (HIGH)");
    }
}

/*
 * 🌀 Diagnóstico de pines PWM como salidas
 * Configura cada pin PWM como OUTPUT, lo pone en HIGH y verifica si el estado se mantiene
 */
void diagnosticarPWM() {
    Serial.println("\n➡️ Verificando pines PWM:");

    for (size_t i = 0; i < Pins::NUM_PWM; ++i) {
        const PinInfo& pin = Pins::PWM[i];  // Acceso directo al pin actual

        pinMode(pin.numero, OUTPUT);        // Configura como salida
        digitalWrite(pin.numero, HIGH);     // Pone el pin en estado alto
        delay(5);                           // Breve espera para estabilizar lectura
        int estado = digitalRead(pin.numero); // Lee el estado del pin

        // Muestra el resultado por Serial
        Serial.print("🌀 ");
        Serial.print(pin.nombre);
        Serial.print(" [Pin ");
        Serial.print(pin.numero);
        Serial.print("] → Estado: ");
        Serial.println(estado == HIGH ? "Funciona correctamente" : "Falla o conflicto");
    }
}

/*
 * 🧭 Diagnóstico completo
 * Ejecuta diagnóstico de GPIO y PWM, mostrando resultados por Serial
 */
void diagnosticoCompleto() {
    Serial.println("🔧 Diagnóstico inicial de pines digitales y PWM\n");

    diagnosticarGPIO();   // Diagnóstico de pines GPIO
    diagnosticarPWM();    // Diagnóstico de pines PWM

    Serial.println("\n✅ Diagnóstico completo.\n");
}