#include "arm_book_lib.h"

#include "pool_assistant_system.h"
#include "electrolyze_system.h"
#include "ble_com.h"
#include "sensors.h"

void initPoolAssistantSystem() {
    initSensors();
    initElectrolyzeSystem();
}

void updatePoolAssistantSystem() {
    updateSensors();
    updateElectrolyzeSystem();
    updateBleCom();
}