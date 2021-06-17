#include "utils/Mapping.hpp"
#include "system/Interface.hpp"

int Mapping::getLedIndex (int pos)
{
	int result = NUM_LEDS - pos;
	result += 29;
	if (result >= NUM_LEDS) result -= NUM_LEDS;
	return result;
}

int Mapping::getLedIndex (int x, int y)
{
	switch (y) {
		case 0: {
			switch (x) {
				case 0 ... 3: return x;
				case 5 ... 8: return x - 1;
				case 12 ... 15: return x - 4;
				case 17 ... 20: return x - 5;
				default: return -1;
			}
			break;
		}
		case 1: {
			switch (x) {
				case 0: return 16;
				case 3: return 17;
				case 5: return 18;
				case 8: return 19;
				case 12: return 20;
				case 15: return 21;
				case 17: return 22;
				case 20: return 23;
				default: return -1;
			}
			break;
		}
		case 2: {
			switch (x) {
				case 0: return 24;
				case 3: return 25;
				case 5: return 26;
				case 8: return 27;
				case 10: return 28;
				case 12: return 29;
				case 15: return 30;
				case 17: return 31;
				case 20: return 32;
				default: return -1;
			}
			break;
		}
		case 3: {
			switch (x) {
				case 0 ... 3: return x + 33;
				case 5 ... 8: return x + 32;
				case 12 ... 15: return x + 29;
				case 17 ... 20: return x + 28;
				default: return -1;
			}
			break;
		}
		case 4: {
			switch (x) {
				case 0: return 49;
				case 3: return 50;
				case 5: return 51;
				case 8: return 52;
				case 10: return 53;
				case 12: return 54;
				case 15: return 55;
				case 17: return 56;
				case 20: return 57;
				default: return -1;
			}
			break;
		}
		case 5: {
			switch (x) {
				case 0: return 58;
				case 3: return 59;
				case 5: return 60;
				case 8: return 61;
				case 12: return 62;
				case 15: return 63;
				case 17: return 64;
				case 20: return 65;
				default: return -1;
			}
			break;
		}
		case 6: {
			switch (x) {
				case 0 ... 3: return x + 66;
				case 5 ... 8: return x + 65;
				case 12 ... 15: return x + 62;
				case 17 ... 20: return x + 61;
				default: return -1;
			}
			break;
		}
		default: {
			return -1;
		}
	}
}
