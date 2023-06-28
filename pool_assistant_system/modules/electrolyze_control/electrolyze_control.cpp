#include "arm_book_lib.h"

#include "electrolyze_control.h"
#include "electrolyze_system.h"
#include "red_ox_sensor.h"

enum AutoElectrolyzeState {
    IDLE,
    OXYDATION,
    REDUCTION
};

static ElectrolyzeControlMode   currentMode;
static AutoElectrolyzeState     currentState;

static void updateAutomaticElectrolyzeState();

void initElectrolyzeControl() {
    currentMode = AUTOMATIC_MODE;
    currentState = IDLE;
}

void updateElectrolyzeControl() {
    switch (currentMode) {
        case AUTOMATIC_MODE:
            updateAutomaticElectrolyzeState();
            break;
        case MANUAL_MODE_ON:
            writeElectrolyzeSystem(ON);
            break;
        case MANUAL_MODE_OFF:
            writeElectrolyzeSystem(OFF);
            break;
    }
}

void setModeElectrolyzeControl(ElectrolyzeControlMode mode) {
    currentMode = mode;
}

char getStateAsCharElectrolyzeControl() {
    char result = '\0';
    switch (currentMode) {
        case AUTOMATIC_MODE:    result = 'A'; break;
        case MANUAL_MODE_ON:    result = 'O'; break;
        case MANUAL_MODE_OFF:   result = 'F'; break;
    }
    return result;
}

void updateAutomaticElectrolyzeState() {
    float redOxVal = readRedOxSensor();
    switch (currentState) {
        case IDLE:
            if (redOxVal < MAX_RED_OX_VAL) {
                currentState = OXYDATION;
                writeElectrolyzeSystem(ON);
            } else {
                currentState = REDUCTION;
                writeElectrolyzeSystem(OFF);
            }
            break;
        case OXYDATION:
            if (redOxVal > MAX_RED_OX_VAL) {
                currentState = REDUCTION;
                writeElectrolyzeSystem(OFF);
            }
            break;
        case REDUCTION:
            if (redOxVal < MIN_RED_OX_VAL) {
                currentState = OXYDATION;
                writeElectrolyzeSystem(ON);
            }
            break;
    }
}