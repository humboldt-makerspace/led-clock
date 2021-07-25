#ifndef COLOR_GRADIENT_HPP
#define COLOR_GRADIENT_HPP

#include "system/Interface.hpp"

class ColorGradient {
private:
	/* variables */

	/* functions */

public:
	/* variables */
	static CRGB colors[NUM_LEDS_PALETTE];
	static CRGB offsetDecoy[NUM_LEDS_PALETTE];
	static bool shift;
	static int offset;

	/* functions */
	static void changeColorGradient (ColorMode mode);
	static void fillPride (void);
	static void changeShift (void);
	static void init (void);
};

#endif
