#include <stdio.h>
#include <time.h>
#include <string.h>
#include <sched.h>
#include "taskb.h"



void histogram_sched(void)
{
    const int samples = 10 * 1000 * 1000;
    const int ns_max = 10000;
    int histogram[ns_max];
    struct timespec t3;
    struct timespec t4;

    memset(histogram, 0, sizeof(histogram));

    for(int i = 0; i < samples; i++){

        clock_gettime(CLOCK_MONOTONIC, &t3);
        sched_yield();
        clock_gettime(CLOCK_MONOTONIC, &t4);

        long long ns =
            (t4.tv_sec - t3.tv_sec) * 1000000000LL
            + (t4.tv_nsec - t3.tv_nsec);

        if(ns >= 0 && ns < ns_max){
            histogram[ns]++;
        }
    }

    for(int i = 0; i < ns_max; i++){
        printf("%d\n", histogram[i]);
    }
}