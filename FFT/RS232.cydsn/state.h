//#include <time.h>       /* clock_t, clock, CLOCKS_PER_SEC */
#include <stdbool.h>

long const BEAT_TIMEOUT_MILLS = 300;


typedef struct{
	long lastTimeMills;
	unsigned int frequency;
	unsigned int threshold;
	bool isBeat;
}BeatState; 
