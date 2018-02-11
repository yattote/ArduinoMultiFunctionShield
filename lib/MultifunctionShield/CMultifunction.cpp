#include "CMultifunction.h"

const byte SEGMENT_MAP[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0X80, 0X90};    // Segment byte maps for numbers 0 to 9
const byte SEGMENT_SELECT[] = {0xF1, 0xF2, 0xF4, 0xF8}; // Byte maps to select digit 1 to 4

#pragma region Public methods

void CMultifunction::SetOutput(EOutput out, unsigned int iValue)
{
    digitalWrite(out, iValue);
}

int CMultifunction::GetInput(EInput in)
{
    return digitalRead(in);
}

int CMultifunction::GetInputPwm(EInputPwm inPwm)
{
    return analogRead(inPwm);
}

void CMultifunction::Display(int iValue)
{
    //TODO: allow floats so decimals are allowed
    WriteNumberToSegment(0 , iValue / 1000);
    WriteNumberToSegment(1 , (iValue / 100) % 10);
    WriteNumberToSegment(2 , (iValue / 10) % 10);
    WriteNumberToSegment(3 , iValue % 10);
}

void CMultifunction::PlayMelody(EMelodies melody)
{
    m_Melodies->PlayMelody(melody);
    SetOutput(Buzzer, HIGH);            //set off the buzzer
}

#pragma endregion

// Private methods
void CMultifunction::WriteNumberToSegment(byte bSegment, byte bValue)
{
    digitalWrite(DISPLAY_LATCH, LOW);
    shiftOut(DISPLAY_DATA, DISPLAY_CLOCK, MSBFIRST, SEGMENT_MAP[bValue]);
    shiftOut(DISPLAY_DATA, DISPLAY_CLOCK, MSBFIRST, SEGMENT_SELECT[bSegment]);
    digitalWrite(DISPLAY_LATCH, HIGH);
}
