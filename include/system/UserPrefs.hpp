#ifndef USER_PREFS_HPP
#define USER_PREFS_HPP

#include "EEPROM.h"
#include "constants.h"

typedef struct storables {
	uint8_t brightness;
	ColorMode cmode;
} Storable;

class UserPrefs {
private:
	/* variables */

	/* functions */

public:
	/* variables */

	/* functions */
	static void saveValuesToEEPROM (void);
	static void readValuesFromEEPROM (void);
	static void clearEEPROM (void);
	static void resetEEPROM (void);
};

#endif
