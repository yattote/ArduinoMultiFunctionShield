#include "main.h"

void setup()
{
    m_multifunction = CMultifunction();

    // Serial.begin(9600);
    // Serial.println("Debugging Multifunction Shield");
}

void loop()
{
    ProcessMelodies();
    //ProcessLeds();
    //ProcessDisplay();
    Common.Sleep(SLEEP_120MS);
}