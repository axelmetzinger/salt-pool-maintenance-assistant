#include "sensors.h"

void initSensors() {
    initPhSensor();
    initRedOxSensor();
    initTemperatureSensor();
}

void updateSensors() {
    updatePhSensor();
    updateRedOxSensor();
    updateTemperatureSensor();
}