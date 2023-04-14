// Program Number : 03
// Name : Vidhish Trivedi
// Register Number : IMT2021055
// Date : 15/01/2023
// Description : Write a program to create a file and print the file descriptor value.
// Use creat ( ) system call

#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

int main(){
    int fd = -100;
	// fd: File Descriptor.
	fd = open("test3.txt", O_CREAT, 0777);
    
    if(fd > 2){
        printf("File created with fd = %d\n", fd);
        close(fd);
    }
    else{
        perror("Error");
    }
	return(0);
}

