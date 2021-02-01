#include "utils/ColorGradient.hpp"
#include "system/Interface.hpp"

CRGB ColorGradient::colors[NUM_LEDS];
bool ColorGradient::shift = false;
int ColorGradient::offset = 0;
unsigned long offsetTime;

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
        input[i] = CRGB( r88 >> 8, g88 >> 8, b88 >> 8);
        r88 += rdelta87;
        g88 += gdelta87;
        b88 += bdelta87;
    }
}

void ColorGradient::changeShift (void)
{
	if (!ColorGradient::shift) return;
	if (millis() - offsetTime > OFFSET_INC_MS) {
		(ColorGradient::offset >= NUM_LEDS - 1) ? ColorGradient::offset = 0 : ColorGradient::offset++;
		offsetTime = millis();
	}
}

void ColorGradient::changeColorGradient (ColorMode mode)
{
	switch (mode) {
		case RAINBOW: {
			fillGradientRGB(colors, 0, CRGB::Red, NUM_LEDS / 3, CRGB::Green);
			fillGradientRGB(colors, NUM_LEDS / 3, CRGB::Green, 2 * NUM_LEDS / 3, CRGB::Blue);
			fillGradientRGB(colors, 2 * NUM_LEDS / 3, CRGB::Blue, NUM_LEDS - 1, CRGB::Red);
			break;
		}
		case SUPERMAN: {
			break;
		}
		case TEMPERATURE: {
			break;
		}
		case AVH: {
			break;
		}
		default: {
			break;
		}
	}
}
