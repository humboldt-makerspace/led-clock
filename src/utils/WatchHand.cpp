#include "utils/WatchHand.hpp"
#include "system/Interface.hpp"

void WatchHand::showHour (int hour)
{
	int midPoint = (hour * 5) % 60;
	int begin = midPoint - WATCH_HAND_WIDTH / 2;
	int end = midPoint + WATCH_HAND_WIDTH / 2;
	if (begin < 0) begin += NUM_LEDS;
	if (end > NUM_LEDS - 1) end -= NUM_LEDS;
	for (int i = 0; i < NUM_LEDS; i++) {
		if ((begin <= end && i >= begin && i <= end) || (begin > end && (i >= begin || i <= end))) {
			Interface::leds[Mapping::getLedIndex(i)] = ColorGradient::colors[i];
		}
		else Interface::leds[Mapping::getLedIndex(i)] = CRGB::Black;
	}
}

void WatchHand::showMinute (int minute)
{
	Interface::leds[Mapping::getLedIndex(minute)] = CRGB::White;
}

void WatchHand::showSecond (int second)
{
	Interface::leds[Mapping::getLedIndex(second)] = ColorGradient::colors[second];
}
