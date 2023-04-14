// Program Number : 22
// Name : Vidhish Trivedi
// Register Number : IMT2021055
// Date : 08/02/2023
// Description : Write a program, open a file, call fork, and then write to the file by both the child as well as the
// parent processes. Check output of the file.

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	int fd = open("test_22.txt", O_RDWR);

	int res = fork();

	if(res == 0){
		printf("Child....\n");
		write(fd, "Child is writing", 16);
	}
	else{
		printf("Parent....\n");
		write(fd, "Parent is writing", 17);
	}

	return 0;
}
