#ifndef PINS_H
#define PINS_H

#include <Arduino.h>

/*
 * 📌 Structure to represent pins with symbolic name and physical number
 */
struct PinInfo {
    const char* name;  // Symbolic name of the pin
    int number;        // Physical pin number on the board

    // Constructor constexpr para permitir uso en evaluaciones de tiempo de compilación
    constexpr PinInfo(const char* n, int num) : name(n), number(num) {}

};

/*
 * 📦 Namespace Pins: Groups all pin arrays and basic functions
 */
namespace Pins {

    /*
     * 🔗 UART: Asynchronous serial communication
     */
  inline constexpr PinInfo UART_RX[] = {
        {"PIN_RX0", 0},    // RX0: UART0 via USB (Serial.begin)
        {"PIN_RX1", 19},   // RX1: UART1 + INT4 interrupt (external communication)
        {"PIN_RX2", 17},   // RX2: UART2 (additional devices)
        {"PIN_RX3", 15}    // RX3: UART3 (extended use on Mega)
    };


    inline constexpr PinInfo UART_TX[] = {
        {"PIN_TX0", 1},    // TX0: UART0 via USB (Serial.print)
        {"PIN_TX1", 18},   // TX1: UART1 + INT5 interrupt
        {"PIN_TX2", 16},   // TX2: UART2
        {"PIN_TX3", 14}    // TX3: UART3
    };

    /*
     * 🔄 SPI: Synchronous master-slave communication
     */
    inline constexpr PinInfo SPI[] = {
        {"PIN_MISO", 50},  // MISO: receives data from slave
        {"PIN_MOSI", 51},  // MOSI: sends data to slave
        {"PIN_SCK", 52},   // SCK: clock signal
        {"PIN_SS", 53}     // SS: slave select (must be OUTPUT)
    };

    /*
     * 🔧 I2C / TWI: Two-wire communication
     */
    inline constexpr PinInfo I2C[] = {
        {"PIN_SDA", 20},   // SDA: data line + INT3 interrupt
        {"PIN_SCL", 21}    // SCL: clock line + INT2 interrupt
    };

    /*
     * ⚡ External interrupts
     */
    inline constexpr PinInfo INTERRUPTS[] = {
        {"INT_0", 2},    // INT0: button, sensor, etc.
        {"INT_1", 3},    // INT1: button, sensor, etc.
        {"INT_2", 21},   // INT2: shared with SCL
        {"INT_3", 20},   // INT3: shared with SDA
        {"INT_4", 19},   // INT4: shared with RX1
        {"INT_5", 18}    // INT5: shared with TX1
    };

    /*
    * 🎯 ANALOG: Pins with analog input capability (ADC)
    */
    inline constexpr PinInfo ANALOG[] = {
        {"PIN_ANALOG_A00", 54},   // A0: general analog input
        {"PIN_ANALOG_A01", 55},   // A1: general analog input
        {"PIN_ANALOG_A02", 56},   // A2: general analog input
        {"PIN_ANALOG_A03", 57},   // A3: general analog input
        {"PIN_ANALOG_A04", 58},   // A4: general analog input
        {"PIN_ANALOG_A05", 59},   // A5: general analog input
        {"PIN_ANALOG_A06", 60},   // A6: general analog input
        {"PIN_ANALOG_A07", 61},   // A7: general analog input
        {"PIN_ANALOG_A08", 62},   // A8: extended analog input (Mega only)
        {"PIN_ANALOG_A90", 63},   // A9: extended analog input (Mega only)
        {"PIN_ANALOG_A10", 64},  // A10: extended analog input (Mega only)
        {"PIN_ANALOG_A11", 65},  // A11: extended analog input (Mega only)
        {"PIN_ANALOG_A12", 66},  // A12: extended analog input (Mega only)
        {"PIN_ANALOG_A13", 67},  // A13: extended analog input (Mega only)
        {"PIN_ANALOG_A14", 68},  // A14: extended analog input (Mega only)
        {"PIN_ANALOG_A15", 69}   // A15: extended analog input (Mega only)
    };

