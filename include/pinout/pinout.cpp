#include <Arduino.h>
#include "pinout.h"
/**
 * @brief Verifica si un pin digital configurado como salida puede establecer el estado HIGH correctamente.
 * 
 * @param pin Número físico del pin (ej. 22).
 * @param nombre Nombre simbólico del pin (ej. "PIN_GPIO_22").
 * 
 * Imprime por Serial el resultado de la prueba incluyendo el nombre descriptivo y el número.
 */
void checkDigitalOutput(uint8_t pin, const char* nombre) {
  pinMode(pin, OUTPUT);
  digitalWrite(pin, HIGH);
  delay(10);

  if (digitalRead(pin) == HIGH) {
    Serial.print("✅ Salida OK → ");
  } else {
    Serial.print("❌ Falla en salida → ");
  }

  Serial.print(nombre);   // Ej: "PIN_GPIO_22"
  Serial.print(" [Pin ");
  Serial.print(pin);      // Ej: 22
  Serial.println("]");
}

/**
 * @brief Verifica el estado lógico de un pin configurado como entrada digital con resistencia interna (pull-up).
 * 
 * @param pin Número físico del pin (ej. 2).
 * @param nombre Nombre simbólico del pin (ej. "INT_0").
 * 
 * Configura el pin como entrada usando resistencia pull-up.
 * Imprime por Serial el estado actual del pin (HIGH o LOW), junto con su nombre y número.
 */
void checkDigitalInput(uint8_t pin, const char* nombre) {
  pinMode(pin, INPUT_PULLUP);  // Evita estados flotantes
  delay(10);
  int value = digitalRead(pin);

  Serial.print("🔍 Entrada → ");
  Serial.print(nombre);        // Ej: "INT_0"
  Serial.print(" [Pin ");
  Serial.print(pin);           // Ej: 2
  Serial.print("] → Estado: ");
  Serial.println(value == HIGH ? "HIGH" : "LOW");
}


/**
 * @brief Configura un pin como salida PWM y genera una señal con ciclo de trabajo al 50% (valor medio).
 * 
 * @param pin Número físico del pin con capacidad PWM (ej. 5).
 * @param nombre Nombre simbólico del pin (ej. "PIN_PWM_5").
 * 
 * Envía una señal PWM con analogWrite al 50% de intensidad.
 * Imprime por Serial confirmación del pin PWM configurado, con nombre y número.
 */
void checkPWM(uint8_t pin, const char* nombre) {
  pinMode(pin, OUTPUT);
  analogWrite(pin, 128);  // 128 sobre 255 → 50% de ciclo
  delay(10);

  Serial.print("🌀 PWM activo → ");
  Serial.print(nombre);     // Ej: "PIN_PWM_5"
  Serial.print(" [Pin ");
  Serial.print(pin);        // Ej: 5
  Serial.println("]");
}