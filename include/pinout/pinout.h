#ifndef PINS_H
#define PINS_H

#include <Arduino.h>

/*
 * 📌 Estructura para representar pines con nombre y número
 */
struct PinInfo {
    const char* nombre;  // Nombre simbólico del pin
    int numero;          // Número físico del pin en la placa
};

/*
 * 📦 Namespace Pins: Agrupa todos los arrays de pines y funciones basicas
 */
namespace Pins {

    /*
     * 🔗 UART: Comunicación serial asíncrona
     */
    inline const PinInfo UART_RX[] = {
        {"PIN_RX0", 0},    // RX0: UART0 por USB (Serial.begin)
        {"PIN_RX1", 19},   // RX1: UART1 + interrupción INT4 (comunicación externa)
        {"PIN_RX2", 17},   // RX2: UART2 (dispositivos adicionales)
        {"PIN_RX3", 15}    // RX3: UART3 (uso extendido en Mega)
    };

    inline const PinInfo UART_TX[] = {
        {"PIN_TX0", 1},    // TX0: UART0 por USB (Serial.print)
        {"PIN_TX1", 18},   // TX1: UART1 + interrupción INT5
        {"PIN_TX2", 16},   // TX2: UART2
        {"PIN_TX3", 14}    // TX3: UART3
    };

    /*
     * 🔄 SPI: Comunicación síncrona maestro-esclavo
     */
    inline const PinInfo SPI[] = {
        {"PIN_MISO", 50},  // MISO: recibe datos del esclavo
        {"PIN_MOSI", 51},  // MOSI: envía datos al esclavo
        {"PIN_SCK", 52},   // SCK: reloj de sincronización
        {"PIN_SS", 53}     // SS: selección de esclavo (debe estar en OUTPUT)
    };

    /*
     * 🔧 I2C / TWI: Comunicación de dos hilos
     */
    inline const PinInfo I2C[] = {
        {"PIN_SDA", 20},   // SDA: línea de datos + interrupción INT3
        {"PIN_SCL", 21}    // SCL: línea de reloj + interrupción INT2
    };

    /*
     * ⚡ Interrupciones externas
     */
    inline const PinInfo INTERRUPTS[] = {
        {"INT_0", 2},    // INT0: botón, sensor, etc.
        {"INT_1", 3},    // INT1: botón, sensor, etc.
        {"INT_2", 21},   // INT2: compartido con SCL
        {"INT_3", 20},   // INT3: compartido con SDA
        {"INT_4", 19},   // INT4: compartido con RX1
        {"INT_5", 18}    // INT5: compartido con TX1
    };

    /*
     * 🌀 PWM: Pines con capacidad de modulación por ancho de pulso
     */
    inline const PinInfo PWM[] = {
        {"PIN_PWM_2", 2},    // PWM + INT0: útil para botones con interrupción
        {"PIN_PWM_3", 3},    // PWM + INT1: servos o sensores con interrupción
        {"PIN_PWM_4", 4},    // PWM estándar: LED, motor
        {"PIN_PWM_5", 5},    // PWM estándar: LED, motor
        {"PIN_PWM_6", 6},    // PWM estándar: LED, motor
        {"PIN_PWM_7", 7},    // PWM estándar: LED, motor
        {"PIN_PWM_8", 8},    // PWM estándar: LED, motor
        {"PIN_PWM_9", 9},    // PWM estándar: LED, motor
        {"PIN_PWM_10", 10},  // PWM + SS SPI: ideal como salida para SPI
        {"PIN_PWM_11", 11},  // PWM estándar: LED, motor
        {"PIN_PWM_12", 12},  // PWM estándar: LED, motor
        {"PIN_PWM_13", 13},  // PWM + LED integrado: útil para pruebas rápidas
        {"PIN_PWM_44", 44},  // PWM extendido (Mega): motores grandes
        {"PIN_PWM_45", 45},  // PWM extendido (Mega): motores grandes
        {"PIN_PWM_46", 46}   // PWM extendido (Mega): motores grandes
    };

    /*
     * 🧩 GPIO: Pines digitales de propósito general
     */
    inline const PinInfo GPIO[] = {
        {"PIN_GPIO_22", 22},  // Digital: entrada/salida general
        {"PIN_GPIO_23", 23},  // Digital: entrada/salida general
        {"PIN_GPIO_24", 24},  // Digital: entrada/salida general
        {"PIN_GPIO_25", 25},  // Digital: entrada/salida general
        {"PIN_GPIO_26", 26},  // Digital: entrada/salida general
        {"PIN_GPIO_27", 27},  // Digital: entrada/salida general
        {"PIN_GPIO_28", 28},  // Digital: entrada/salida general
        {"PIN_GPIO_29", 29},  // Digital: entrada/salida general
        {"PIN_GPIO_30", 30},  // Digital: entrada/salida general
        {"PIN_GPIO_31", 31},  // Digital: entrada/salida general
        {"PIN_GPIO_32", 32},  // Digital: entrada/salida general
        {"PIN_GPIO_33", 33},  // Digital: entrada/salida general
        {"PIN_GPIO_34", 34},  // Digital: entrada/salida general
        {"PIN_GPIO_35", 35},  // Digital: entrada/salida general
        {"PIN_GPIO_36", 36},  // Digital: entrada/salida general
        {"PIN_GPIO_37", 37},  // Digital: entrada/salida general
        {"PIN_GPIO_38", 38},  // Digital: entrada/salida general
        {"PIN_GPIO_39", 39},  // Digital: entrada/salida general
        {"PIN_GPIO_40", 40},  // Digital: entrada/salida general
        {"PIN_GPIO_41", 41},  // Digital: entrada/salida general
        {"PIN_GPIO_42", 42},  // Digital: entrada/salida general
        {"PIN_GPIO_43", 43},  // Digital: entrada/salida general
        {"PIN_GPIO_47", 47},  // Digital: entrada/salida general
        {"PIN_GPIO_48", 48},  // Digital: entrada/salida general
        {"PIN_GPIO_49", 49}   // Digital: entrada/salida general
    };
        

    /*
     * 📏 Tamaños de arrays (para bucles y diagnósticos)
     */
    constexpr size_t NUM_GPIO       = sizeof(GPIO) / sizeof(GPIO[0]);
    constexpr size_t NUM_PWM        = sizeof(PWM) / sizeof(PWM[0]);
    constexpr size_t NUM_UART_RX    = sizeof(UART_RX) / sizeof(UART_RX[0]);
    constexpr size_t NUM_UART_TX    = sizeof(UART_TX) / sizeof(UART_TX[0]);
    constexpr size_t NUM_SPI        = sizeof(SPI) / sizeof(SPI[0]);
    constexpr size_t NUM_I2C        = sizeof(I2C) / sizeof(I2C[0]);
    constexpr size_t NUM_INTERRUPTS = sizeof(INTERRUPTS) / sizeof(INTERRUPTS[0]);
}

/*
 * 🧪 Funciones de diagnóstico de pines
 * Se implementan en pins.cpp
 */

// Configura los pines GPIO como INPUT_PULLUP y detecta si están conectados a masa
void diagnosticarGPIO();

// Configura los pines PWM como OUTPUT y los pone en HIGH para verificar conflictos
void diagnosticarPWM();

// Ejecuta ambos diagnósticos y muestra resultados por Serial
void diagnosticoCompleto();

// Verifica si un pin específico existe en el array de pines GPIO
bool existePinEnPinGIO(int numeroPin);

#endif  // PINS_H
