# This code is part of an IoT project which is getting values from a distance sensor device.
#include <Wire.h>
#include "Adafruit_VCNL4010.h"

Adafruit_VCNL4010 vcnl;

int delayval = 1; // delay for half a second

void setup() {
  Serial.begin(9600);
  Serial.println("VCNL4010 test");

  if (! vcnl.begin()) {
    Serial.println("Sensor not found 😞");
    while (1);
  }
  Serial.println("Found VCNL4010");
}

void exec_function() {
  double prodistance = vcnl.readProximity();
  Serial.println(prodistance);
  delay(1000);
}

void loop() {
  exec_function();
}
