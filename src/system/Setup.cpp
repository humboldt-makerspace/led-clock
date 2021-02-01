#include "system/Setup.hpp"
#include "system/Interface.hpp"

WiFiUDP Setup::UDPServer;

void initButtons (void)
{
	pinMode(BUTTON_1_PIN, INPUT_PULLUP);
	pinMode(BUTTON_2_PIN, INPUT_PULLUP);
	for (int i = 0; i < NUM_BUTTONS; i++) Interface::btnPressed[i] = false;
}

void initLeds (void)
{
	FastLED.addLeds<WS2812B, LED_PIN, GRB>(Interface::leds, NUM_LEDS);
}

void initClockStatus (void)
{
	Figures::defineAlphabet();
	ColorGradient::changeColorGradient(RAINBOW);
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
