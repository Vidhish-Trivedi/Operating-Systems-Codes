// Program Number : 19
// Name : Vidhish Trivedi
// Register Number : IMT2021055
// Date : 28/01/2023
// Description : Write a program to find out time taken to execute getpid system call. Use time stamp counter.

#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <time.h>

unsigned long long rdtsc(){
	unsigned long long dst;
	__asm__ __volatile__("rdtsc":"=A"(dst));
	return(dst);
}

int main(){
	long long int start, end;
	start = rdtsc();
	//
	int tmp = getpid();	
	//
	end = rdtsc();
	printf("%llu\n%llu\n", start, end);
	printf("Time stamps taken for getpid() call: %llu\n", end - start);

    // We can further use the CPU frequency to calculate time.
	clock_t t;
    t = clock();
    getpid();
    t = clock() - t;

    printf("Time taken to execute getpid (in ms) is: %f\n", (double) t/CLOCKS_PER_SEC * 1000); 
    
    return 0;
}

