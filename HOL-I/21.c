// Program Number : 21
// Name : Vidhish Trivedi
// Register Number : IMT2021055
// Date : 08/02/2023
// Description : Write a program, call fork and print the parent and child process id.

#include <stdio.h>
#include <unistd.h>

int main(){
	int res = fork();

	if(res == 0){
		printf("Child pid: %d\n", getpid());
	}
	else{	
		printf("Parent pid: %d\n", getpid());
	}
	return 0;
}

