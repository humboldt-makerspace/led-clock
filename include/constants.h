#ifndef CONSTANTS_H
#define CONSTANTS_H

#define DIGITAL					0
#define ANALOG					1
#define COUNTER					2
#define BINARY					3
#define DIGITAL_MINI			4
#define EPOXY_COUNTER			5
#define EPOXY_DIGITAL			6

#define CLOCK_TYPE				DIGITAL
/* data pins for led stripes */
#define LED_PIN					D7
#define LED_PIN_2				D3
#define LED_PIN_3				D4

/* number of leds per data pin */
#if CLOCK_TYPE == DIGITAL
    #define NUM_LEDS			82
	#define OFFSET_INC_MS		80
#elif CLOCK_TYPE == ANALOG
    #define NUM_LEDS			60
	#define OFFSET_INC_MS		20
#elif CLOCK_TYPE == COUNTER
    #define NUM_LEDS			39
	#define OFFSET_INC_MS		80
#elif CLOCK_TYPE == BINARY
    #define NUM_LEDS			11
	#define OFFSET_INC_MS		80
#elif CLOCK_TYPE == DIGITAL_MINI
    #define NUM_LEDS			82
	#define OFFSET_INC_MS		80
#elif CLOCK_TYPE == EPOXY_COUNTER
	#define NUM_LEDS			25
	#define OFFSET_INC_MS		80
#elif CLOCK_TYPE == EPOXY_DIGITAL
	#define NUM_LEDS			26
	#define OFFSET_INC_MS		80
#else
	#define NUM_LEDS			0
	#define OFFSET_INC_MS		100
#endif

/* buttons on control pcb */
#if CLOCK_TYPE == EPOXY_COUNTER
	#define BUTTON_1_PIN			D1
	#define BUTTON_2_PIN			D2
#else
	#define BUTTON_1_PIN			D5
	#define BUTTON_2_PIN			D6
#endif
#define NUM_BUTTONS				2
#define BUTTON_PRESS_TOLERANCE  100

/* digital clock */
#define NUM_FIGURES			10
#if CLOCK_TYPE == EPOXY_DIGITAL
	#define LEDS_PER_FIGURE		13
#else
	#define LEDS_PER_FIGURE		20
#endif
#define FIGURE_HEIGHT			7
#define FIGURE_WIDTH			4
#define GRID_HEIGHT				7
#define GRID_WIDTH				21

/* analog clock */
#define WATCH_HAND_WIDTH		5

/* counter clock */
#define LEDS_FIRST_DIGIT		5
#define LEDS_SECOND_DIGIT		9
#define MINUTE_OFFSET			LEDS_FIRST_DIGIT + LEDS_SECOND_DIGIT
#define HOUR_OFFSET				2 * (LEDS_FIRST_DIGIT + LEDS_SECOND_DIGIT)
#define EPOXY_FADE_FACTOR		100

/* lighting */
#define BRIGHTNESS_DEC			20

/* time information */
#define TIME_ZONE				2
#define DST						1

#define COLOR_GRADIENT_TIMER	1
#if CLOCK_TYPE == EPOXY_DIGITAL
	#define NUM_LEDS_PALETTE	78
#else
	#define NUM_LEDS_PALETTE	NUM_LEDS
#endif

#define EEPROM_SIZE				512

/* color modes for light show */
typedef enum colors {
	RAINBOW,
	RAINBOW_SHIFT,
	PRIDE,
	RED,
	ORANGE,
	YELLOW,
	GREEN,
	PURPLE,
	BLUE,
	WHITE
} ColorMode;

/* all figures that be displayed on clock */
typedef enum figures {
	N0, N1, N2, N3, N4, N5, N6, N7, N8, N9
} Figure;

/* enum for counter clock */
typedef enum timeUnits {
	HOUR, MINUTE, SECOND
} timeUnit;

/* position of figures on clock */
typedef enum clockPos {
	HR_1, HR_2, MIN_1, MIN_2, SEC_1, SEC_2
} ClockPosition;

#endif
