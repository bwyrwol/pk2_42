#include "utility.h"

void UtilitySeparator(char c, int cnt)
{
	for (int i = 0; i < cnt; i++)
		std::cout << c;
	std::cout << std::endl;
}

void UtilityGetTime(tm& time)
{
	time_t now = std::time(0);
	localtime_s(&time, &now);
	time.tm_year += 1900;
}