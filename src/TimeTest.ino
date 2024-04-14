#include <GxEPD.h>
#include <GxDEPG0150BN/GxDEPG0150BN.h>  // Adjust for your specific display model
#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>
#include "time.h"

// Setup display configuration
GxIO_Class io(SPI, 15, 2, 17);
GxEPD_Class display(io, 17, 16);

void setup() {
  Serial.begin(115200);

  // Initialize the display
  display.init();
  display.setRotation(0);
  display.setTextColor(GxEPD_BLACK);

  // Manually set the time: YYYY, MM, DD, HH, MM, SS
  struct tm newTime;
  newTime.tm_year = 2023 - 1900;  // Year - 1900
  newTime.tm_mon = 3;             // Month, where 0 = january
  newTime.tm_mday = 10;           // Day of the month
  newTime.tm_hour = 15;           // Hour
  newTime.tm_min = 30;            // Minute
  newTime.tm_sec = 0;             // Second
  time_t t = mktime(&newTime);    // Convert to time_t format
  timeval now = { .tv_sec = t, .tv_usec = 0 };  // Create timeval struct
  settimeofday(&now, NULL);       // Set the system time

  // Display the initial time
  display.fillScreen(GxEPD_WHITE);
  displayTime();
}

void displayTime() {
  char timeString[64];
  struct tm timeinfo;
  if (getLocalTime(&timeinfo)) {
    strftime(timeString, sizeof(timeString), "%c", &timeinfo);
    display.setCursor(0, 30);
    display.setTextSize(2);
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

  if (now - lastTime >= 60) {  // Update the time every minute
    lastTime = now;
    display.fillScreen(GxEPD_WHITE);
    displayTime();
  }
  delay(1000);
}
