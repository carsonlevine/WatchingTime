#include <GxEPD.h>
#include <GxDEPG0150BN/GxDEPG0150BN.h>    // 1.54" b/w 200x200
// #include <GxGDEH0154Z90/GxGDEH0154Z90.h>  // 1.54" b/w/r 200x200
#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>
#include "IMG.h"
#include "Face1.h"
#include "Face2.h"
#include "Face3.h"
#include "LED_Dot_Matrix12pt7b.h"
#include "LED_Dot_Matrix4pt7b.h"
#include "LED_Dot_Matrix6pt7b.h"

#define PIN_MOTOR 4
#define PIN_KEY GPIO_NUM_35
#define PWR_EN 5
#define Backlight 33

#define SPI_SCK 14
#define SPI_DIN 13
#define EPD_CS 15
#define EPD_DC 2
#define SRAM_CS -1
#define EPD_RESET 17
#define EPD_BUSY 16

GxIO_Class io(SPI, /*CS*/ EPD_CS, /*DC=*/EPD_DC, /*RST=*/EPD_RESET);
GxEPD_Class display(io, /*RST=*/EPD_RESET, /*BUSY=*/EPD_BUSY);

void DeepSleep(void)
{
  display.powerDown();
  pinMode(PIN_MOTOR, INPUT_PULLDOWN);
  pinMode(PWR_EN, INPUT);
  pinMode(PIN_KEY, INPUT);
  pinMode(SPI_SCK, INPUT);
  pinMode(SPI_DIN, INPUT);
  pinMode(EPD_CS, INPUT);
  pinMode(EPD_DC, INPUT);
  pinMode(EPD_RESET, INPUT);
  pinMode(EPD_BUSY, INPUT);
  pinMode(PIN_MOTOR, INPUT);
  pinMode(Backlight, INPUT),
      esp_sleep_enable_ext0_wakeup(PIN_KEY, 0);
  esp_deep_sleep_start();
}

void setup()
{
  Serial.begin(115200);
  delay(10);
  Serial.println("ESP32 EPD Simple Test");
  SPI.begin(SPI_SCK, -1, SPI_DIN, EPD_CS);
  pinMode(PIN_MOTOR, OUTPUT);
  pinMode(PWR_EN, OUTPUT);

  digitalWrite(PWR_EN, HIGH);
  digitalWrite(PIN_MOTOR, HIGH);
  delay(200);
  digitalWrite(PIN_MOTOR, LOW);
  delay(100);
  digitalWrite(PIN_MOTOR, HIGH);
  delay(200);
  digitalWrite(PIN_MOTOR, LOW);

display.init();
display.setRotation(0);
display.invertDisplay(true);
// display.fillScreen(GxEPD_BLACK);
display.setTextColor(GxEPD_BLACK);


// Manually set the time: YYYY, MM, DD, HH, MM, SS
  struct tm newTime;
  newTime.tm_year = 2024 - 1900;  // Year - 1900
  newTime.tm_mon = 4;             // Month, where 0 = january
  newTime.tm_mday = 14;           // Day of the month
  newTime.tm_hour = 15;           // Hour
  newTime.tm_min = 30;            // Minute
  newTime.tm_sec = 0;             // Second
  time_t t = mktime(&newTime);    // Convert to time_t format
  timeval now = { .tv_sec = t, .tv_usec = 0 };  // Create timeval struct
  settimeofday(&now, NULL);       // Set the system time

  // Display the initial time
  // display.fillScreen(GxEPD_WHITE);
  display.drawBitmap(0, 0, face3, 200, 200, GxEPD_WHITE);
  displayTime();


}

void displayTime() {
  char timeString[64];
  struct tm timeinfo;
  if (getLocalTime(&timeinfo)) {
    strftime(timeString, sizeof(timeString), "%c", &timeinfo);
    display.setCursor(0, 30);
    display.setTextSize(3);
    display.println(timeString);
    display.update();
  } else {
    Serial.println("Failed to get time");
  }
}

void loop() {
  // Update the display every minute
  static time_t lastTime = 0;
  time_t now;
  time(&now);

  if (now - lastTime >= 10) {  // Update the time every minute
    lastTime = now;
    display.fillScreen(GxEPD_WHITE);
    displayTime();
  }
  // delay(1000);
  // delay(3000);
  // DeepSleep();
}

void displayCustom()
{
  // display.drawBitmap(0, 0, face3, 200, 200, GxEPD_WHITE);

// // Set text properties before printing text
// display.setCursor(10, 10); // Set the position where you want to start printing text
// // display.fillScreen(GxEPD_BLACK);
// display.setTextColor(GxEPD_WHITE);

// display.setFont(&LED_Dot_Matrix6pt7b); // Example: setting a font, you can choose your own
// display.setTextSize(1);
// display.print("OCT 10 2023          12:45pm");

// display.setTextSize(3);
// display.setCursor(10, 40); 
// display.print("+");
// display.setCursor(37, 55); 
// display.setTextSize(3);
// display.print("231,494");
// display.setTextSize(1);
// display.setCursor(160, 70); 
// display.print("HOURS");

// display.setCursor(0, 97); 
// display.print("_________________________________");

// display.setCursor(10, 115); 
// display.print("AUG 8 2082");

// display.setCursor(10, 135); 
// display.setTextSize(3);

// display.print("-");

// display.setCursor(37, 145); 
// display.print("512,780");
// display.setCursor(160, 164); 
// display.setTextSize(1);
// display.print("HOURS");


// Update the display after all drawing commands
  // display.update();
  
}
