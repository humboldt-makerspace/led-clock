#include "utils/Counter.hpp"
#include "system/Interface.hpp"

void Counter::showSecond (int amount)
{
	int ten = amount / 10;
	int one = amount % 10;

#if CLOCK_TYPE == COUNTER
	for (int i = 0; i < LEDS_SECOND_DIGIT + LEDS_FIRST_DIGIT; i++) {
		if (i < one || i >= LEDS_SECOND_DIGIT + LEDS_FIRST_DIGIT - ten) {
			Interface::leds[i] = ColorGradient::colors[i];
		}
		else Interface::leds[i] = CRGB::Black;
	}
#elif CLOCK_TYPE == EPOXY_COUNTER
	return;
#endif
}

void Counter::showMinute (int amount)
{
	int ten = amount / 10;
	int one = amount % 10;

#if CLOCK_TYPE == COUNTER
	for (int i = MINUTE_OFFSET; i < LEDS_SECOND_DIGIT + LEDS_FIRST_DIGIT + MINUTE_OFFSET; i++) {
		if (i < one + MINUTE_OFFSET || i >= LEDS_SECOND_DIGIT + LEDS_FIRST_DIGIT + MINUTE_OFFSET - ten) {
			Interface::leds[i] = ColorGradient::colors[i];
		}
		else Interface::leds[i] = CRGB::Black;
	}
#elif CLOCK_TYPE == EPOXY_COUNTER
	// // tens
	// for (int i = 11; i < 16; i++) {
	// 	if (i - 11 < ten) nblend(Interface::leds[i], ColorGradient::colors[i], EPOXY_FADE_FACTOR);
	// 	else nblend(Interface::leds[i], CRGB::Black, EPOXY_FADE_FACTOR);
	// }
	// // ones
	// for (int i = 16; i < 25; i++) {
	// 	if (i - 16 < one) nblend(Interface::leds[i], ColorGradient::colors[i], EPOXY_FADE_FACTOR);
	// 	else nblend(Interface::leds[i], CRGB::Black, EPOXY_FADE_FACTOR);
	// }

	for (int i = 11; i < 16; i++) {
		if (i - 11 < ten) Interface::leds[i] = ColorGradient::colors[i];
		else Interface::leds[i] = CRGB::Black;
	}
	// ones
	for (int i = 16; i < 25; i++) {
		if (i - 16 < one) Interface::leds[i] = ColorGradient::colors[i];
		else Interface::leds[i] = CRGB::Black;
	}
#endif
}

void Counter::showHour (int amount)
{
	int ten = amount / 10;
	int one = amount % 10;

#if CLOCK_TYPE == COUNTER
	for (int i = HOUR_OFFSET; i < LEDS_SECOND_DIGIT + 2 + HOUR_OFFSET; i++) {
		if (i < one + HOUR_OFFSET || i >= LEDS_SECOND_DIGIT + 2 + HOUR_OFFSET - ten) {
			Interface::leds[i] = ColorGradient::colors[i];
		}
		else Interface::leds[i] = CRGB::Black;
	}
#elif CLOCK_TYPE == EPOXY_COUNTER
	// // tens
	// for (int i = 0; i < 2; i++) {
	// 	if (i < ten) nblend(Interface::leds[i], ColorGradient::colors[i], EPOXY_FADE_FACTOR);
	// 	else nblend(Interface::leds[i], CRGB::Black, EPOXY_FADE_FACTOR);
	// }
	// // ones
	// for (int i = 2; i < 11; i++) {
	// 	if (i - 2 < one) nblend(Interface::leds[i], ColorGradient::colors[i], EPOXY_FADE_FACTOR);
	// 	else nblend(Interface::leds[i], CRGB::Black, EPOXY_FADE_FACTOR);
	// }

	for (int i = 0; i < 2; i++) {
		if (i < ten) Interface::leds[i] = ColorGradient::colors[i];
		else Interface::leds[i] = CRGB::Black;
	}
	// ones
	for (int i = 2; i < 11; i++) {
		if (i - 2 < one) Interface::leds[i] = ColorGradient::colors[i];
		else Interface::leds[i] = CRGB::Black;
	}
#endif
}
