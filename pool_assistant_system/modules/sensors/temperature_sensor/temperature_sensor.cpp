#define DATA_PIN        A0

#include "temperature_sensor.h"

#include "mbed.h"
#include "DS1820.h"

#define MAX_PROBES      16
 
static int num_devices = 0;
static DS1820* probe[MAX_PROBES];

void initTemperatureSensor() {
    // Initialize the probe array to DS1820 objects
    while(DS1820::unassignedProbe(DATA_PIN)) {
        probe[num_devices] = new DS1820(DATA_PIN);
        num_devices++;
        if (num_devices == MAX_PROBES)
            break;
    }
}

void updateTemperatureSensor() { }

float readTemperatureSensor() {
    float res;
    probe[0]->convertTemperature(true, DS1820::all_devices);
    res = probe[0]->temperature();
    return res;
}
