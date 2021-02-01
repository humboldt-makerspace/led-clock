#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#define DIGITAL					0
#define ANALOG					1
#define COUNTER					2
#define BINARY					3

#define CLOCK_TYPE				COUNTER

/* data pins for led stripes */
#define LED_PIN					D7

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
#else
	#define NUM_LEDS			0
	#define OFFSET_INC_MS		100
#endif

/* buttons on control pcb */
#define BUTTON_1_PIN			D5
#define BUTTON_2_PIN			D6
#define NUM_BUTTONS				2

/* digital clock */
#define NUM_FIGURES				10
#define LEDS_PER_FIGURE			20

/* analog clock */
#define WATCH_HAND_WIDTH		5

/* counter clock */
#define LEDS_FIRST_DIGIT		5
#define LEDS_SECOND_DIGIT		9
#define MINUTE_OFFSET			LEDS_FIRST_DIGIT + LEDS_SECOND_DIGIT
#define HOUR_OFFSET				2 * (LEDS_FIRST_DIGIT + LEDS_SECOND_DIGIT)

/* lighting */
#define BRIGHTNESS_DEC			20

/* time information */
#define TIME_ZONE				1
#define DST						1

/* color modes for light show */
typedef enum colors {
	RAINBOW,
	SUPERMAN,
	AVH,
	TEMPERATURE,
	MONO
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
	HR_1, HR_2, MIN_1, MIN_2
} ClockPosition;

#endif
