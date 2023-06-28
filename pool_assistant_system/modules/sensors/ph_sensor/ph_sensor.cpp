//=====[Libraries]=============================================================

#include "arm_book_lib.h"

#include "ph_sensor.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

AnalogIn ph(A2);

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void initPhSensor() { }

void updatePhSensor() { }

float readPhSensor() {
    return 14.0 * ph.read();
}

//=====[Implementations of private functions]==================================