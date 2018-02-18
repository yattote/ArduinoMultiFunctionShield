#include "CMultifunction.h"

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

void CMultifunction::DisplayNumber(int iValue)
{
    //TODO: allow floats so decimals are allowed
    if (iValue / 1000)
    {
        WriteNumberToSegment(0 , iValue / 1000);
    }
    if ((iValue / 100) % 10)
    {
        WriteNumberToSegment(1 , (iValue / 100) % 10);
    }
    if ((iValue / 10) % 10)
    {
        WriteNumberToSegment(2 , (iValue / 10) % 10);
    }
    WriteNumberToSegment(3 , iValue % 10);
}

void CMultifunction::DisplayChar(char cValue)
{
    AsciiToSegmentValue(cValue);
}

void CMultifunction::StartTimeTrial()
{
    m_bTimeTrialRun = true;
    int i = 0;
    while (m_bTimeTrialRun)
    {
        DisplayNumber(i);
        Common.Sleep(SLEEP_250MS);
        i += 25;
        if (i == 1000)
            i = 0;
    }
}

void CMultifunction::StopTimeTrial()
{
    m_bTimeTrialRun = false;
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

void CMultifunction::AsciiToSegmentValue(byte bAscii)
{
    digitalWrite(DISPLAY_LATCH, LOW);
    if (bAscii >= 'A' && bAscii <='Z')
    {
        shiftOut(DISPLAY_DATA, DISPLAY_CLOCK, MSBFIRST, SEGMENT_MAP_CHARS[bAscii - 'A']);
        shiftOut(DISPLAY_DATA, DISPLAY_CLOCK, MSBFIRST, SEGMENT_SELECT[3]); //TODO: segment
    }
    // else
    // {
    //     switch (bAscii)
    //     {
    //         case '-':
    //             segmentValue = 191;
    //             break;
    //         case '.':
    //             segmentValue = 127;
    //             break;
    //         case '_':
    //             segmentValue = 247;
    //             break;
    //         case ' ':
    //             segmentValue = 255;
    //             break;
    //     }
    // }
    digitalWrite(DISPLAY_LATCH, HIGH);
}
