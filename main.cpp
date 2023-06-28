#include "pool_assistant_system.h"

// main() runs in its own thread in the OS
int main()
{
    initPoolAssistantSystem();
    while (true) {
        updatePoolAssistantSystem();
    }
}

