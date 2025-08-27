#include "RFID-RC522/RFID-RC522_System.h"

RFID_System::RFID_System(){}
 
/**
 * @brief Initializes the MFRC522 RFID system.
 *        This routine:
 *        1. Logs initialization message with context information.
 *        2. Starts SPI communication.
 *        3. Initializes the RFID reader hardware.
 *        4. Runs hardware diagnostics to confirm reader and antenna status.
 *        5. Performs a self-test on the RFID reader.
 *
 * @note This should be called once during system setup (e.g., in setup()) 
 *       to ensure the reader is ready for use.
 */
void RFID_System::init() {

    // --- Step 1: Log initialization start with contextual info (file, function, build date/time) ---
    standardMessage("Initializing RFID-RC522", __FILE__, __FUNCTION__, __DATE__, __TIME__);

    // --- Step 2: Begin SPI communication (required for RFID module to communicate with MCU) ---
    SPI.begin();

    // --- Step 3: Initialize RFID reader hardware (sets registers and default settings) ---
    rfid.PCD_Init();
    delay(50); // Short delay to allow the chip to stabilize

    rfid.PCD_AntennaOn(); // Ensure antenna is powered on
    
    // --- Step 4: Verify hardware is detected, pins are correct, and antenna is powered ---
    RFID_System::isInitMFRC522();

    // --- Step 5: Run a built-in self-test to ensure reader functions as expected ---
    RFID_System::testMFRC522();
}; 


/**
 * @brief Performs initialization diagnostics for the MFRC522 RFID reader.
 *        Displays pin configuration, verifies communication, checks firmware version,
 *        and ensures the antenna is powered on.
 */
void RFID_System::isInitMFRC522() {

    // --- Show header info: useful for debugging context (file, function, build date/time) ---
    standardHeaderFull("RFID-RC522 Initialization Information", __FILE__, __FUNCTION__, __DATE__, __TIME__);

    // --- Display raw hardware pin assignments for the RFID-RC522 module ---
    Serial.println("🔧 [Pin Mapping] RFID-RC522 hardware pins:");
    Serial.print(" - PIN_MISO: "); Serial.println(PIN_MISO);   // Master In, Slave Out pin
    Serial.print(" - PIN_MOSI: "); Serial.println(PIN_MOSI);   // Master Out, Slave In pin
    Serial.print(" - PIN_SCK : "); Serial.println(PIN_SCK);    // Serial Clock pin
    Serial.print(" - PIN_SS  : "); Serial.println(PIN_SS);     // Slave Select pin
    Serial.print(" - PIN_RST : "); Serial.println(PIN_RST);    // Reset pin for module
    Serial.print(" - PIN_RQ  : "); Serial.println(PIN_RQ);     // Request/IRQ pin if used
    Serial.println();

    // --- Display configured pin values from MFRC522DriverPin objects ---
    Serial.println("🛠 [Driver Pin Objects] Pin assignments in MFRC522DriverPin:");
    Serial.print(" - MISO: "); Serial.println(PIN_MISO_OJB.getPin());  // MISO from object
    Serial.print(" - MOSI: "); Serial.println(PIN_MOSI_OBJ.getPin());  // MOSI from object
    Serial.print(" - SCK : "); Serial.println(PIN_SCK_OBJ.getPin());   // SCK from object
    Serial.print(" - SS  : "); Serial.println(PIN_SS_OBJ.getPin());    // SS from object
    Serial.print(" - RST : "); Serial.println(PIN_RST_OBJ.getPin());   // RST from object
    Serial.print(" - RQ  : "); Serial.println(PIN_RQ_OBJ.getPin());    // RQ from object
    Serial.println();

    // --- Repeat header for clarity before firmware version check ---
    standardHeaderFull("RFID-RC522 Initialization Information", __FILE__, __FUNCTION__, __DATE__, __TIME__);

    // --- Read firmware version register to confirm communication with MFRC522 ---
    byte version = driver.PCD_ReadRegister(MFRC522Constants::PCD_Register::VersionReg);

    // --- If version is 0x00 or 0xFF, there's no communication ---
    if (version == 0x00 || version == 0xFF) {
        Serial.println("❌ ERROR: No communication with the MFRC522 reader detected.");
    } else {
        // --- Valid response: show detected firmware version ---
        Serial.print("✅ MFRC522 detected. Firmware Version: 0x");
        Serial.println(version, HEX);

        // --- Warn if detected version is not one of the known official versions ---
        if (version != 0x91 && version != 0x92) {
            Serial.println("⚠ NOTE: Non-standard firmware version (clone or variant). Proceeding...");
        }
    }

    // --- Read TxControlReg to check if the antenna driver is ON ---
    uint8_t txControl = driver.PCD_ReadRegister(MFRC522Constants::PCD_Register::TxControlReg);
    bool antennaOn = (txControl & 0x03); // Lower two bits indicate antenna status

    // --- If antenna is OFF, attempt to turn it ON ---
    if (!antennaOn) {
        Serial.println("📡 Antenna is OFF. Attempting to power ON...");
        rfid.PCD_AntennaOn();  // Command to enable antenna

        // --- Re-check status after first attempt ---
        txControl = driver.PCD_ReadRegister(MFRC522Constants::PCD_Register::TxControlReg);
        antennaOn = (txControl & 0x03);

        if (antennaOn) {
            Serial.println("✅ Antenna powered ON successfully.");
        } else {
            // --- Retry once if antenna failed to power ON ---
            Serial.println("⚠ Retry: Powering antenna ON...");
            rfid.PCD_AntennaOn();

            txControl = driver.PCD_ReadRegister(MFRC522Constants::TxControlReg);
            antennaOn = (txControl & 0x03);

            if (antennaOn) {
                Serial.println("✅ Antenna powered ON after retry.");
            } else {
                Serial.println("❌ ERROR: Antenna power-on failed. Check wiring or replace reader.");
            }
        }
    } else {
        // --- Antenna was already powered ON ---
        Serial.println("📡 Antenna is already ON.");
    };
};


