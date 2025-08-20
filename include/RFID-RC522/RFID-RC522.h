#ifndef RFID_RC522_H
#define RFID_RC522_H

#include <SPI.h>
#include <MFRC522.h>
#include "pinout/pinout.h"   // Custom pin mapping

/**
 * @brief Class to handle the RFID RC522 module using a centralized pin mapping.
 */
class RFIDReader {
public:
    /**
     * @brief Construct a new RFIDReader object with configured pins.
     */
    RFIDReader();

    /**
     * @brief Initialize SPI interface and the RC522 module.
     */
    void begin();

    /**
     * @brief Read the UID from a detected card.
     * @return UID in HEX format as String, or empty string if no card present.
     */
    String readUID();

private:
    /**
     * @brief SPI hardware pins (from Pins::SPI).
     * MISO = index 0, MOSI = index 1, SCK = index 2.
     */
    static constexpr uint8_t PIN_MISO = Pins::SPI[0].number; ///< Pin 50
    static constexpr uint8_t PIN_MOSI = Pins::SPI[1].number; ///< Pin 51
    static constexpr uint8_t PIN_SCK  = Pins::SPI[2].number; ///< Pin 52

    /**
     * @brief RC522‐specific control pins (from Pins::GPIO).
     * Adjust indexes as per actual wiring.
     */
    static constexpr uint8_t PIN_RST  = Pins::GPIO[2].number; ///< Example: PIN_GPIO_24
    static constexpr uint8_t PIN_RQ   = Pins::GPIO[4].number; ///< Example: PIN_GPIO_26
    static constexpr uint8_t PIN_SS   = Pins::GPIO[6].number; ///< Example: PIN_GPIO_28

    /**
     * @brief MFRC522 library object.
     */
    MFRC522 rfid;
};

#endif // RFID_RC522_H
