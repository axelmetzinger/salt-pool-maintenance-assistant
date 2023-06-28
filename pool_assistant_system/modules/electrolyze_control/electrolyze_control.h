#ifndef _ELECTROLYZE_CONTROL_H_
#define _ELECTROLYZE_CONTROL_H_

#define MIN_RED_OX_VAL  650 // in mV
#define MAX_RED_OX_VAL  750 // in mV

// State
enum ElectrolyzeControlMode {
    AUTOMATIC_MODE,
    MANUAL_MODE_ON,
    MANUAL_MODE_OFF
};

void initElectrolyzeControl();

void updateElectrolyzeControl();

void setModeElectrolyzeControl(ElectrolyzeControlMode mode);

char getStateAsCharElectrolyzeControl();

#endif  // _ELECTROLYZE_CONTROL_H_