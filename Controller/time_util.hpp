#ifndef TIME_UTIL_H
# define TIME_UTIL_H

# include <time.h>

# define NSEC_IN_SEC 1000000000L

long			time_subtract(struct timespec a, struct timespec b);
struct timespec	time_add(struct timespec t, long n);

#endif
