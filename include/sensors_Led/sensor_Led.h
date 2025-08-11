#ifndef SENSOR_LED_H
#define SENSOR_LED_H

#include <Arduino.h>

/**
 * @brief Clase base para LEDs digitales simples.
 * 
 * Proporciona métodos para encender, apagar y alternar el estado de un LED conectado a un pin digital.
 */
class LedBasicoDigital {
protected:
    uint8_t pin; /**< Pin digital al que está conectado el LED */

public:
    /**
     * @brief Constructor de la clase LedBasicoDigital.
     * 
     * Configura el pin como salida.
     * 
     * @param pin Número de pin digital donde está conectado el LED.
     */
    LedBasicoDigital(uint8_t pin);

    /**
     * @brief Enciende el LED.
     * 
     * Pone el pin en estado HIGH.
     */
    void on();

    /**
     * @brief Apaga el LED.
     * 
     * Pone el pin en estado LOW.
     */
    void off();

    /**
     * @brief Alterna el estado del LED.
     * 
     * Si el LED está encendido, lo apaga. Si está apagado, lo enciende.
     */
    void conmutacionEstado();

     /**
     * @brief Produce una alternacia de estado por tiempo.
     * 
     * Si el LED está encendido, lo apaga. Si está apagado, lo enciende, de forma automatica en un tiempo
     */

    void conmutacionEstadoPorTiempo(unsigned long tiempoAlternacia);
};

/**
 * @brief Clase para controlar un LED rojo.
 * 
 * Hereda de LedBasicoDigital.
 */
class LedRojo : public LedBasicoDigital {
public:
    /**
     * @brief Constructor de la clase LedRojo.
     * 
     * @param pin Número de pin digital donde está conectado el LED rojo.
     */
    LedRojo(uint8_t pin);
};

/**
 * @brief Clase para controlar un LED verde.
 * 
 * Hereda de LedBasicoDigital.
 */
class LedVerde : public LedBasicoDigital {
public:
    /**
     * @brief Constructor de la clase LedVerde.
     * 
     * @param pin Número de pin digital donde está conectado el LED verde.
     */
    LedVerde(uint8_t pin);
};

/**
 * @brief Clase para controlar un LED azul.
 * 
 * Hereda de LedBasicoDigital.
 */
class LedAzul : public LedBasicoDigital {
public:
    /**
     * @brief Constructor de la clase LedAzul.
     * 
     * @param pin Número de pin digital donde está conectado el LED azul.
     */
    LedAzul(uint8_t pin);
};

#endif // SENSOR_LED_H