#include "RFID-RC522/RFID-RC522_System.h"

RFID_System::RFID_System(){}
 
void RFID_System::init() {
    SPI.begin(); // Initialize SPI communication
    rfid.PCD_Init(); // Initialize the RFID reader
    RFID_System::isInitMFRC522(); // Check if the RFID reader is initialized
    RFID_System::testMFRC522(); // Perform a self-test on the RFID reader
}

void RFID_System::isInitMFRC522() {
    Serial.println("Informacion del incializacion del RFID-RC522:");

    Serial.println("Configuración de pines para RFID-RC522:");
    Serial.print("PIN_MISO: "); Serial.println(PIN_MISO);
    Serial.print("PIN_MOSI: "); Serial.println(PIN_MOSI);
    Serial.print("PIN_SCK : "); Serial.println(PIN_SCK);
    Serial.print("PIN_SS  : "); Serial.println(PIN_SS);
    Serial.print("PIN_RST : "); Serial.println(PIN_RST);
    Serial.print("PIN_RQ  : "); Serial.println(PIN_RQ);
    Serial.println("");

    Serial.println("Configuración de pines para objeto pines MFRC522DriverPin:");
    Serial.print("MISO: "); Serial.println(PIN_MISO_OJB.getPin());
    Serial.print("MOSI: "); Serial.println(PIN_MOSI_OBJ.getPin());
    Serial.print("SCK : "); Serial.println(PIN_SCK_OBJ.getPin());
    Serial.print("SS  : "); Serial.println(PIN_SS_OBJ.getPin());
    Serial.print("RST : "); Serial.println(PIN_RST_OBJ.getPin());
    Serial.print("RQ  : "); Serial.println(PIN_RQ_OBJ.getPin());
  
    Serial.println("");
    
    // Verifica si el lector MFRC522 está inicializado correctamente
    if (rfid.PCD_Init()) {
        byte version = driver.PCD_ReadRegister(MFRC522Constants::PCD_Register::VersionReg);
        Serial.print("MFRC522 inicializado correctamente. Versión del chip: 0x");
        Serial.println(version, HEX);
    } else {
        Serial.println("❌ Error: no se pudo inicializar el lector MFRC522.");
    }

    // Verifica si la antena está encendida
    uint8_t txControl = driver.PCD_ReadRegister(MFRC522Constants::PCD_Register::TxControlReg);
    bool antenaEncendida = (txControl & 0x03);

    if (!antenaEncendida) {
        Serial.println("Antena apagada. Encendiendo...");
        rfid.PCD_AntennaOn();

        txControl = driver.PCD_ReadRegister(MFRC522Constants::TxControlReg);
        antenaEncendida = (txControl & 0x03);

        if (antenaEncendida) {
            Serial.println("Antena encendida correctamente.");
        } else {
            Serial.println("❌ Error al encender la antena. Reintentando...");
            rfid.PCD_AntennaOn();

            txControl = driver.PCD_ReadRegister(MFRC522Constants::TxControlReg);
            antenaEncendida = (txControl & 0x03);

            if (antenaEncendida) {
                Serial.println("Antena encendida correctamente tras reintento.");
            } else {
                Serial.println("❌ Error persistente. Revisa conexiones o considera reemplazar el lector.");
            }
        }
    } else {
        Serial.println("Antena ya está encendida.");
    };
};

void RFID_System::testMFRC522() {
    bool testOK = rfid.PCD_PerformSelfTest();

    if (testOK) {
        Serial.println("✅ Self-test exitoso:");
        Serial.println("   - Memoria FIFO: OK");
        Serial.println("   - CRC interno: OK");
        Serial.println("   - Modulador/Demodulador RF: OK"); 
        Serial.println("   - Oscilador interno: OK");
        Serial.println("💡 El lector MFRC522 está listo para operar.");
    } else {
        Serial.println("❌ Self-test fallido:");
        Serial.println("   - Algún bloque interno no pasó la verificación.");
        Serial.println("   - Posibles causas:");
        Serial.println("       • Cableado incorrecto o flojo.");
        Serial.println("       • Módulo dañado o clon incompleto.");
        Serial.println("       • Voltaje de alimentación inestable.");
        Serial.println("🛠  Recomendación: Revisar conexiones, reiniciar y volver a probar.");
    }


}