#include "menu/menu.h"

void showMenu_RIFD_RC522() {
    standardMessage("RFID-RC522 Menu", __FILE__, __FUNCTION__, __DATE__, __TIME__);
    Serial.println(F("A - Sensor Status Check"));
    Serial.println(F("B - Detect Tag and Read UID"));
    Serial.println(F("M - Show Menu again"));
    Serial.println(F("Esperando comando....."));

};