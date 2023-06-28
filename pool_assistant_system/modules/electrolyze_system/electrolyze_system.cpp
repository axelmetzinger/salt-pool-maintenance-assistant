#include "mbed.h"
#include "arm_book_lib.h"

#include "electrolyze_system.h"
#include "electrolyze_control.h"

DigitalOut electrolyze(LED1);   // Electrolyze is simuled by a LED

void initElectrolyzeSystem() {
    electrolyze.write(OFF);
    initElectrolyzeControl();
}

void updateElectrolyzeSystem() {
    updateElectrolyzeControl();
}

void writeElectrolyzeSystem(bool value) {
    electrolyze.write(value);
}