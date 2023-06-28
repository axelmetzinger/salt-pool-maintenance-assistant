#include <stdio.h>

#include "monitoring.h"
#include "ble_com.h"

void refreshValuesMonitoring() {
    char buffer[24];
    sprintf(buffer, "%0.1f,%0.1f,%0.1f,%c",
        readTemperatureSensor(),
        readPhSensor(),
        readRedOxSensor(),
        getStateAsCharElectrolyzeControl());

    writeStringBleCom(buffer);
}