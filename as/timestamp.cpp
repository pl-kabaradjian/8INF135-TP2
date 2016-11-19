#include "timestamp.h"

long int Timestamp::getCurrentTS()
{
	time_t t = std::time(0);
	long int now = static_cast<long int> (t);
	return now;
}
