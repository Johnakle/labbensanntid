#define _POSIX_C_SOURCE 199309L

#include "taska.h"
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/times.h>
#include <stdint.h>




struct timespec start;
struct timespec end;
struct timespec clock_value;
struct timespec t3;
struct timespec t4;
struct tms usage;
struct tms usage1;
struct tms usage2;
volatile clock_t times_value;


uint64_t rdtsc(void){
    uint64_t val;
    asm volatile("isb; mrs %0, cntvct_el0; isb; " : "=r"(val) :: "memory"); 
    // You can check the current CPU frequency with $sudo dmesg | grep MHz
    return val;
}

uint64_t t1;
uint64_t t2; 

void rdtsc_maaling(void){
clock_gettime(CLOCK_MONOTONIC, &start); 

for(int i = 0; i < 10*1000*1000; i++){

}
clock_gettime(CLOCK_MONOTONIC, &end);

long long elapsed = (end.tv_sec - start.tv_sec) * 1000000000LL + (end.tv_nsec - start.tv_nsec);
int lat = elapsed / (10*1000*1000);

     t1 = rdtsc();
     t2 = rdtsc();
int res = t2 - t1;

printf("Latency for rdtsc: %d ns\n", lat);
printf("Resolusjon for rdtsc: %d ns\n", res);
}

const int samples = 10*1000*1000;
void clock_measure(void){
clock_gettime(CLOCK_MONOTONIC, &start); 

for (int i = 0; i < samples; i++) {
        clock_gettime(CLOCK_MONOTONIC, &clock_value);
    }

clock_gettime(CLOCK_MONOTONIC, &end);

long long elapsed =
        (end.tv_sec - start.tv_sec) * 1000000000LL
        + (end.tv_nsec - start.tv_nsec);

    double latency = (double)elapsed / samples;
clock_gettime(CLOCK_MONOTONIC, &t3);
clock_gettime(CLOCK_MONOTONIC, &t4);

long long ns =
    (t4.tv_sec - t3.tv_sec) * 1000000000LL
    + (t4.tv_nsec - t3.tv_nsec);

    printf("Latency for clock_gettime: %.3f ns\n", latency);
    printf("Resolusjon for clock_gettime: %lld ns\n", ns);
}
int value;
void times_maaling(void){

    clock_gettime(CLOCK_MONOTONIC, &start);

    for (int i = 0; i < samples; i++) {
        times_value = times(&usage);
        clock_t t1 = times(&usage1);
        clock_t t2 = times(&usage2);
    }

    clock_gettime(CLOCK_MONOTONIC, &end);

     long long elapsed =
        (end.tv_sec - start.tv_sec) * 1000000000LL
        + (end.tv_nsec - start.tv_nsec);

long ticks_per_second = sysconf(_SC_CLK_TCK);

    long long ns =
        (long long)(t2 - t1) * 1000000000LL
        / ticks_per_second;


    






    printf("Latency for times: %.3f ns\n",
           (double) elapsed / samples);



}
//int histogram[ns_max];
//int ns_max = 50;
//memset(histogram, 0, sizeof(int)*ns_max);
//
//for(int i = 0; i < 10*1000*1000; i++){
//    
//    // t1 = timer()
//    uint64_t t1 = rdtsc();
//    // t2 = timer()
//    uint64_t t2 = rdtsc();
//    
//    int ns = (t2 - t1) 
//    
//    if(ns >= 0 && ns < ns_max){
//        histogram[ns]++;
//    }
//}
//
//for(int i = 0; i < ns_max; i++){
//    printf("%d\n", histogram[i]);
//}