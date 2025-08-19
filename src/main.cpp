//Headers necesarios para Arduino
#include <Arduino.h>
#include <HardwareSerial.h>
#include <Stream.h>
#include <Print.h>
//Headers necesarios para Debugging
#include <avr8-stub.h>
//Configuración del proyecto
#include "configuracion.h"
//Pinout 
#include "pinout/pinout.h"
//Mensaje del sistema
#include "msg/msg.h"
//SensorLed
#include "sensors_Led/sensor_Led.h"

//----------------------------------------------------------------------------------------------------------------------------------------------------------------

void setup() {
  if (systemConfiguration.debugMode) {
    // Inicializa el programa en modo depuración
    debug_init();  
  }else{
    // Inicializa el programa en modo ejecución
    // Iniciar la comunicación serial a 57600 baudio
    Serial.begin(57600);
     // Espera a que el puerto esté listo (opcional en Mega); 
    while (!Serial);
    // Mensaje de inicio del sistema     
    standardMessage("Sistema iniciado modo ejecucion", __FILE__,__FUNCTION__, __DATE__, __TIME__);
    // Diagnóstico completo del sistema entradas/salidas
    fullDiagnostics();
    // Inicializa los pines de configuración principal
    initializeMainConfigurationPins(systemConfiguration);
    // Mensaje de configuración proyecto
    showConfigurationMessage(systemConfiguration);
  };
};



void loop() {
      ledRojo->conmutacionEstadoPorTiempo(2000); // Enciende el LED rojo
}