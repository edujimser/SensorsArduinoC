#include "configuracion.h"
#include "pinout/pinout.h"
#include "sensors_Led/sensor_Led.h"


/**
 * @brief Main configuration structure for the project.
 *
 * Groups global parameters that control the overall behavior
 * of the application, allowing features to be enabled or disabled
 * at compile-time or runtime.
 */
configuracionMain systemConfiguration = {
    // Initialize debug mode
    .debugMode = false,
    // Sensors and systems
    .proyect_Led = false, 
    .proyect_RIFD_RC522 = true
};

/**
 * @brief Initializes hardware pins according to the provided configuration.
 *
 * Sets directions, initial states, and internal resistors for the pins
 * required by the project. If `debugMode` is active, enables pins for
 * diagnostics/tracing; if `proyectoLed` is active, prepares pins for the LED subsystem.
 *
 * @param configuration  Structure with flags that determine which pins are configured.
 * @pre Call once during system startup, before using peripherals.
 * @post Pins are left in a safe and consistent state for the remainder of execution.
 */

// Initialization
LedRojo* ledRojo = nullptr;

void initializeMainConfigurationPins(configuracionMain systemConfiguration) {
    // Project setup
    if (systemConfiguration.proyect_Led){
        // Pins
        ledRojo = new LedRojo(Pins::GPIO[1].number); // Assign GPIO pin 22 to the red LED
    };

    if (systemConfiguration.proyect_RIFD_RC522){
        Serial.println("🔌 RFID-RC522 pines configurados en archivo .h:");
    };
    
}




