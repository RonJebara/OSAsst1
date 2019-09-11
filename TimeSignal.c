#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <time.h>

struct timeval time1;
struct timeval time2;

void timecalc(int calls){
	long totaltime = (time2.tv_sec - time1.tv_sec) * 1000000 + (time2.tv_usec - time1.tv_usec);
	float avgtime = (float)totaltime / calls;
	printf("Exceptions Occurred: %d\n", calls);
	printf("Total Elapsed Time: %ld ms\n", totaltime);
	printf("Average Elapsed Time: %f ms\n", avgtime);
	exit(0); 
}

void handle_sigfpe(int sugnum){
	static int i;	
	i++;
	if (i == 1000000){
		gettimeofday(&time2, 0);
		timecalc(i);
	}
}

int main(int argc, char** argv){
	int x = 5;
	int y = 0;
	int z  = 0;
	signal(SIGFPE, handle_sigfpe);
	gettimeofday(&time1, 0);
	z = x / y;
	return 0;
}
