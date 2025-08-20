#include "RFID-RC522/RFID-RC522.h"

/**
 * @brief Constructor de la clase RFIDReader.
 * Inicializa el objeto MFRC522 con los pines SS y RST definidos.
 */
RFIDReader::RFIDReader()
: rfid(PIN_SS, PIN_RST) {}

/**
 * @brief Inicializa la interfaz SPI y el módulo RC522.
 */
void RFIDReader::begin() {
    SPI.begin();       // Inicia SPI usando los pines hardware (MISO, MOSI, SCK)
    rfid.PCD_Init();   // Inicializa el lector RC522
}

/**
 * @brief Lee el UID de la tarjeta si está presente.
 * @return Cadena con el UID en formato HEX o cadena vacía si no hay tarjeta.
 */
String RFIDReader::readUID() {
    // Verifica si hay una tarjeta nueva presente
    if (!rfid.PICC_IsNewCardPresent()) {
        return "";
    }

    // Intenta leer el número de serie (UID) de la tarjeta
    if (!rfid.PICC_ReadCardSerial()) {
        return "";
    }

    // Construye la cadena UID en formato HEX
    String uidStr;
    for (byte i = 0; i < rfid.uid.size; i++) {
        if (rfid.uid.uidByte[i] < 0x10) {
            uidStr += "0"; // Añade un cero a la izquierda si es menor a 0x10
        }
        uidStr += String(rfid.uid.uidByte[i], HEX);
        if (i != rfid.uid.size - 1) {
            uidStr += ":";
        }
    }
    uidStr.toUpperCase();

    // Detiene la comunicación con la tarjeta y la encriptación
    rfid.PICC_HaltA();
    rfid.PCD_StopCrypto1();

    return uidStr;
}
