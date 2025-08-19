#ifndef MESSAGE_RELEASE_H
#define MESSAGE_RELEASE_H

#include <Arduino.h>
#include "configuracion.h"

/**
 * @brief Prints an enriched log message to the serial monitor.
 *
 * This function should be defined in the corresponding source (.cpp) file.
 * It generates a structured output that includes:
 * - Compilation date and time
 * - Source file from which it is called
 * - Name of the calling function
 * - Custom message
 *
 * Output format:
 * [date time] file::function ➤ message
 *
 * Example:
 * [Aug 7 2025 01:23:00] main.cpp::setup ➤ System initialization...
 *
 * @param message   Custom text to be printed
 * @param file      Source file name (__FILE__)
 * @param function  Name of the calling function (__FUNCTION__)
 * @param date      Compilation date (__DATE__)
 * @param time      Compilation time (__TIME__)
 */
void standardMessage(const char* message, const char* file, const char* function, const char* date, const char* time);

/**
 * @brief Prints an enriched error message to the serial monitor, including contextual information.
 *
 * This function generates a structured output that helps identify the origin of runtime errors.
 * The output includes:
 * - Compilation date and time
 * - Source file name
 * - Function name from which it is invoked
 * - Line number where the function was called
 * - Custom error message
 *
 * Output format:
 * [date time] file::function (Line N) ❌ ERROR ➤ message
 *
 * Example output:
 * [Aug 7 2025 01:23:00] sensor.cpp::readSensor (Line 42) ❌ ERROR ➤ Failed to initialize sensor
 *
 * @param message   Description of the specific error
 * @param file      Source file name (__FILE__)
 * @param function  Function name where the error was detected (__FUNCTION__)
 * @param date      Compilation date (__DATE__)
 * @param time      Compilation time (__TIME__)
 * @param line      Line number in the file where the function is invoked (__LINE__)
 */
void standardErrorMessage(const char* message, const char* file, const char* function, const char* date, const char* time, int line);

/**
 * @brief Displays the current system configuration status on the serial monitor.
 * 
 * This function prints the current values of the fields defined in the 
 * configuracionMain structure, such as debug mode and LED project status, 
 * in a user-friendly format to facilitate system diagnostics or verification.
 * 
 * @param configuration  Structure containing the main system configuration.
 */
void showConfigurationMessage(const configuracionMain& configuration);

#endif // MESSAGE_RELEASE_H