/**
 * @brief Runs the MFRC522 RFID reader self-test routine.
 *        Displays diagnostic results for internal modules (FIFO, CRC, RF Mod/DeMod, Oscillator).
 *        Reports success or detailed failure causes.
 *
 * @details
 *  - If the self-test fails and output patterns differ from NXP's reference values,
 *    this may indicate a counterfeit/cloned MFRC522 module.
 *  - Genuine MFRC522 modules typically return the exact self-test bit sequence documented by NXP.
 *    Clones may fail certain internal tests or produce altered register values.
 *
 * @note Call this after hardware initialization to confirm module health.
 */
void RFID_System::testMFRC522() {

    // --- Show test header with contextual info (file, function, compile time) ---
    standardHeaderFull("RFID-RC522 Self-Test", __FILE__, __FUNCTION__, __DATE__, __TIME__);

    // --- Execute built-in MFRC522 self-test routine ---
    bool testOK = rfid.PCD_PerformSelfTest();

    if (testOK) {
        // ✅ Self-test passed: all internal subsystems responded correctly
        Serial.println("✅ Self-test successful:");
        Serial.println("   • FIFO memory: PASS");
        Serial.println("   • Internal CRC generator: PASS");
        Serial.println("   • RF Modulator/Demodulator: PASS");
        Serial.println("   • Internal oscillator: PASS");
        Serial.println("💡 The MFRC522 reader is ready for normal operation.");
    } else {
        // ❌ Self-test failed: at least one subsystem did not respond as expected
        Serial.println("❌ Self-test FAILED:");
        Serial.println("   • Possible clone detected — self-test data pattern mismatch with genuine MFRC522.");
        Serial.println("   • At least one internal block did not pass verification.");

        // --- Outline possible failure causes for field troubleshooting ---
        Serial.println("   • Potential causes:");
        Serial.println("       - Incorrect or loose wiring.");
        Serial.println("       - Damaged or incomplete clone module.");
        Serial.println("       - Unstable or incorrect supply voltage.");
        Serial.println("       - Firmware or silicon variant not matching NXP reference.");

        // --- Recommended next steps for technician ---
        Serial.println("🛠  Recommendation: Check connections, restart, and re-run the test.");
        Serial.println("ℹ  For suspected clones: compare register dump with NXP's documented values for genuine MFRC522.");
    };
};


