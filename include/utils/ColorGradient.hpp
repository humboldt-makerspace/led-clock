#ifndef COLOR_GRADIENT_HPP
#define COLOR_GRADIENT_HPP

#include "system/Interface.hpp"

class ColorGradient {
private:
	/* variables */

	/* functions */

public:
	/* variables */
	static CRGB colors[NUM_LEDS];
	static bool shift;
	static int offset;

	/* functions */
	static void changeColorGradient (ColorMode mode);
	static void changeShift (void);
};

#endif
