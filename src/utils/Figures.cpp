#include "utils/Figures.hpp"
#include "system/Interface.hpp"

boolean Figures::alphabet[NUM_FIGURES][LEDS_PER_FIGURE];

void Figures::defineAlphabet (void)
{
	for (int i = 0; i < NUM_FIGURES; i++) {
		for (int j = 0; j < LEDS_PER_FIGURE; j++) {
			alphabet[i][j] = false;
		}
	}

	for (int i = 0; i < LEDS_PER_FIGURE; i++) {
		/* 0 */
		if (i < 18) alphabet[N0][i] = true;

		/* 1 */
		if (i == 0 || (i > 11 && i < 18)) alphabet[N1][i] = true;

		/* 2 */
		if (i < 4 || (i > 5 && i < 13) || i > 14) alphabet[N2][i] = true;

		/* 3 */
		if (i < 4 || i > 8 || i == 6) alphabet[N3][i] = true;

		/* 4 */
		if (i == 0 || (i > 2 && i < 7) || i > 11) alphabet[N4][i] = true;

		/* 5 */
		if (i < 7 || (i > 8 && i < 16) || i > 17) alphabet[N5][i] = true;
		
		/* 6 */
		if (i < 16 || i > 17) alphabet[N6][i] = true;
		
		/* 7 */
		if (i < 4 || (i > 11 && i < 18)) alphabet[N7][i] = true;

		/* 8 */
		alphabet[N8][i] = true;

		/* 9 */
		if (i < 7 || i > 8) alphabet[N9][i] = true;
	}
}

void Figures::drawColon (bool show)
{
	int colorIndex1 = 40 + ColorGradient::offset;
	if (colorIndex1 >= NUM_LEDS) colorIndex1 -= NUM_LEDS;
	int colorIndex2 = 41 + ColorGradient::offset;
	if (colorIndex2 >= NUM_LEDS) colorIndex2 -= NUM_LEDS;
	if (show) {
		Interface::leds[40] = ColorGradient::colors[colorIndex1];
		Interface::leds[41] = ColorGradient::colors[colorIndex2];
	}
	else {
		Interface::leds[40] = CRGB::Black;
		Interface::leds[41] = CRGB::Black;
	}
}

void Figures::displayFigure (Figure figure, ClockPosition pos)
{
	int offset = 0;
	switch (pos) {
		case HR_1: {
			offset = 3 * LEDS_PER_FIGURE + 2;
			break;
		}
		case HR_2: {
			offset = 2 * LEDS_PER_FIGURE + 2;
			break;
		}
		case MIN_1: {
			offset = 1 * LEDS_PER_FIGURE;
			break;
		}
		case MIN_2: {
			offset = 0;
			break;
		}
		default: {
			break;
		}
	}
	for (int i = 0; i < LEDS_PER_FIGURE; i++) {
		int colorIndex = i + offset + ColorGradient::offset;
		if (colorIndex >= NUM_LEDS) colorIndex -= NUM_LEDS;
		if (!alphabet[figure][i]) Interface::leds[i + offset] = CRGB::Black;
		else Interface::leds[i + offset] = ColorGradient::colors[colorIndex];
	}
}
