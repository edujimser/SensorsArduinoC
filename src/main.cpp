#include <Arduino.h>

// Include the necessary headers
#include <HardwareSerial.h>
#include <Stream.h>
#include <Print.h>

//Pinout 
#include "pinout/pinout.h"

//Checks
#include "pinout/pinout.h"

void setup() {
  Serial.begin(9600);

  //Checks
  diagnosticoCompleto();
}

void loop() {
}

