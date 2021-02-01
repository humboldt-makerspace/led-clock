#include "includes.hpp"

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
	FastLED.delay(1);
}
