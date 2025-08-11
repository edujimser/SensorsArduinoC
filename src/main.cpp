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
  if (configuracion.debugMode) {
    // Inicializa el programa en modo depuración
    debug_init();  
  }else{
    // Inicializa el programa en modo ejecución
    Serial.begin(57600); // Iniciar la comunicación serial a 57600 baudio
    while (!Serial);      // Espera a que el puerto esté listo (opcional en Mega);
    mensajeEstandar("Sistema iniciado modo ejecucion", __FILE__,__FUNCTION__, __DATE__, __TIME__);
  };
}

LedRojo ledRojo(Pins::GPIO[0].numero); // Instancia del LED rojo en el pin definido

void loop() {
      ledRojo.conmutacionEstadoPorTiempo(4000); // Enciende el LED rojo

}