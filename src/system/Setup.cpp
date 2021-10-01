#include "system/Setup.hpp"
#include "system/Interface.hpp"

WiFiUDP Setup::UDPServer;

void initButtons (void)
{
	pinMode(BUTTON_1_PIN, INPUT_PULLUP);
	pinMode(BUTTON_2_PIN, INPUT_PULLUP);
	for (int i = 0; i < NUM_BUTTONS; i++) Interface::btnPressed[i] = false;

	//attachInterrupt(BUTTON_1_PIN, Interface::buttonCallbackFirst, FALLING);
	//attachInterrupt(BUTTON_2_PIN, Interface::buttonCallbackSecond, FALLING);
}

void initLeds (void)
{
	FastLED.addLeds<WS2812B, LED_PIN>(Interface::leds, NUM_LEDS);
	#if CLOCK_TYPE == EPOXY_DIGITAL
	FastLED.addLeds<WS2812B, LED_PIN_2, GRB>(Interface::leds2, NUM_LEDS);
	FastLED.addLeds<WS2812B, LED_PIN_3, GRB>(Interface::leds3, NUM_LEDS);
	#endif
	UserPrefs::readValuesFromEEPROM();
	Interface::cmode = Interface::store.cmode;
	FastLED.setBrightness(Interface::store.brightness);
	ColorGradient::init();
}

void initClockStatus (void)
{ 
	Figures::defineAlphabet();
	ColorGradient::changeColorGradient(GREEN);
}

void Setup::initWifi (void)
{
	Serial.print("MAC: ");
	Serial.println(WiFi.macAddress());

	WiFi.mode(WIFI_STA);
	WiFi.begin(SSID_CUSTOM, PW_CUSTOM);
	Serial.println();
	Serial.println();
	Serial.print("Wait for WiFi... ");

	while (WiFi.status() != WL_CONNECTED)
	{
		Serial.print(".");
		delay(500);
	}
	Serial.println("");
	Serial.println("WiFi connected");
	Serial.println("IP address: ");
	Serial.println(WiFi.localIP());
	Setup::UDPServer.begin(UDP_PORT);
	
	configTime(TIME_ZONE * 3600, DST * 0, NTP_SERVER);
  	Serial.println("\nWaiting for time");
  	while (!time(nullptr)) {
    	Serial.print(".");
    	delay(1000);
  	}
  	Serial.println("");
	time_t now = time(nullptr);
  	Serial.println(ctime(&now));
}

void Setup::init (void)
{
	Serial.begin(115200);
	initWifi();
	initLeds();
	initButtons();
	initClockStatus();
}