    /*
     * 🌀 PWM: Pins with pulse-width modulation capability
     */
    inline constexpr PinInfo PWM[] = {
        {"PIN_PWM_02", 2},    // PWM + INT0: useful for buttons with interrupt
        {"PIN_PWM_03", 3},    // PWM + INT1: servos or sensors with interrupt
        {"PIN_PWM_04", 4},    // Standard PWM: LED, motor
        {"PIN_PWM_05", 5},    // Standard PWM: LED, motor
        {"PIN_PWM_06", 6},    // Standard PWM: LED, motor
        {"PIN_PWM_07", 7},    // Standard PWM: LED, motor
        {"PIN_PWM_08", 8},    // Standard PWM: LED, motor
        {"PIN_PWM_09", 9},    // Standard PWM: LED, motor
        {"PIN_PWM_10", 10},  // PWM + SPI SS: ideal as SPI output
        {"PIN_PWM_11", 11},  // Standard PWM: LED, motor
        {"PIN_PWM_12", 12},  // Standard PWM: LED, motor
        {"PIN_PWM_44", 44},  // Extended PWM (Mega): large motors
        {"PIN_PWM_45", 45},  // Extended PWM (Mega): large motors
        {"PIN_PWM_46", 46}   // Extended PWM (Mega): large motors
    };

    /*
     * 🧩 GPIO: General-purpose digital pins
     */
    inline constexpr PinInfo GPIO[] = {
        {"PIN_GPIO_13", 13},  // Digital: general input/output PWM13 'Note: this pin is digital' input/output 0
        {"PIN_GPIO_22", 22},  // Digital: general input/output 1
        {"PIN_GPIO_23", 23},  // Digital: general input/output 2
        {"PIN_GPIO_24", 24},  // Digital: general input/output 3
        {"PIN_GPIO_25", 25},  // Digital: general input/output 4
        {"PIN_GPIO_26", 26},  // Digital: general input/output 5
        {"PIN_GPIO_27", 27},  // Digital: general input/output 6
        {"PIN_GPIO_28", 28},  // Digital: general input/output 7
        {"PIN_GPIO_29", 29},  // Digital: general input/output 8
        {"PIN_GPIO_30", 30},  // Digital: general input/output 9
        {"PIN_GPIO_31", 31},  // Digital: general input/output 10
        {"PIN_GPIO_32", 32},  // Digital: general input/output 11 
        {"PIN_GPIO_33", 33},  // Digital: general input/output 12
        {"PIN_GPIO_34", 34},  // Digital: general input/output 13
        {"PIN_GPIO_35", 35},  // Digital: general input/output 14
        {"PIN_GPIO_36", 36},  // Digital: general input/output 15
        {"PIN_GPIO_37", 37},  // Digital: general input/output 16
        {"PIN_GPIO_38", 38},  // Digital: general input/output 17
        {"PIN_GPIO_39", 39},  // Digital: general input/output 18
        {"PIN_GPIO_40", 40},  // Digital: general input/output 19 
        {"PIN_GPIO_41", 41},  // Digital: general input/output 20
        {"PIN_GPIO_42", 42},  // Digital: general input/output 21
        {"PIN_GPIO_43", 43},  // Digital: general input/output 22
        {"PIN_GPIO_44", 44},  // Digital: general input/output 23
        {"PIN_GPIO_45", 45},  // Digital: general input/output 24
        {"PIN_GPIO_46", 46},  // Digital: general input/output 25
        {"PIN_GPIO_47", 47},  // Digital: general input/output 26
        {"PIN_GPIO_48", 48},  // Digital: general input/output 27
        {"PIN_GPIO_49", 49}   // Digital: general input/output 2189
    };

    /*
     * 📏 Array sizes (for loops and diagnostics)
     */
    constexpr size_t NUM_ANALOG     = sizeof(ANALOG) / sizeof(ANALOG[0]);
    constexpr size_t NUM_GPIO       = sizeof(GPIO) / sizeof(GPIO[0]);
    constexpr size_t NUM_PWM        = sizeof(PWM) / sizeof(PWM[0]);
    constexpr size_t NUM_UART_RX    = sizeof(UART_RX) / sizeof(UART_RX[0]);
    constexpr size_t NUM_UART_TX    = sizeof(UART_TX) / sizeof(UART_TX[0]);
    constexpr size_t NUM_SPI        = sizeof(SPI) / sizeof(SPI[0]);
    constexpr size_t NUM_I2C        = sizeof(I2C) / sizeof(I2C[0]);
    constexpr size_t NUM_INTERRUPTS = sizeof(INTERRUPTS) / sizeof(INTERRUPTS[0]);
}

/*
 * 🧪 Pin diagnostic functions
 * Implemented in pins.cpp
 */

// Configures ANALOG  pins as INPUT and detects if voltage is present and it porcent
void diagnoseAnalog();
// Configures GPIO  pins as INPUT and detects if voltage is present
void diagnoseGPIO();
// Configures PWM pins as INPUT and detects if voltage is present
void diagnosePWM();
// Runs both diagnostics and prints results via Serial
void fullDiagnosticsPins();
// Checks if a specific pin exists in the GPIO array
bool isPinInGPIO(int pinNumber);

#endif  // PINS_H
