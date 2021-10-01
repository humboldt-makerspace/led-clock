#include "includes.h"
#include "utils/Figures.hpp"

long colorGradientTimer = 0;
int r = 0;
int g = 255;
int b = 0;

void table_lighting (void)
{
	if (g == 255 && r < 255 && !b) r++;
	else if (g > 0 && r == 255 && !b) g--;
	else if (r == 255 && b < 255 && !g) b++;
	else if (r > 0 && b == 255 && !g) r--;
	else if (b == 255 && g < 255 && !r) g++;
	else if (b > 0 && g == 255 && !r) b--;

	if (r > 255) r = 255;
	else if (r < 0) r = 0;
	if (g > 255) g = 255;
	else if (g < 0) g = 0;
	if (b > 255) b = 255;
	else if (b < 0) b = 0;

	if (g == 255 && !r && !b) r++;

	analogWrite(REDPIN, r);
	analogWrite(GREENPIN, g);
	analogWrite(BLUEPIN, b);

	// // fade from blue to violet
	// for (r = 0; r < 256; r++) {
	// 	analogWrite(REDPIN, r);
	// 	delay(FADESPEED);
	// }
	// // fade from violet to red
	// for (b = 255; b > 0; b--) {
	// 	analogWrite(BLUEPIN, b);
	// 	delay(FADESPEED);
	// }
	// // fade from red to yellow
	// for (g = 0; g < 256; g++) {
	// 	analogWrite(GREENPIN, g);
	// 	delay(FADESPEED);
	// }
	// // fade from yellow to green
	// for (r = 255; r > 0; r--) {
	// 	analogWrite(REDPIN, r);
	// 	delay(FADESPEED);
	// }
	// // fade from green to teal
	// for (b = 0; b < 256; b++) {
	// 	analogWrite(BLUEPIN, b);
	// 	delay(FADESPEED);
	// }
	// // fade from teal to blue
	// for (g = 255; g > 0; g--) {
	// 	analogWrite(GREENPIN, g);
	// 	delay(FADESPEED);
	// }
}

void setup ()
{
	Setup::init();
	//Interface::cmode = ColorMode::RAINBOW_SHIFT;
	//ColorGradient::changeColorGradient(Interface::cmode);
	// FastLED.setBrightness(30);
	//analogWrite(REDPIN, 255);
	//analogWrite(GREENPIN, 255);
	analogWrite(BLUEPIN, 255);
}

void loop ()
{
	Interface::readButtons();
	if (millis() - colorGradientTimer > COLOR_GRADIENT_TIMER) {
		colorGradientTimer = millis();
		ColorGradient::changeColorGradient(Interface::cmode);
		Clock::showTime(CLOCK_TYPE);
		delay(10);
		FastLED.show();
		//table_lighting();
	}
	// ColorGradient::changeColorGradient(Interface::cmode);
	// for (int i = 0; i < NUM_LEDS; i++) {
	// 	Interface::leds[i] = ColorGradient::colors[i];
	// }
	// ColorGradient::changeColorGradient(Interface::cmode);
	// Figures::displayFigure(N9, MIN_2);
	// FastLED.delay(10);
	// FastLED.show();
}
