#include "UltrasonicSensor.h"

UltrasonicSensor::UltrasonicSensor(int trig, int echo) {
    trigPin = trig;
    echoPin = echo;
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

float UltrasonicSensor::readDistance(String unit) {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    long duration = pulseIn(echoPin, HIGH);

    if (unit == "inch") {
        return duration * 0.0133;
    }
    return duration * 0.0343 / 2.0;
}

bool UltrasonicSensor::isObjectDetected(float threshold_cm) {
    float distance = readDistance("cm");
    return distance <= threshold_cm;
}

float UltrasonicSensor::filteredDistance() {
    float sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += readDistance("cm");
        delay(20);
    }
    return sum / 5.0;
}