/*
  ------------------------------------------------------------
  Project: Arduino Main File
  Board: ATmega2560 (Arduino Mega)
  Author: Eduardo
  Date:   20/08/2025
  ------------------------------------------------------------
  Description:
  Initializes the system in either debug or execution mode.
  - Debug mode: runs the debug initialization routine.
  - Execution mode: starts serial communication, displays system messages,
      -runs diagnostics, shows configuration, and initializes main pins.
  ------------------------------------------------------------
*/



#include <Arduino.h>                                       // Core Arduino functions
#include <HardwareSerial.h>                                // Serial communication support
#include <Stream.h>                                        // Stream base class for serial and other I/O
#include <Print.h>                                         // Printing utilities for Arduino
#include <avr8-stub.h>                                     // AVR8 debugging stub for GDB
#include "config.h"                                        // Project configuration definitions
#include "pinout/pinout.h"                                 // Pin mapping for the personal project
#include "msg/msg.h"                                       // Message handling functions
#include "diagnostics/diagnosticsUART.h"                   // UART diagnostics functions
#include "diagnostics/diagnosticsEEPROM.h"
#include "RFID-RC522/RFID-RC522_System.h"             // EEPROM diagnostics functions
#include "menu/menu.h"                                     // Menu display functions

void setup() {                                             // Arduino setup function (runs once at startup)
  if (systemConfiguration.debugMode) {                     // Check if the system is in debug mode
    debug_init();                                          // Start debugger initialization routine
  } else {                                                 // Otherwise, run in normal execution mode
    Serial.begin(57600);                                   // Start serial communication at 57600 baud
    while (!Serial);                                       // Wait until serial port is ready
    standardMessage("System started in execution mode",    // Send system start message with metadata
                    __FILE__,                              // Current file name
                    __FUNCTION__,                          // Current function name
                    __DATE__,                              // Compilation date
                    __TIME__);                             // Compilation time
    fullDiagnosticsPins();                                 // Run diagnostics on all pins
    diagnoseAllUART();
    DiagnosticsEEPROM::runTest();                          // Run diagnostics on all UART ports
    showConfigurationMessage(systemConfiguration);         // Display the current system configuration
    initializeMainConfiguration(systemConfiguration);      // Initialize pins and settings for main config
  };
};

void loop() {
    if (systemConfiguration.proyect_RIFD_RC522) {
        static RFID_System rfidSystem;  
        static bool mostrarMenu = true; // bandera para controlar cuándo se pinta

        // Pintar menú solo cuando esté activada la bandera
        if (mostrarMenu) {
            showMenu_RIFD_RC522();
            mostrarMenu = false;
        }

        // Comprobar si hay datos por Serial
        if (Serial.available() > 0) {
            char command = toupper(Serial.read());

            switch (command) {
                case 'A':
                    rfidSystem.statusSensor();
                    mostrarMenu = true; // volver a mostrar después
                    break;

                case 'B':
                    rfidSystem.detectedTag();
                    mostrarMenu = true;
                    break;

                case 'C':
                    // Acción C...
                    mostrarMenu = true;
                    break;

                case 'M': // Menú manual
                    mostrarMenu = true;
                    break;

                case '\n':
                case '\r':
                    // Ignorar saltos de línea
                    break;

                default:
                    Serial.println("⚠ Comando desconocido. Pulsa 'M' para menú.");
                    break;
            };
        };
    };
};

   



