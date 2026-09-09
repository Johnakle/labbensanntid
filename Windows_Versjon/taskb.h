#define _POSIX_C_SOURCE 199309L
#include <time.h>
#include <sys/times.h>
#include <stdint.h>

uint64_t rdtsc(void);
void rdtsc_maaling(void);
void clock_measure(void);
void times_maaling(void);