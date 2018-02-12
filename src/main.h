#include "CMultifunction.h"
#include "Thread.h"
#include "StaticThreadController.h"

CMultifunction m_multifunction;
Thread* myThread;                                           //The Thread (as a pointer) with justCallback initialized
Thread  hisThread;
StaticThreadController<2> control (myThread, &hisThread);   //StaticThreadController that will control all threads

void ProcessMelodies()
{
    if (m_multifunction.GetInput(Button1) == LOW)
    {
//Serial.println("Button 1 pressed");
        //m_multifunction.PlayMelody(Fanfarria);
    }
    else if (m_multifunction.GetInput(Button2) == LOW)
    {
//Serial.println("Button 2 pressed");
        //m_multifunction.PlayMelody(DogPower);
    }
    else if (m_multifunction.GetInput(Button3) == LOW)
    {
//Serial.println("Button 3 pressed");
        m_multifunction.StartTimeTrial();
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
    for (int i = 0; i < 4; i++)
    {
        m_multifunction.Display(i);
        Common.Sleep(SLEEP_1S);
    }
}