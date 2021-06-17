#include "includes.h"

void setup ()
{
	Setup::init();
}

void loop ()
{	
	Interface::readButtons();
	ColorGradient::changeShift();
	Clock::showTime(CLOCK_TYPE);
	FastLED.show();
}
