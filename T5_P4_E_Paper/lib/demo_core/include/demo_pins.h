#pragma once

namespace DemoPins
{
    static constexpr int PIN_USER_KEY = 6;
    static constexpr int PIN_PWR_EN = 15;

    static constexpr int PIN_WS2812 = 14;

    static constexpr int PIN_IR_EN = 2;
    static constexpr int PIN_IR_RX = 1;

    static constexpr int PIN_ENCODER_A = 4;
    static constexpr int PIN_ENCODER_B = 5;
    static constexpr int PIN_ENCODER_KEY = 0;

    static constexpr int PIN_I2C_SDA = 8;
    static constexpr int PIN_I2C_SCL = 18;

    static constexpr int PIN_SPI_SCK = 11;
    static constexpr int PIN_SPI_MOSI = 9;
    static constexpr int PIN_SPI_MISO = 10;

    static constexpr int PIN_DISPLAY_BL = 21;
    static constexpr int PIN_DISPLAY_CS = 41;
    static constexpr int PIN_DISPLAY_DC = 16;
    static constexpr int PIN_DISPLAY_RST = 40;

    static constexpr int PIN_PN532_RST = 45;
    static constexpr int PIN_PN532_IRQ = 17;

    static constexpr int PIN_SD_CS = 13;

    static constexpr int PIN_CC1101_CS = 12;
    static constexpr int PIN_CC1101_GDO0 = 3;
    static constexpr int PIN_CC1101_GDO2 = 38;
    static constexpr int PIN_CC1101_SW0 = 48;
    static constexpr int PIN_CC1101_SW1 = 47;

    static constexpr int PIN_RST = PIN_PN532_RST;
    static constexpr int PIN_INT = PIN_CC1101_GDO0;
    static constexpr int PIN_LED = PIN_WS2812;
}
