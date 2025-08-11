// Include the necessary headers
#include <Arduino.h>
#include "pinout/pinout.h"

/**
 * @brief Diagnóstico de pines digitales (GPIO) configurados como entradas con resistencia pull-up.
 * 
 * Recorre todos los pines definidos como GPIO, los configura como INPUT_PULLUP
 * y verifica si están conectados a masa (lectura LOW). Imprime los resultados por Serial.
 * 
 * @note Este diagnóstico es útil para detectar si un pin está conectado a tierra.
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

/**
 * @brief Diagnóstico de pines PWM configurados como salidas digitales.
 * 
 * Configura cada pin PWM como OUTPUT, lo pone en estado HIGH y verifica si el estado se mantiene.
 * Imprime los resultados por Serial para detectar posibles fallos o conflictos.
 * 
 * @note Este diagnóstico permite verificar si los pines PWM responden correctamente como salidas.
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

/**
 * @brief Ejecuta un diagnóstico completo de los pines digitales (GPIO) y PWM.
 * 
 * Llama a las funciones de diagnóstico individuales para GPIO y PWM,
 * mostrando los resultados por Serial. Útil como prueba inicial del hardware.
 * 
 * @note Ideal para verificar el estado general de los pines al inicio del programa.
 */
void diagnosticoCompleto() {
    Serial.println("🔧 Diagnóstico inicial de pines digitales y PWM\n");

    diagnosticarGPIO();   // Diagnóstico de pines GPIO
    diagnosticarPWM();    // Diagnóstico de pines PWM

    Serial.println("\n✅ Diagnóstico completo.\n");
}

/**
 * @brief Verifica si un número de pin existe en la lista de pines GPIO.
 * 
 * Recorre el arreglo Pins::GPIO y compara el número físico del pin con los definidos.
 * 
 * @param numeroPin Número físico del pin que se desea verificar.
 * @return true Si el pin está presente en la lista GPIO.
 * @return false Si el pin no se encuentra en la lista GPIO.
 */
bool existePinEnPinGIO(int numeroPin) {
    for (const auto& gpio : Pins::GPIO) {
        if (gpio.numero == numeroPin) {
            return true;
        }
    };
    return false;
};