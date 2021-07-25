#include "utils/Figures.hpp"
#include "system/Interface.hpp"

boolean Figures::alphabet[NUM_FIGURES][LEDS_PER_FIGURE];						/* for white epoxy clock */
boolean Figures::miniAlphabet[NUM_FIGURES][FIGURE_WIDTH][FIGURE_HEIGHT];		/* for 3d printed compact clock */
boolean Figures::epoxyAlphabet[NUM_FIGURES][LEDS_PER_FIGURE];					/* for epoxy digital clock */

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
	else if (CLOCK_TYPE == EPOXY_DIGITAL) {
		for (int i = 0; i < NUM_FIGURES; i++) {
			for (int j = 0; j < LEDS_PER_FIGURE; j++) {
				epoxyAlphabet[i][j] = false;
			}
		}

		for (int i = 0; i < LEDS_PER_FIGURE; i++) {
			/* 0 */
			if (i > 0) epoxyAlphabet[N0][i] = true;

			/* 1 */
			if ((i > 0 && i < 4) || i > 10) epoxyAlphabet[N1][i] = true;

			/* 2 */
			if (i != 6 && i != 12) epoxyAlphabet[N2][i] = true;

			/* 3 */
			if (i != 6 && i != 8) epoxyAlphabet[N3][i] = true;

			/* 4 */
			if (i < 4 || (i > 4 && i < 8) || i > 10) epoxyAlphabet[N4][i] = true;

			/* 5 */
			if (i != 2 && i != 8) epoxyAlphabet[N5][i] = true;

			/* 6 */
			if (i != 2) epoxyAlphabet[N6][i] = true;

			/* 7 */
			if ((i > 0 && i < 6) || i > 10) epoxyAlphabet[N7][i] = true;

			/* 8 */
			epoxyAlphabet[N8][i] = true;

			/* 9 */
			if (i != 8) epoxyAlphabet[N9][i] = true;
		}
	}
}

void Figures::drawColon (bool show)
{
	if (CLOCK_TYPE == DIGITAL) {
		if (show) {
			Interface::leds[40] = ColorGradient::colors[40];
			Interface::leds[41] = ColorGradient::colors[41];
		}
		else {
			Interface::leds[40] = CRGB::Black;
			Interface::leds[41] = CRGB::Black;
		}
	}
	else if (CLOCK_TYPE == DIGITAL_MINI) {
		int colorIndex = 10 % GRID_WIDTH;
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
			default: return;
		}
		for (int i = 0; i < LEDS_PER_FIGURE; i++) {
			int colorIndex = i + offset;
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
			default: return;
		}

		for (int x = 0; x < FIGURE_WIDTH; x++) {
			int colorIndex = x + offset;
			if (colorIndex >= GRID_WIDTH) colorIndex -= GRID_WIDTH;
			for (int y = 0; y < FIGURE_HEIGHT; y++) {
				if (!miniAlphabet[figure][x][y]) Interface::leds[Mapping::getLedIndex(x + offset, y)] = CRGB::Black;
				else Interface::leds[Mapping::getLedIndex(x + offset, y)] = ColorGradient::colors[colorIndex];
			}
		}
	}
	else if (CLOCK_TYPE == EPOXY_DIGITAL) {
		int offset = 0;
		int colorOffset = 0;
		switch (pos) {
			case HR_1:
			case MIN_1:
			case SEC_1: {
				offset = 0;
				break;
			}
			case HR_2:
			case MIN_2:
			case SEC_2: {
				offset = LEDS_PER_FIGURE;
				break;
			}
			default: {
				break;
			}
		}

		switch (pos) {
			case HR_1:
			case HR_2: {
				colorOffset = 0;
				break;
			}
			case MIN_1:
			case MIN_2: {
				colorOffset = 2 * LEDS_PER_FIGURE;
				break;
			}
			case SEC_1:
			case SEC_2: {
				colorOffset = 4 * LEDS_PER_FIGURE;
				break;
			}
		}

		for (int i = 0; i < LEDS_PER_FIGURE; i++) {
			int colorIndex = i + offset + colorOffset;
			if (colorIndex >= NUM_LEDS_PALETTE) colorIndex -= NUM_LEDS_PALETTE;
			switch (pos) {
				case HR_1:
				case HR_2: {
					if (!epoxyAlphabet[figure][i]) nblend(Interface::leds3[i + offset], CRGB::Black, EPOXY_FADE_FACTOR);
					else nblend(Interface::leds3[i + offset], ColorGradient::colors[colorIndex], EPOXY_FADE_FACTOR);
					break;
				}
				case MIN_1:
				case MIN_2: {
					if (!epoxyAlphabet[figure][i]) nblend(Interface::leds2[i + offset], CRGB::Black, EPOXY_FADE_FACTOR);
					else nblend(Interface::leds2[i + offset], ColorGradient::colors[colorIndex], EPOXY_FADE_FACTOR);
					break;
				}
				case SEC_1:
				case SEC_2: {
					if (!epoxyAlphabet[figure][i]) nblend(Interface::leds[i + offset], CRGB::Black, EPOXY_FADE_FACTOR);
					else nblend(Interface::leds[i + offset], ColorGradient::colors[colorIndex], EPOXY_FADE_FACTOR);
					break;
				}
			}
		}
	}
}


