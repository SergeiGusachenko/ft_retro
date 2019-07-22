#include "time_util.hpp"

long time_subtract(struct timespec a, struct timespec b)
{
	return ((a.tv_sec - b.tv_sec) * NSEC_IN_SEC + a.tv_nsec - b.tv_nsec);
}

struct timespec	time_add(struct timespec t, long n)
{
	t.tv_nsec += n;
	while (t.tv_nsec < 0)
	{
		t.tv_sec--;
		t.tv_nsec += NSEC_IN_SEC;
	}
	while (t.tv_nsec > NSEC_IN_SEC)
	{
		t.tv_sec++;
		t.tv_nsec -= NSEC_IN_SEC;
	}
	return (t);
}
