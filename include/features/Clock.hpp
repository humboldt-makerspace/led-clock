#ifndef CLOCK_HPP
#define CLOCK_HPP

#include <ctime>
#include "constants.h"

class Clock {
private:
	/* functions */
	static void getTime (void);

public:
	/* variables */
	static tm* gmtm;

	/* functions */
	static void showTime (int type);
};

#endif
