#include <Arduino.h>
#include "UltrasonicSensor.h"

UltrasonicSensor sensor(13, 12); // TRIG = GPIO13, ECHO = GPIO12

void setup() {
    Serial.begin(115200);
}

void loop() {
    Serial.print("Distance (cm): ");
    Serial.println(sensor.readDistance());

    if (sensor.isObjectDetected(30)) {
        Serial.println("Object detected within 30 cm!");
    }

    Serial.print("Filtered Distance: ");
    Serial.println(sensor.filteredDistance());

    delay(1000);
}