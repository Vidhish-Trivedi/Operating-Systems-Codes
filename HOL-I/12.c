// Program Number : 12
// Name : Vidhish Trivedi
// Register Number : IMT2021055
// Date : 22/01/2023
// Description : Write a program to find out the opening mode of a file. Use fcntl.

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	int fd = open("test_12.txt", O_RDONLY);
	int res = fcntl(fd, F_GETFL);
	printf("fcntl returns:\t%d\n", res);

	if(res < 0){
		printf("Error...\n");
	}
	else if((res & O_ACCMODE) == O_RDONLY){
		printf("File opened in O_RDONLY mode.\n");
	}
	else if((res & O_ACCMODE) == O_RDWR){
		printf("File opened in O_RDWR mode.\n");
	}
	else if((res & O_ACCMODE) == O_WRONLY){
		printf("File opened in O_WRONLY mode.\n");
	}
	else{
		printf("File opened in mode other than O_RDWR, O_RDONLY, O_WRONLY modes.\n");
	}

	return 0;
}

