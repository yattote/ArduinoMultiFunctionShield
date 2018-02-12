#include <arduino.h>
#include "CMelodies.h"
#include "CCommon.h"

enum EOutput { Led1 = 10, Led2 = 11, Led3 = 12, Led4 = 13,  //Led4 equals the Uno's built-in LED
               Buzzer = 3 };
enum EInput { Button1 = A1, Button2 = A2, Button3 = A3,
              Input1 = 5, Input2 = 6, Input3 = 9, InfraredReceiver = 2};
enum EInputPwm { InputPwm = A5, Potentiometer = A0, TemperatureSensor = A4 };              
enum ECommunication { APC220_RX = 0, APC220_TX = 1 };

// outputs
const int DISPLAY_LATCH = 4;
const int DISPLAY_CLOCK = 7;
const int DISPLAY_DATA = 8;

class CMultifunction
{
public:
    // Constructors
    CMultifunction()
    {
        pinMode(Led1, OUTPUT);                  //the leds are negated, so instead of lightning-on with HIGH value, it'd be with LOW value.
        pinMode(Led2, OUTPUT);
        pinMode(Led3, OUTPUT);
        pinMode(Led4, OUTPUT);
        SetOutput(Led1, HIGH);                  //set to HIGH to avoid lightning on at start
        SetOutput(Led2, HIGH);
        SetOutput(Led3, HIGH);
        SetOutput(Led4, HIGH);

        pinMode(Button1, INPUT_PULLUP);         //pressing any embbeded button generates LOW logic signal
        pinMode(Button2, INPUT_PULLUP);
        pinMode(Button3, INPUT_PULLUP);

        // outputs
        pinMode(DISPLAY_LATCH, OUTPUT);
        pinMode(DISPLAY_CLOCK, OUTPUT);
        pinMode(DISPLAY_DATA,  OUTPUT);
        //pinMode(Buzzer, OUTPUT);              //set by m_Melodies
        m_Melodies = new CMelodies(Buzzer);
        SetOutput(Buzzer, HIGH);                //output also negated, so set it to HIGH to avoid buzzing at start
        Display(1000);

        // inputs
        //pinMode(Potentiometer, INPUT);        //= A0;
        //pinMode(TemperatureSensor, INPUT);    //= A4. NOTE: Remove jumper J1
        //pinMode(InfraredReceiver, INPUT);     //2

        // comm
        // const int APC220_RX = 0;
        // const int APC220_TX = 1;
    };

    // Public methods
    void SetOutput(EOutput out, unsigned int iValue);
    int  GetInput(EInput in);
    int  GetInputPwm(EInputPwm inPwm);
    void Display(int iValue);

    void StartTimeTrial();
    void StopTimeTrial();
    void PlayMelody(EMelodies melody);
private:
    // Private methods
    CMelodies* m_Melodies;
    void WriteNumberToSegment(byte bSegment, byte bValue);
    bool m_bTimeTrialRun;
};