// Program Number : 24
// Name : Vidhish Trivedi
// Register Number : IMT2021055
// Date : 08/02/2023
// Description : Write a program to create an orphan process.

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(){
	int res = fork();
	if(res == 0){
		printf("In child process...\n");
		printf("PID: %d\nPPID: %d\n", getpid(), getppid());
		sleep(15);

		printf("PID: %d\nPPID: %d\n", getpid(), getppid());
		printf("Still in child process...\n");
		sleep(15);

		printf("PID: %d\nPPID: %d\n", getpid(), getppid());
		printf("Still in child process...\n");
		exit(0);
	}
	else{
		printf("Original PPID: %d\n", getpid());
		printf("In parent process...\n");
		sleep(20);
		/* exit(0); */
	}
	return 0;
}

