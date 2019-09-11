#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h> 

int main(int argc, char *argv[]){	
	int i;
	struct timeval time1;
	struct timeval time2;
	long totaltime = 0;
	float avgtime = 0;
	pid_t process_id;
	for (i = 0; i < 1000000; i++){ 
		gettimeofday(&time1, 0);
		getpid();
		gettimeofday(&time2, 0);
		totaltime += (time2.tv_sec - time1.tv_sec) * 1000000 + (time2.tv_usec - time1.tv_usec);

	}
	printf("Syscalls performed: %d\n", i);
	printf("total elapsed time: %ld ms\n", totaltime);
	avgtime = (float)totaltime / 1000000;
	printf("Average time per syscall: %f ms\n", avgtime);
	return 0;

}
