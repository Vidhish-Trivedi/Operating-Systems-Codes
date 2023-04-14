// Program Number : 23
// Name : Vidhish Trivedi
// Register Number : IMT2021055
// Date : 08/02/2023
// Description : Write a program to create a Zombie state of the running program.

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(){
	int res = fork();
	
	if(res == 0){
        // sleep(25);
		printf("Child: %d\n", getpid());
		sleep(25);
	}
	else{
		printf("Parent: %d\n", getpid());
		exit(0);
	}

	return 0;
}

