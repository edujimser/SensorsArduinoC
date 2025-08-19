#ifndef     CONF_MAIN_H
#define     CONF_MAIN_H

#include "sensors_Led/sensor_Led.h"

/**
 * @brief Main configuration structure for the project.
 *
 * Groups global parameters that control the overall behavior
 * of the application, allowing features to be enabled or disabled
 * at compile-time or runtime.
 */
struct configuracionMain {
    bool debugMode;
    bool proyectoLed;
};
extern configuracionMain systemConfiguration;

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
void initializeMainConfigurationPins(configuracionMain systemConfiguration);

// List of pins
extern LedRojo* ledRojo;

#endif // CONF_MAIN_H