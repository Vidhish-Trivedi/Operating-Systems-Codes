/*
Program Number : 14
Name : Vidhish Trivedi
Register Number : IMT2021055
Date : 30/03/2023
Description : Simple program to create a pipe, write to the pipe, read from pipe and display on
			  the monitor.
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	int fd[2];
	
	pipe(fd);
	printf("pipe created with fd1: %d, fd2: %d\n", fd[0], fd[1]);

	char buf[10];
	

	write(fd[1], "Hello\n", sizeof("Hello\n"));
	read(fd[0], buf, sizeof(buf));

	printf("Buffer: %s", buf);

	getchar();

	return(0);
}