/**
 * @brief Checks if the MFRC522 RFID reader is responding correctly.
 *
 * @return true  if the sensor is communicating and version is valid
 * @return false if communication failed or version is unknown
 */
void RFID_System::statusSensor() {
    standardMessage("Checking RFID-RC522 Sensor Status", __FILE__, __FUNCTION__, __DATE__, __TIME__);
    Serial.println(F("📡 Leyendo versión de firmware del RC522..."));
    
    rfidDebug.PCD_DumpVersionToSerial(rfid, Serial);

    // Lee registro de versión
    byte version = driver.PCD_ReadRegister(MFRC522Constants::PCD_Register::VersionReg);

    // Estado de comunicación
    bool comunicacionOK = false;

    if (version == 0x91 || version == 0x92) {
        Serial.println(F("✅ Sensor OK - MFRC522 estándar detectado."));
        comunicacionOK = true;
    } else if (version == 0x00 || version == 0xFF) {
        Serial.println(F("❌ Falla de comunicación. Revisa cableado, alimentación y SPI."));
        comunicacionOK = false;
    } else {
        Serial.print(F("⚠ Versión no estándar detectada: 0x"));
        Serial.println(version, HEX);
        Serial.println(F("   Puede ser un clon. Funcionamiento no garantizado."));
        comunicacionOK = true; // seguimos aunque sea clon
    }

    // 🔍 Test extra de eco en un registro (verifica MOSI/MISO)
    const byte testValue = 0x55; // patrón de prueba
    driver.PCD_WriteRegister(MFRC522Constants::PCD_Register::TxModeReg, testValue);
    byte readValue = driver.PCD_ReadRegister(MFRC522Constants::PCD_Register::TxModeReg);

    Serial.print(F("Escrito: 0x"));
    Serial.print(testValue, HEX);
    Serial.print(F(" - Leído: 0x"));
    Serial.println(readValue, HEX);

    if (readValue == testValue) {
        Serial.println(F("✅ Comunicación SPI verificada en ambas direcciones."));
    } else {
        Serial.println(F("⚠ Error de eco: posible fallo en líneas MOSI o MISO."));
        comunicacionOK = false;
    }

    // Resultado final
    if (comunicacionOK) {
        Serial.println(F("🚀 Sensor listo para uso."));
    } else {
        Serial.println(F("⛔ Sensor no operativo."));
    };
};


void RFID_System::detectedTag() {
    // Detecta si hay algo en el campo
    if (!rfid.PICC_IsNewCardPresent()) {
        Serial.println(F("⏳ No hay tarjeta en el campo"));
        return; // Sale de la función
    }

    // Intenta leer el UID y tipo
    if (!rfid.PICC_ReadCardSerial()) {
        Serial.println(F("⚠ No se pudo leer el UID de la tarjeta"));
        return;
    }

    // Mostrar UID
    Serial.print(F("UID detectado:"));
    for (byte i = 0; i < rfid.uid.size; i++) {
        Serial.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
        Serial.print(rfid.uid.uidByte[i], HEX);
    }
    Serial.println();

    // Obtener el tipo con el tipo de dato correcto
    MFRC522Constants::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);

    // Mostrar tipo de tarjeta
    Serial.print(F("Tipo detectado: "));
    Serial.println(rfidDebug.PICC_GetTypeName(piccType));

    // Clasificar
    if (piccType == MFRC522Constants::PICC_Type::PICC_TYPE_MIFARE_MINI ||
        piccType == MFRC522Constants::PICC_Type::PICC_TYPE_MIFARE_1K ||
        piccType == MFRC522Constants::PICC_Type::PICC_TYPE_MIFARE_4K) {
        Serial.println(F("💳 Tarjeta RFID detectada"));
    } else {
        Serial.println(F("🐾 Posible microchip u otro tipo de tag"));
    }
}


