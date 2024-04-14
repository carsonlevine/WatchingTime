// #include <GxEPD.h>
// #include <GxDEPG0150BN/GxDEPG0150BN.h>    // 1.54" b/w 200x200
// #include <GxIO/GxIO_SPI/GxIO_SPI.h>
// #include <GxIO/GxIO.h>
// #include "IMG.h"
// #include "Face1.h"
// #include "Face2.h"
// #include "Face3.h"
// #include "LED_Dot_Matrix12pt7b.h"
// #include "LED_Dot_Matrix4pt7b.h"
// #include "LED_Dot_Matrix6pt7b.h"

// #define PIN_MOTOR 4
// #define PIN_KEY GPIO_NUM_35
// #define PWR_EN 5
// #define Backlight 33
// #define SPI_SCK 14
// #define SPI_DIN 13
// #define EPD_CS 15
// #define EPD_DC 2
// #define SRAM_CS -1
// #define EPD_RESET 17
// #define EPD_BUSY 16

// GxIO_Class io(SPI, EPD_CS, EPD_DC, EPD_RESET);
// GxEPD_Class display(io, EPD_RESET, EPD_BUSY);

// void initializeHardware() {
//   pinMode(PIN_MOTOR, OUTPUT);
//   pinMode(PWR_EN, OUTPUT);
//   digitalWrite(PWR_EN, HIGH);
//   digitalWrite(PIN_MOTOR, HIGH);
//   delay(200);
//   digitalWrite(PIN_MOTOR, LOW);
//   delay(100);
//   digitalWrite(PIN_MOTOR, HIGH);
//   delay(200);
//   digitalWrite(PIN_MOTOR, LOW);
// }

// void initializeDisplay() {
//   display.init();
//   display.setRotation(0);
//   display.invertDisplay(true);
//   display.fillScreen(GxEPD_BLACK);
// }

// void drawUI() {
//   display.setTextColor(GxEPD_WHITE);
//   display.setFont(&LED_Dot_Matrix6pt7b);
//   display.setCursor(10, 10);
//   display.setTextSize(1);
//   display.print("OCT 10 2023          12:45pm");

//   display.setTextSize(3);
//   display.setCursor(10, 40);
//   display.print("+");
//   display.setCursor(37, 55);
//   display.print("231,494");
//   display.setTextSize(1);
//   display.setCursor(160, 70);
//   display.print("HOURS");

//   display.setCursor(0, 97);
//   display.print("_________________________________");

//   display.setCursor(10, 115);
//   display.print("AUG 8 2082");

//   display.setTextSize(3);
//   display.setCursor(10, 135);
//   display.print("-");
//   display.setCursor(37, 145);
//   display.print("512,780");
//   display.setCursor(160, 164);
//   display.print("HOURS");
//   display.update();
// }

// void enterDeepSleep() {
//   display.powerDown();
//   const int inputs[] = {PIN_MOTOR, PWR_EN, PIN_KEY, SPI_SCK, SPI_DIN, EPD_CS, EPD_DC, EPD_RESET, EPD_BUSY, Backlight};
//   for (int pin : inputs) {
//     pinMode(pin, INPUT);
//   }
//   esp_sleep_enable_ext0_wakeup(PIN_KEY, 0);
//   esp_deep_sleep_start();
// }

// void setup() {
//   Serial.begin(115200);
//   Serial.println("ESP32 EPD Simple Test");
//   SPI.begin(SPI_SCK, -1, SPI_DIN, EPD_CS);
//   initializeHardware();
//   initializeDisplay();
//   drawUI();
//   delay(3000);
//   enterDeepSleep();
// }

// void loop() {
//   // Loop is intentionally left empty
// }
