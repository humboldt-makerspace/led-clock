#include "features/Clock.hpp"
#include "system/Interface.hpp"

tm* Clock::gmtm;

void Clock::getTime (void)
{
	time_t now = time(0);
  	gmtm = localtime(&now);
}

void Clock::showTime (int type)
{	
	getTime();

	switch (type) {
		case DIGITAL: {
			Figures::displayFigure((Figure)(gmtm->tm_hour / 10), HR_1);
			Figures::displayFigure((Figure)(gmtm->tm_hour % 10), HR_2);
			Figures::drawColon(gmtm->tm_sec % 2 == 0);
			Figures::displayFigure((Figure)(gmtm->tm_min / 10), MIN_1);
			Figures::displayFigure((Figure)(gmtm->tm_min % 10), MIN_2);
			break;
		}
		case ANALOG: {
			WatchHand::showHour(gmtm->tm_hour);
			WatchHand::showMinute(gmtm->tm_min);
			WatchHand::showSecond(gmtm->tm_sec);
			break;
		}
		case EPOXY_COUNTER:
		case COUNTER: {
			Counter::showHour(gmtm->tm_hour);
			Counter::showMinute(gmtm->tm_min);
			Counter::showSecond(gmtm->tm_sec);
			break;
		}
		case EPOXY_DIGITAL: {
			Figures::displayFigure((Figure)(gmtm->tm_hour / 10), HR_1);
			Figures::displayFigure((Figure)(gmtm->tm_hour % 10), HR_2);
			Figures::displayFigure((Figure)(gmtm->tm_min / 10), MIN_1);
			Figures::displayFigure((Figure)(gmtm->tm_min % 10), MIN_2);
			Figures::displayFigure((Figure)(gmtm->tm_sec / 10), SEC_1);
			Figures::displayFigure((Figure)(gmtm->tm_sec % 10), SEC_2);
			break;
		}
		case LARGE_SEGMENT: {
			Figures::displayFigure((Figure)(gmtm->tm_hour / 10), HR_1);
			Figures::displayFigure((Figure)(gmtm->tm_hour % 10), HR_2);
			Figures::displayFigure((Figure)(gmtm->tm_min / 10), MIN_1);
			Figures::displayFigure((Figure)(gmtm->tm_min % 10), MIN_2);
			break;
		}
		case BINARY: {
			break;
		}
		default: {
			break;
		}
	}
}
