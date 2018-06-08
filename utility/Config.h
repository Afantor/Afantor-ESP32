#ifndef _CONFIG_H_
#define _CONFIG_H_

// SPI LCD Screen
#define TFT_LED_PIN 	-1
#define TFT_MISO_PIN 	-1
#define TFT_MOSI_PIN 	23
#define TFT_SCLK_PIN 	18
#define TFT_CS_PIN 		2		// Chip select control pin
#define TFT_DC_PIN 		22		// Data Command control pin
#define TFT_RST_PIN 	21		// Reset pin (could connect to RST pin)
//#define TFT_RST  -1  // Set TFT_RST to -1 if display RESET is connected to ESP32 board RST


// SD card
#define SDCARD_CS_PIN 	5

// Buttons
#define BTN_NULL    (0)
#define BTN_A       (1)
#define BTN_B       (2)
#define BTN_C       (3)
#define BTN_D       (4)
#define BUTTON_NULL   (0)
#define BUTTON_A      (1)
#define BUTTON_B      (2)
#define BUTTON_C      (3)
#define BUTTON_D      (4)


#define BUTTON_PIN 	39

// BEEP PIN
#define SPEAKER_PIN 	25
#define TONE_PIN_CHANNEL 0

// UART
#define USE_SERIAL		Serial

#define FALSE  (0)
#define TRUE   (1)

#endif /* SETTINGS_C */
