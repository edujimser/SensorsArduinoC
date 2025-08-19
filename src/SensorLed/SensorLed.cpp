#include "sensors_Led/sensor_Led.h"
#include "pinout/pinout.h"
#include "msg/msg.h"

/**
 * @brief Constructor de la clase LedBasicoDigital.
 * 
 * Inicializa el pin como salida digital.
 * 
 * @param p Número de pin digital al que está conectado el LED.
 */
LedBasicoDigital::LedBasicoDigital(uint8_t p) : 
    pin(p)
    {
        if(isPinInGPIO(pin) == false){
            standardErrorMessage("El pin no existe en la configuración de PinGIO", __FILE__, __FUNCTION__, __DATE__, __TIME__, __LINE__);
            return;
        }

        pinMode(pin, OUTPUT);
    }

/**
 * @brief Enciende el LED.
 * 
 * Establece el pin en estado HIGH.
 */
void LedBasicoDigital::on() {
    digitalWrite(pin, HIGH);
}

/**
 * @brief Apaga el LED.
 * 
 * Establece el pin en estado LOW.
 */
void LedBasicoDigital::off() {
    digitalWrite(pin, LOW);
}

/**
 * @brief Conmuta el estado del LED.
 * 
 * Si el LED está encendido, lo apaga; si está apagado, lo enciende.
 */
void LedBasicoDigital::conmutacionEstado() {
    digitalWrite(pin, !digitalRead(pin));
}

void LedBasicoDigital::conmutacionEstadoPorTiempo(unsigned long tiempoAlternacia) {
    static unsigned long lastToggleTime = 0;

    if (millis() - lastToggleTime >= tiempoAlternacia) {
        conmutacionEstado();
        lastToggleTime = millis();
    };
}

/**
 * @brief Constructores de las clases LedRojo, LedVerde y LedAzul.
 * 
 * Cada clase hereda de LedBasicoDigital e inicializa el pin digital correspondiente
 * para controlar un LED de color específico.
 * 
 * @param pin Número de pin digital al que está conectado el LED.
 */
LedRojo::LedRojo(uint8_t pin) : LedBasicoDigital(pin) {}
LedVerde::LedVerde(uint8_t pin) : LedBasicoDigital(pin) {}
LedAzul::LedAzul(uint8_t pin) : LedBasicoDigital(pin) {}