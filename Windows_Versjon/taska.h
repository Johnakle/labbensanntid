#define _POSIX_C_SOURCE 199309L
#include <time.h>
#include <sys/times.h>
#include <stdint.h>

void taskA1( int tid);
void busy_wait_clock(struct timespec t);
void busy_wait_times(void);