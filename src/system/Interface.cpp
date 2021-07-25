#include "system/Interface.hpp"

CRGB Interface::leds[NUM_LEDS];
CRGB Interface::leds2[NUM_LEDS];
CRGB Interface::leds3[NUM_LEDS];
boolean Interface::buttons[NUM_BUTTONS];
bool Interface::btnPressed[NUM_BUTTONS];
uint8_t Interface::brightness;
ColorMode Interface::cmode;
long toleranceTimer1 = 0;
long toleranceTimer2 = 0;

void Interface::allLedsOff (void)
{
	for (int i = 0; i < NUM_LEDS; i++) {
		Interface::leds[i] = CRGB::Black;
	}
}

void Interface::changeBrightness (void)
{
	if (brightness == 0) brightness = 255;
	else brightness -= BRIGHTNESS_DEC;

	if (brightness < 0) brightness = 0;
	FastLED.setBrightness(brightness);
}

void Interface::changeColorMode (void)
{
	if (cmode == ColorMode::WHITE) cmode = ColorMode::RAINBOW;
	else {
		int tmp = (int) cmode;
		tmp++;
		cmode = (ColorMode) tmp;
	}
}

void Interface::readButtons (void)
{
	buttons[0] = digitalRead(BUTTON_1_PIN);
	buttons[1] = digitalRead(BUTTON_2_PIN);

	for (int i = 0; i < NUM_BUTTONS; i++) {
		if (!buttons[i]) btnPressed[i] = true;
	}
	if (buttons[0] && btnPressed[0]) {
		btnPressed[0] = false;
		changeBrightness();
	}
	if (buttons[1] && btnPressed[1]) {
		btnPressed[1] = false;
		changeColorMode();
		//ColorGradient::changeColorGradient(Interface::cmode);
	}
}

void Interface::buttonCallbackFirst (void)
{
	if (millis() - toleranceTimer1 > BUTTON_PRESS_TOLERANCE) {
		toleranceTimer1 = millis();
		Interface::changeBrightness();
	}
}

void Interface::buttonCallbackSecond (void)
{
	if (millis() - toleranceTimer2 > BUTTON_PRESS_TOLERANCE) {
		toleranceTimer2 = millis();
		Interface::changeColorMode();
	}
}
