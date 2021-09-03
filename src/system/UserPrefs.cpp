#include "system/UserPrefs.hpp"
#include "system/Interface.hpp"

void UserPrefs::saveValuesToEEPROM (void)
{
	Serial.println("Saved values to EEPROM");
	uint8_t addr = 0;
	EEPROM.begin(EEPROM_SIZE);
  	EEPROM.put(addr, Interface::store);
	EEPROM.commit();
}

void UserPrefs::readValuesFromEEPROM (void)
{
	Serial.println("Reading from EEPROM");
	uint8_t addr = 0;
	EEPROM.begin(EEPROM_SIZE);
  	EEPROM.get(addr, Interface::store);
}

void UserPrefs::clearEEPROM (void)
{
	Serial.println("Clearing EEPROM");
	EEPROM.begin(EEPROM_SIZE);
	for (int i = 0; i < EEPROM_SIZE; i++) EEPROM.write(i, 0);
	EEPROM.end();
}

void UserPrefs::resetEEPROM (void)
{
	Serial.println("Resetting EEPROM");
	Storable s;
	s.brightness = 255;
	s.cmode = RAINBOW;

	uint8_t addr = 0;
	EEPROM.begin(EEPROM_SIZE);
	EEPROM.put(addr, s);
	EEPROM.commit();
}
