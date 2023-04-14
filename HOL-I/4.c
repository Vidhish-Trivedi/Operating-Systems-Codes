// Program Number : 04
// Name : Vidhish Trivedi
// Register Number : IMT2021055
// Date : 15/01/2023
// Description : Write a program to open an existing file with read write mode.
// Try O_EXCL flag also.

#include <stdio.h>
#include <fcntl.h>

int main(){
	int fd = -100;
	fd = open("test4.txt", O_RDWR);
	/* fd = open("test4.txt", O_EXCL); */
	if(fd > 2){
        printf("File opened with fd = %d\n", fd);
        close(fd);
    }
    else{
        perror("Error");
    }

	return(0);
}
