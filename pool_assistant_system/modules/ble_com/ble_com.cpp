#include "mbed.h"
#include "arm_book_lib.h"

#include "ble_com.h"
#include "monitoring.h"
#include "electrolyze_control.h"

//=====[Declaration of private defines]========================================

#define UART_RX PD_6
#define UART_TX PD_5

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

UnbufferedSerial uartBle(UART_TX, UART_RX, 9600);

//=====[Declarations (prototypes) of private functions]========================

static char readCharBleCom();

//=====[Implementations of public functions]===================================

void updateBleCom() {
    char receivedChar = readCharBleCom();
    if (receivedChar != '\0') {
        switch (receivedChar) {
            // Application asks for refreshing values
            case 'R': refreshValuesMonitoring();   break;
            // Application set a new mode of electrolysis
            case 'A': setModeElectrolyzeControl(AUTOMATIC_MODE);    break;
            case 'O': setModeElectrolyzeControl(MANUAL_MODE_ON);    break;
            case 'F': setModeElectrolyzeControl(MANUAL_MODE_OFF);   break;
            default: break;
        }
    }
}

void writeStringBleCom( const char* str ) {
    uartBle.write( str, strlen(str) );
}

//=====[Implementations of private functions]==================================

static char readCharBleCom() {
    char receivedChar = '\0';
    if( uartBle.readable() ) {
        uartBle.read(&receivedChar,1);
    }
    return receivedChar;
}