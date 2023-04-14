// Program Number : 26
// Name : Vidhish Trivedi
// Register Number : IMT2021055
// Date : 12/02/2023
// Description : Write a program to execute an executable program.
// a. use some executable program
// b. pass some input to an executable program. (for example execute an executable of $./a.out name)

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
	printf("In 26.c file...\n");
	execv("./helloWorld", argv);
	/* printf("End of 26.c file...\n"); */
	return 0;
}

