// Include the necessary headers
#include <Arduino.h>
#include "pinout/pinout.h"

/**
 * @brief Diagnostic for digital GPIO pins configured as input with pull-up resistor.
 * 
 * Iterates through all defined GPIO pins, configures them as INPUT_PULLUP,
 * and checks if they are connected to ground (LOW reading). Prints results via Serial.
 * 
 * @note Useful for detecting if a pin is grounded.
 */
void diagnoseGPIO() {
    Serial.println("➡️ Checking digital pins (GPIO):");

    for (size_t i = 0; i < Pins::NUM_GPIO; ++i) {
        const PinInfo& pin = Pins::GPIO[i];  // Direct access to current pin

        pinMode(pin.number, INPUT_PULLUP);   // Configure as input with pull-up resistor
        delay(5);                            // Brief delay to stabilize reading
        int state = digitalRead(pin.number); // Read pin state

        // Print result to Serial
        Serial.print("🔍 ");
        Serial.print(pin.name);
        Serial.print(" [Pin ");
        Serial.print(pin.number);
        Serial.print("] → State: ");
        Serial.println(state == LOW ? "Connected to ground (LOW)" : "Floating (HIGH)");

        // Force pin to LOW state to avoid false readings
        digitalWrite(pin.number, LOW);
    }
}

/**
 * @brief Diagnostic for PWM pins configured as digital outputs.
 * 
 * Configures each PWM pin as OUTPUT, sets it to HIGH, and checks if the state holds.
 * Prints results via Serial to detect potential faults or conflicts.
 * 
 * @note Useful for verifying PWM pins behave correctly as outputs.
 */
void diagnosePWM() {
    Serial.println("\n➡️ Checking PWM pins:");

    for (size_t i = 0; i < Pins::NUM_PWM; ++i) {
        const PinInfo& pin = Pins::PWM[i];  // Direct access to current pin

        pinMode(pin.number, OUTPUT);        // Configure as output
        digitalWrite(pin.number, HIGH);     // Set pin to HIGH
        delay(5);                           // Brief delay to stabilize reading
        int state = digitalRead(pin.number); // Read pin state

        // Print result to Serial
        Serial.print("🌀 ");
        Serial.print(pin.name);
        Serial.print(" [Pin ");
        Serial.print(pin.number);
        Serial.print("] → State: ");
        Serial.println(state == HIGH ? "Working correctly" : "Fault or conflict");
    }
}

/**
 * @brief Runs a full diagnostic of digital GPIO and PWM pins.
 * 
 * Calls individual diagnostic functions for GPIO and PWM,
 * printing results via Serial. Useful as an initial hardware test.
 * 
 * @note Ideal for checking general pin status at program startup.
 */
void fullDiagnostics() {
    Serial.println();
    Serial.println("🔧 Initial diagnostic of digital and PWM pins\n");

    diagnoseGPIO();   // GPIO pin diagnostic
    diagnosePWM();    // PWM pin diagnostic

    Serial.println("\n✅ Full diagnostic complete.\n");
}

/**
 * @brief Checks if a given pin number exists in the GPIO pin list.
 * 
 * Iterates through Pins::GPIO and compares the physical pin number.
 * 
 * @param pinNumber Physical pin number to check.
 * @return true If the pin is found in the GPIO list.
 * @return false If the pin is not found.
 */
bool isPinInGPIO(int pinNumber) {
    for (const auto& gpio : Pins::GPIO) {
        if (gpio.number == pinNumber) {
            return true;
        }
    }
    return false;
}
