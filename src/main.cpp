#include "includes.h"

long colorGradientTimer = 0;

void setup ()
{
	Setup::init();
	Interface::cmode = ColorMode::RAINBOW;
	ColorGradient::changeColorGradient(Interface::cmode);
}

void loop ()
{
	Interface::readButtons();
	if (millis() - colorGradientTimer > COLOR_GRADIENT_TIMER) {
		colorGradientTimer = millis();
		ColorGradient::changeColorGradient(Interface::cmode);
		Clock::showTime(CLOCK_TYPE);
		FastLED.show();
	}
	//ColorGradient::changeColorGradient(Interface::cmode);
	// for (int i = 0; i < NUM_LEDS; i++) {
	// 	Interface::leds[i] = ColorGradient::colors[i];
	// }
	
	

}
