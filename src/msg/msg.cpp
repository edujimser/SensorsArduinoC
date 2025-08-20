#include "msg/msg.h"

/**
 * @brief Prints an enriched log message to the serial monitor.
 *
 * This function generates a structured output that includes:
 * - Program compilation date and time
 * - Source file name from which it is called
 * - Name of the function invoking the message
 * - Custom message content
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
void standardMessage(const char* message, const char* file, const char* function, const char* date, const char* time) {
  Serial.println();
  Serial.print("[");
  Serial.print(date);
  Serial.print(" ");
  Serial.print(time);
  Serial.print("] ");
  Serial.print(file);
  Serial.print("::");
  Serial.print(function);
  Serial.print(" ➤ ");
  Serial.println(message);
  Serial.println();
}

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
void standardErrorMessage(const char* message, const char* file, const char* function, const char* date, const char* time, int line) {
  Serial.println();
  Serial.print("[");
  Serial.print(date);
  Serial.print(" ");
  Serial.print(time);
  Serial.print("] ");
  Serial.print(file);
  Serial.print("::");
  Serial.print(function);
  Serial.print(" (Line ");
  Serial.print(line);
  Serial.print(") ❌ ERROR ➤ ");
  Serial.println(message);
  Serial.println();
}

/**
 * @brief Prints the current system configuration status to the serial monitor.
 * 
 * This function displays the values of the fields contained in the 
 * configuracionMain structure, such as debug mode and LED project status,
 * using a clear and friendly visual format for easy reading on the serial monitor.
 * It includes separators and informative emojis to enhance presentation.
 * 
 * @param configuration  Reference to the current system configuration structure.
 */
void showConfigurationMessage(const configuracionMain& configuration) {
  Serial.println(); // Initial line break
  Serial.println("📋 Current configuration status:");
  Serial.println("----------------------------------------");
  Serial.print("🔧 Debug mode: ");
  Serial.println(configuration.debugMode ? "Enabled" : "Disabled");

  Serial.print("💡 LED project: ");
  Serial.println(configuration.proyect_Led ? "Enabled" : "Disabled");

    Serial.print("💡 LED project: ");
  Serial.println(configuration.proyect_RIFD_RC522 ? "Enabled" : "Disabled");

  Serial.println("----------------------------------------");
  Serial.println(); // Final line break

  
}
