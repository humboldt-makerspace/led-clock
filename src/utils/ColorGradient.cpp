#include "utils/ColorGradient.hpp"
#include "system/Interface.hpp"

CRGB ColorGradient::colors[NUM_LEDS_PALETTE];
CRGB ColorGradient::offsetDecoy[NUM_LEDS_PALETTE];
bool ColorGradient::shift = false;
int ColorGradient::offset = 0;
unsigned long offsetTime;
long shiftTimer = 0;

void fillGradientRGB (CRGB* input, uint16_t startpos, CRGB startcolor, uint16_t endpos, CRGB endcolor)
{
	if (endpos < startpos) {
		uint16_t t = endpos;
		CRGB tc = endcolor;
		endcolor = startcolor;
		endpos = startpos;
		startpos = t;
		startcolor = tc;
	}

	saccum87 rdistance87;
	saccum87 gdistance87;
	saccum87 bdistance87;

	rdistance87 = (endcolor.r - startcolor.r) << 7;
	gdistance87 = (endcolor.g - startcolor.g) << 7;
	bdistance87 = (endcolor.b - startcolor.b) << 7;

	uint16_t pixeldistance = endpos - startpos;
	int16_t divisor = pixeldistance ? pixeldistance : 1;

	saccum87 rdelta87 = rdistance87 / divisor;
	saccum87 gdelta87 = gdistance87 / divisor;
	saccum87 bdelta87 = bdistance87 / divisor;

	rdelta87 *= 2;
	gdelta87 *= 2;
	bdelta87 *= 2;

	accum88 r88 = startcolor.r << 8;
	accum88 g88 = startcolor.g << 8;
	accum88 b88 = startcolor.b << 8;
	for (uint16_t i = startpos; i <= endpos; i++) {
		input[i] = CRGB(r88 >> 8, g88 >> 8, b88 >> 8);
		r88 += rdelta87;
		g88 += gdelta87;
		b88 += bdelta87;
	}
}

void ColorGradient::fillPride (void)
{
	static uint16_t sPseudotime = 0;
	static uint16_t sLastMillis = 0;
	static uint16_t sHue16 = 0;

	uint8_t sat8 = beatsin88(87, 220, 250);
	uint8_t brightdepth = beatsin88(341, 96, 224);
	uint16_t brightnessthetainc16 = beatsin88(203, (25 * 256), (40 * 256));
	uint8_t msmultiplier = beatsin88(147, 23, 60);

	uint16_t hue16 = sHue16;//gHue * 256;
	uint16_t hueinc16 = beatsin88(113, 1, 3000);

	uint16_t ms = millis();
	uint16_t deltams = ms - sLastMillis;
	sLastMillis = ms;
	sPseudotime += deltams * msmultiplier;
	sHue16 += deltams * beatsin88(400, 5, 9);
	uint16_t brightnesstheta16 = sPseudotime;

	for (uint16_t i = 0; i < NUM_LEDS_PALETTE; i++) {
		hue16 += hueinc16;
		uint8_t hue8 = hue16 / 256;

		brightnesstheta16 += brightnessthetainc16;
		uint16_t b16 = sin16(brightnesstheta16) + 32768;

		uint16_t bri16 = (uint32_t) ((uint32_t) b16 * (uint32_t) b16) / 65536;
		uint8_t bri8 = (uint32_t) (((uint32_t) bri16) * brightdepth) / 65536;
		bri8 += (255 - brightdepth);

		CRGB newcolor = CHSV(hue8, sat8, bri8);

		uint16_t pixelnumber = i;
		pixelnumber = (NUM_LEDS_PALETTE - 1) - pixelnumber;

		colors[pixelnumber] = newcolor;
	}
}

void ColorGradient::changeShift (void)
{
	if (!ColorGradient::shift) return;
	if (millis() - offsetTime > OFFSET_INC_MS) {
		(ColorGradient::offset >= NUM_LEDS_PALETTE - 1) ? ColorGradient::offset = 0 : ColorGradient::offset++;
		offsetTime = millis();
	}
}

void ColorGradient::changeColorGradient (ColorMode mode)
{
	switch (mode) {
		case RAINBOW: {
			fillGradientRGB(colors, 0, CRGB::Red, NUM_LEDS_PALETTE / 3, CRGB::Green);
			fillGradientRGB(colors, NUM_LEDS_PALETTE / 3, CRGB::Green, 2 * NUM_LEDS_PALETTE / 3, CRGB::Blue);
			fillGradientRGB(colors, 2 * NUM_LEDS_PALETTE / 3, CRGB::Blue, NUM_LEDS_PALETTE - 1, CRGB::Red);
			break;
		}
		case RAINBOW_SHIFT: {
			if (millis() - shiftTimer > COLOR_GRADIENT_TIMER) {
				if (ColorGradient::offset == NUM_LEDS_PALETTE - 1) ColorGradient::offset = 0;
				else ColorGradient::offset++;
				for (int i = 0; i < NUM_LEDS_PALETTE; i++) {
					int colorIndex = i + ColorGradient::offset;
					if (colorIndex >= NUM_LEDS_PALETTE) colorIndex -= NUM_LEDS_PALETTE;
					ColorGradient::colors[i] = ColorGradient::offsetDecoy[colorIndex];
				}
				shiftTimer = millis();
			}

			break;
		}
		case PRIDE: {
			fillPride();
			break;
		}
		case RED: {
			for (int i = 0; i < NUM_LEDS_PALETTE; i++) {
				ColorGradient::colors[i] = CRGB::Red;
			}
			break;
		}
		case ORANGE: {
			for (int i = 0; i < NUM_LEDS_PALETTE; i++) {
				ColorGradient::colors[i] = CRGB::Orange;
			}
			break;
		}
		case YELLOW: {
			for (int i = 0; i < NUM_LEDS_PALETTE; i++) {
				ColorGradient::colors[i] = CRGB::Yellow;
			}
			break;
		}
		case GREEN: {
			for (int i = 0; i < NUM_LEDS_PALETTE; i++) {
				ColorGradient::colors[i] = CRGB::Green;
			}
			break;
		}
		case PURPLE: {
			for (int i = 0; i < NUM_LEDS_PALETTE; i++) {
				ColorGradient::colors[i] = CRGB::Purple;
			}
			break;
		}
		case BLUE: {
			for (int i = 0; i < NUM_LEDS_PALETTE; i++) {
				ColorGradient::colors[i] = CRGB::Blue;
			}
			break;
		}
		case WHITE: {
			for (int i = 0; i < NUM_LEDS_PALETTE; i++) {
				ColorGradient::colors[i] = CRGB::White;
			}
			break;
		}
		default: {
			break;
		}
	}
}

void ColorGradient::init (void)
{
	fillGradientRGB(offsetDecoy, 0, CRGB::Red, NUM_LEDS_PALETTE / 3, CRGB::Green);
	fillGradientRGB(offsetDecoy, NUM_LEDS_PALETTE / 3, CRGB::Green, 2 * NUM_LEDS_PALETTE / 3, CRGB::Blue);
	fillGradientRGB(offsetDecoy, 2 * NUM_LEDS_PALETTE / 3, CRGB::Blue, NUM_LEDS_PALETTE - 1, CRGB::Red);
}
