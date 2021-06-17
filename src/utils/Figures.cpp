#include "utils/Figures.hpp"
#include "system/Interface.hpp"

boolean Figures::alphabet[NUM_FIGURES][LEDS_PER_FIGURE];
boolean Figures::miniAlphabet[NUM_FIGURES][FIGURE_WIDTH][FIGURE_HEIGHT];

void Figures::defineAlphabet (void)
{
	if (CLOCK_TYPE == DIGITAL) {
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
	else if (CLOCK_TYPE == DIGITAL_MINI) {
		for (int i = 0; i < NUM_FIGURES; i++) {
			for (int j = 0; j < FIGURE_WIDTH; j++) {
				for (int k = 0; k < FIGURE_HEIGHT; k++) {
					miniAlphabet[i][j][k] = false;
				}
			}
		}

		for (int x = 0; x < FIGURE_WIDTH; x++) {
			for (int y = 0; y < FIGURE_HEIGHT; y++) {
				// 0
				if (y == 0 || y == 6 || x == 0 || x == 3) {
					miniAlphabet[N0][x][y] = true;
				}

				// 1
				if (x == 3) {
					miniAlphabet[N1][x][y] = true;
				}
				
				// 2
				if (y == 0 || y == 3 || y == 6 || (x == 3 && y > 3) || (x == 0 && y < 3)) {
					miniAlphabet[N2][x][y] = true;
				}

				// 3
				if (x == 3 || y == 0 || y == 3 || y == 6) {
					miniAlphabet[N3][x][y] = true;
				}

				// 4
				if (x == 3 || y == 3 || (x == 0 && y > 3)) {
					miniAlphabet[N4][x][y] = true;
				}

				// 5
				if (y == 0 || y == 3 || y == 6 || (x == 0 && y > 3) || (x == 3 && y < 3)) {
					miniAlphabet[N5][x][y] = true;
				}

				// 6
				if (x == 0 || y == 0 || y == 3 || y == 6 || (x == 3 && y < 3)) {
					miniAlphabet[N6][x][y] = true;
				}

				// 7
				if (x == 3 || y == 6) {
					miniAlphabet[N7][x][y] = true;
				}

				// 8
				if (x == 3 || x == 0 || y == 0 || y == 3 || y == 6) {
					miniAlphabet[N8][x][y] = true;
				}

				// 9
				if (x == 3 || y == 0 || y == 3 || y == 6 || (x == 0 && y > 3)) {
					miniAlphabet[N9][x][y] = true;
				}
			}
		}
	}
}

void Figures::drawColon (bool show)
{
	if (CLOCK_TYPE == DIGITAL) {
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
	else if (CLOCK_TYPE == DIGITAL_MINI) {
		int colorIndex = (10 + ColorGradient::offset) % GRID_WIDTH;
		if (show) Interface::leds[Mapping::getLedIndex(10, 2)] = ColorGradient::colors[colorIndex];
		else Interface::leds[Mapping::getLedIndex(10, 2)] = CRGB::Black;
	}
}

void Figures::displayFigure (Figure figure, ClockPosition pos)
{
	if (CLOCK_TYPE == DIGITAL) {
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
	else if (CLOCK_TYPE == DIGITAL_MINI) {
		int offset = 0;
		switch (pos) {
			case HR_1: {
				offset = 0;
				break;
			}
			case HR_2: {
				offset = 5;
				break;
			}
			case MIN_1: {
				offset = 12;
				break;
			}
			case MIN_2: {
				offset = 17;
				break;
			}
			default: {
				break;
			}
		}

		for (int x = 0; x < FIGURE_WIDTH; x++) {
			int colorIndex = x + offset + ColorGradient::offset;
			if (colorIndex >= GRID_WIDTH) colorIndex -= GRID_WIDTH;
			for (int y = 0; y < FIGURE_HEIGHT; y++) {
				if (!miniAlphabet[figure][x][y]) Interface::leds[Mapping::getLedIndex(x + offset, y)] = CRGB::Black;
				else Interface::leds[Mapping::getLedIndex(x + offset, y)] = ColorGradient::colors[colorIndex];
			}
		}
	}	
}


