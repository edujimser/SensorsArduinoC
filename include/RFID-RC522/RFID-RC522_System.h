#ifndef RFID_RC522_H
#define RFID_RC522_H

#include <SPI.h>
#include <MFRC522v2.h>  // Include the MFRC522 library for RFID functionality
#include <MFRC522DriverSPI.h>  // Include the SPI driver for MFRC522
#include <MFRC522Driver.h> // Include the base driver class for MFRC522
#include <MFRC522DriverPinSimple.h> // Include the simple pin driver for MFRC522
#include <MFRC522Constants.h> // Include constants for MFRC522
#include "pinout/pinout.h"   // Custom pin mapping

/**
 * @brief Class to handle the RFID RC522 module using a centralized pin mapping.
 */
class RFID_System {
public:
    /**
     * @brief Default constructor.
     */
    RFID_System();
    /**
     * @brief Initialize SPI interface and the RC522 module.
     */
    void init();

    void isInitMFRC522();

    void testMFRC522();
    /**
     * @brief SPI hardware pins (from Pins::SPI).
     * MISO = index 0, MOSI = index 1, SCK = index 2.
     */
    static constexpr uint8_t PIN_MISO = Pins::SPI[0].number; ///< Pin 50
    static constexpr uint8_t PIN_MOSI = Pins::SPI[1].number; ///< Pin 51
    static constexpr uint8_t PIN_SCK  = Pins::SPI[2].number; ///< Pin 52
    static constexpr uint8_t PIN_SS   = Pins::SPI[3].number; ///< Pin 53

    /**
     * @brief RC522‐specific control pins (from Pins::GPIO).
     * Adjust indexes as per actual wiring.
     */
    static constexpr uint8_t PIN_RST  = Pins::GPIO[2].number; ///< Example: PIN_GPIO_24
    static constexpr uint8_t PIN_RQ   = Pins::GPIO[4].number; ///< Example: PIN_GPIO_26

    /**
     * @brief MFRC522v2 library object.
     */
    MFRC522DriverPinSimple PIN_MISO_OJB{PIN_MISO};
    MFRC522DriverPinSimple PIN_MOSI_OBJ{PIN_MOSI};
    MFRC522DriverPinSimple PIN_SCK_OBJ{PIN_SCK};
    MFRC522DriverPinSimple PIN_SS_OBJ{PIN_SS};
    MFRC522DriverPinSimple PIN_RST_OBJ{PIN_RST};
    MFRC522DriverPinSimple PIN_RQ_OBJ{PIN_RQ};
 
    MFRC522DriverSPI driver{PIN_SS_OBJ, SPI, SPISettings(4000000u, MSBFIRST, SPI_MODE0)};
    MFRC522 rfid{driver};
};

#endif // RFID_RC522_H 
