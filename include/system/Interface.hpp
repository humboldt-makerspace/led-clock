#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include "constants.hpp"
#include "Arduino.h"
#include "FastLED.h"
#include <ESP8266WiFi.h>
#include "WiFiUdp.h"

#include "utils/ColorGradient.hpp"
#include "utils/Figures.hpp"
#include "utils/Mapping.hpp"
#include "utils/WatchHand.hpp"
#include "utils/Counter.hpp"
#include "custom.h"

class Interface {
private:
	/* variables */
	static boolean buttons[NUM_BUTTONS];

	/* functions */
	static void changeBrightness (void);

public:
	/* variables */
	static CRGB leds[NUM_LEDS];
	static bool btnPressed[NUM_BUTTONS];
	static uint8_t brightness;

	/* functions */
	static void allLedsOff (void);
	static void readButtons (void);
};

#endif
