#ifndef ULTRASONIC_SENSOR_H
#define ULTRASONIC_SENSOR_H

#include <Arduino.h>

class UltrasonicSensor {
private:
    int trigPin;
    int echoPin;

public:
    UltrasonicSensor(int trig, int echo);
    float readDistance(String unit = "cm");
    bool isObjectDetected(float threshold_cm);
    float filteredDistance();
};

#endif