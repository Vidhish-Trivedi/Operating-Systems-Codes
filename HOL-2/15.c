/*
Program Number : 15
Name : Vidhish Trivedi
Register Number : IMT2021055
Date : 30/03/2023
Description : Simple program to send some data from parent to the child process using a pipe.
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	int fd[2];
	pipe(fd);

    // Child process.
	if(!fork()){
        printf("In child process\n");
		int c_value = 1011;
		close(fd[0]);
        printf("Writing to pipe (in child process)\n");
		write(fd[1], &c_value, sizeof(int));
	}
    // Parent process.
	else{
        printf("In parent process\n");
		int p_value;
		close(fd[1]);
		read(fd[0], &p_value, sizeof(int));
		printf("Data from child in parent process: %d\n", p_value);
	}

	return(0);
}
