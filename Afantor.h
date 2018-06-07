// Copyright (c) Afantor. All rights reserved.

// Licensed under the MIT license. See LICENSE file in the project root for full license information.
/**
 * \par Copyright (C), 2016-2017, Afantor
 * \class Afantor
 * \brief   Afantor library.
 * @file    Afantor.h
 * @author  Afantor
 * @version V0.1.0
 * @date    2018/03/27
 * @brief   Header for Afantor.cpp module
 *
 * \par Description
 * This file is a drive for Afantor core.
 *
 * \par Method List:
 *    
 *  System:
        Afant.begin();
        Afant.update();

    LCD:
        Afant.Lcd.setBrightness(uint8_t brightness);
        Afant.Lcd.drawPixel(int16_t x, int16_t y, uint16_t color);
        Afant.Lcd.drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color);
        Afant.Lcd.fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
        Afant.Lcd.fillScreen(uint16_t color);
        Afant.Lcd.drawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
        Afant.Lcd.drawCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername,uint16_t color);
        Afant.Lcd.fillCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
        Afant.Lcd.fillCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername,int16_t delta, uint16_t color);
        Afant.Lcd.drawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color);
        Afant.Lcd.fillTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color);
        Afant.Lcd.drawRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h, int16_t radius, uint16_t color);
        Afant.Lcd.fillRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h, int16_t radius, uint16_t color);
        Afant.Lcd.drawBitmap(int16_t x, int16_t y, const uint8_t bitmap[], int16_t w, int16_t h, uint16_t color);
        Afant.Lcd.drawRGBBitmap(int16_t x, int16_t y, const uint16_t bitmap[], int16_t w, int16_t h),
        Afant.Lcd.drawChar(uint16_t x, uint16_t y, char c, uint16_t color, uint16_t bg, uint8_t size);
        Afant.Lcd.setCursor(uint16_t x0, uint16_t y0);
        Afant.Lcd.setTextColor(uint16_t color);
        Afant.Lcd.setTextColor(uint16_t color, uint16_t backgroundcolor);
        Afant.Lcd.setTextSize(uint8_t size);
        Afant.Lcd.setTextWrap(boolean w);
        Afant.Lcd.printf();
        Afant.Lcd.print();
        Afant.Lcd.println();
        Afant.Lcd.drawCentreString(const char *string, int dX, int poY, int font);
        Afant.Lcd.drawRightString(const char *string, int dX, int poY, int font);
        Afant.Lcd.drawJpg(const uint8_t *jpg_data, size_t jpg_len, uint16_t x, uint16_t y);
        Afant.Lcd.drawJpgFile(fs::FS &fs, const char *path, uint16_t x, uint16_t y);
        Afant.Lcd.drawBmpFile(fs::FS &fs, const char *path, uint16_t x, uint16_t y);


    Button:
        Afant.BtnA/B/C/D.read();
        Afant.BtnA/B/C/D.isPressed();
        Afant.BtnA/B/C/D.isReleased();
        Afant.BtnA/B/C/D.wasPressed();
        Afant.BtnA/B/C/D.wasReleased();
        Afant.BtnA/B/C/D.pressedFor(uint32_t ms);
        Afant.BtnA/B/C/D.releasedFor(uint32_t ms);
        Afant.BtnA/B/C/D.lastChange();

    Speaker:
        Afant.Speaker.tone(uint32_t freq);
        Afant.Speaker.tone(freq, time);
        Afant.Speaker.beep();
        Afant.Speaker.setBeep(uint16_t frequency, uint16_t duration);
        Afant.Speaker.mute();

 *
 * \par History:
 * <pre>
 * `<Author>`         `<Time>`        `<Version>`        `<Descr>`
 * Blue God         2018/03/27         0.1.0            Rebuild the new.
 * </pre>
 *
 */

#ifndef _AFANTOR_H_
#define _AFANTOR_H_

#if defined(ESP32)

#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include "FS.h"
#include "SD.h"

#include "Display.h"
// #include "utility/Config.h"
// #include "utility/Button.h"
// #include "utility/Speaker.h"
// #include "utility/M5Timer.h"

#ifdef MPU6050_INSDE
// #include "utility/MPU6050.h"
// #include "utility/quaternionFilters.h"
#endif


class Afant {

 public:
    void begin(bool LCDEnable=true, bool SDEnable=true);
    void update();

    void setWakeupButton(uint8_t button);
    void powerOFF();

//    // Button API
//    #define DEBOUNCE_MS 5
//    Button BtnA = Button(BUTTON_A_PIN, true, DEBOUNCE_MS);
//    Button BtnB = Button(BUTTON_B_PIN, true, DEBOUNCE_MS);
//    Button BtnC = Button(BUTTON_C_PIN, true, DEBOUNCE_MS);
//    Button BtnD = Button(BUTTON_D_PIN, true, DEBOUNCE_MS);
//    // SPEAKER
//    SPEAKER Speaker;
//
//    // LCD
    AFDisplay Lcd = AFDisplay();
//
//    // UART
//    // HardwareSerial Serial0 = HardwareSerial(0);
//    // HardwareSerial Serial2 = HardwareSerial(2);
//
//    // MPU6050
//#ifdef MPU6050_INSDE
//    MPU6050 IMU = MPU6050();
//#endif
//
 private:
   uint8_t _wakeupPin;
};

extern Afant AF;
#define af AF
#define lcd Lcd

#else
#error “This library only supports boards with ESP32 processor.”
#endif

#endif

