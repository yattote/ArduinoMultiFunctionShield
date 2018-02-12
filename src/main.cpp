#include "main.h"

void setup() {
    m_multifunction = CMultifunction();

    //initialize thread variables
    myThread = new Thread(ProcessMelodies);
    hisThread = Thread(ProcessLeds);

    // Configure myThread
	myThread->onRun(ProcessMelodies);
	myThread->setInterval(100);

	// Configure hisThread
	hisThread.onRun(ProcessLeds);
	hisThread.setInterval(500);

    // Serial.begin(9600);
    // Serial.println("Debugging Multifunction Shield");
}

void loop() {
    // run StaticThreadController. This will check every thread inside ThreadController,
	// if it should run. If yes, he will run it;
    //control.run();

    ProcessMelodies();
    //ProcessLeds();
    //ProcessDisplay();
}