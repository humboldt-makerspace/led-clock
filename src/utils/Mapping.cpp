#include "utils/Mapping.hpp"
#include "system/Interface.hpp"

int Mapping::getLedIndex (int pos)
{
	int result = NUM_LEDS - pos;
	result += 29;
	if (result >= NUM_LEDS) result -= NUM_LEDS;
	return result;
}
