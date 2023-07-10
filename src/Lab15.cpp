/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#line 1 "c:/Users/Akash/IoTCamp2023/Lab15/src/Lab15.ino"
#include "Particle.h"
#include "oled-wing-adafruit.h"

void setup();
void loop();
#line 4 "c:/Users/Akash/IoTCamp2023/Lab15/src/Lab15.ino"
OledWingAdafruit display;

SYSTEM_THREAD(ENABLED);
SYSTEM_MODE(MANUAL);

int watchdogTimeout = 5000;
#define watchdogPin D5

bool watchdogReset = false;

void setup()
{
  Serial.begin(9600);
  while (!Serial.isConnected())
  {
  }
  display.setup();
  display.clearDisplay();
  pinMode(watchdogPin, INPUT);
  Watchdog.init(WatchdogConfiguration().timeout(5000));
  Watchdog.start();
  if (System.resetReason() == RESET_REASON_WATCHDOG)
  {
    watchdogReset = true;
  }
  display.println("setup");
  Serial.println("setup");
  display.display();
}

bool pet = true;

void loop()
{
  display.loop();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.clearDisplay();

  if (pet)
  {
    Watchdog.refresh();
  }
  if (!digitalRead(watchdogPin))
  {
    pet = !pet;
    display.println("dont work!");
    Serial.println("dont work!");
    delay(10);
  }

  if (watchdogReset)
  {
    display.println("Watchdog Reset");
    Serial.println("Watchdog Reset");
  }
  else
  {
    display.println("Normal Reset");
  }
  display.display();
}
