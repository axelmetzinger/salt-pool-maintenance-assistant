//=====[Libraries]=============================================================

#include "arm_book_lib.h"

#include "ph_sensor.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

AnalogIn redOx(A1);

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void initRedOxSensor() { }

void updateRedOxSensor() { }

float readRedOxSensor() {
    return 1000.0 * redOx.read();
}

//=====[Implementations of private functions]==================================