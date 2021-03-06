#ifndef FIGURES_HPP
#define FIGURES_HPP

#include "system/Interface.hpp"

class Figures {
private:
	/* variables */
	static boolean alphabet[NUM_FIGURES][LEDS_PER_FIGURE];

public:
	/* functions */
	static void defineAlphabet (void);
	static void displayFigure (Figure figure, ClockPosition cp);
	static void drawColon (bool show);
};

#endif
