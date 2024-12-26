#ifndef _TIME_H
#define _TIME_H

#include <internal/types.h>
#include <sys/types.h>

#ifndef time_t
typedef long time_t;
#endif

struct timespec {
    time_t tv_sec;
    long   tv_nsec;
};

int nanosleep(const struct timespec *req, struct timespec *rem);
unsigned int sleep(unsigned int seconds);
#endif
