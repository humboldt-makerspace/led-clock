#include "utils/Counter.hpp"
#include "system/Interface.hpp"

void Counter::showSecond (int amount)
{
	int ten = amount / 10;
	int one = amount % 10;

	for (int i = 0; i < LEDS_SECOND_DIGIT + LEDS_FIRST_DIGIT; i++) {
		int colorIndex = i + ColorGradient::offset;
		if (colorIndex >= NUM_LEDS) colorIndex -= NUM_LEDS;
		if (i < one || i >= LEDS_SECOND_DIGIT + LEDS_FIRST_DIGIT - ten) {
			Interface::leds[i] = ColorGradient::colors[colorIndex];
		}
		else Interface::leds[i] = CRGB::Black;
	}
}

void Counter::showMinute (int amount)
{
	int ten = amount / 10;
	int one = amount % 10;

	for (int i = MINUTE_OFFSET; i < LEDS_SECOND_DIGIT + LEDS_FIRST_DIGIT + MINUTE_OFFSET; i++) {
		int colorIndex = i + ColorGradient::offset;
		if (colorIndex >= NUM_LEDS) colorIndex -= NUM_LEDS;
		if (i < one + MINUTE_OFFSET || i >= LEDS_SECOND_DIGIT + LEDS_FIRST_DIGIT + MINUTE_OFFSET - ten) {
			Interface::leds[i] = ColorGradient::colors[colorIndex];
		}
		else Interface::leds[i] = CRGB::Black;
	}
}

void Counter::showHour (int amount)
{
	int ten = amount / 10;
	int one = amount % 10;

	for (int i = HOUR_OFFSET; i < LEDS_SECOND_DIGIT + 2 + HOUR_OFFSET; i++) {
		int colorIndex = i + ColorGradient::offset;
		if (colorIndex >= NUM_LEDS) colorIndex -= NUM_LEDS;
		if (i < one + HOUR_OFFSET || i >= LEDS_SECOND_DIGIT + 2 + HOUR_OFFSET - ten) {
			Interface::leds[i] = ColorGradient::colors[colorIndex];
		}
		else Interface::leds[i] = CRGB::Black;
	}
}
