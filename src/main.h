#include "CMultifunction.h"

CMultifunction m_multifunction;

void ProcessMelodies()
{
    if (m_multifunction.GetInput(Button1) == LOW)
    {
        m_multifunction.PlayMelody(R2D2_2);
    }
    else if (m_multifunction.GetInput(Button2) == LOW)
    {
        m_multifunction.PlayMelody(Ohhh2);
    }
    else if (m_multifunction.GetInput(Button3) == LOW)
    {
        m_multifunction.PlayMelody(Catcall);
        // m_multifunction.StartTimeTrial();
    }
}

void ProcessLeds()
{
    for (int i = 0; i < 4; i++)
    {
        m_multifunction.SetOutput(EOutput(i + Led1), LOW);
        Common.Sleep(SLEEP_500MS);
    }
    for (int i = 0; i < 4; i++)
    {
        m_multifunction.SetOutput(EOutput(i + Led1), HIGH);
        Common.Sleep(SLEEP_500MS);
    }
}

void ProcessDisplay()
{
    for (int i = 0; i < 10; i++)
    {
        m_multifunction.DisplayNumber(i);
        Common.Sleep(SLEEP_250MS);
    }

    for (int i = 0; i < 26; i++)
    {
        m_multifunction.DisplayChar(0x41 + i);    //'A' = 0x41
        Common.Sleep(SLEEP_250MS);
    }
}