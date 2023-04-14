// Program Number : 11
// Name : Vidhish Trivedi
// Register Number : IMT2021055
// Date : 22/01/2023
// Description : Write a program to open a file, duplicate the file descriptor and append the file with both the
// descriptors and check whether the file is updated properly or not.
// a. use dup
// b. use dup2
// c. use fcntl

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int main(){

    // Part a.
    ////////////////////////////////////////////////////////////////
    // char filename[20];
    // printf("Enter filename:");
    // scanf("%s",filename);
    // int oldfd = open(filename,O_RDWR | O_CREAT,0777);
    // int newfd = dup(oldfd);
    // write(oldfd,"From Old fd\n",sizeof("From Old Fd\n"));
    // write(newfd,"From New fd\n",sizeof("From New Fd\n"));
    // close(newfd);
    ////////////////////////////////////////////////////////////////

    // Part b.
    ////////////////////////////////////////////////////////////////
    // char filename[20];
    // printf("Enter filename:");
    // scanf("%s",filename);
    // int oldfd = open(filename,O_RDWR | O_CREAT,0777);
    // int newfd = 7;
    // dup2(oldfd,newfd);
    // write(oldfd,"From Old fd\n",sizeof("From Old Fd\n"));
    // write(newfd,"From New fd\n",sizeof("From New Fd\n"));
    // close(oldfd);
    // close(newfd);
    ////////////////////////////////////////////////////////////////

    // Part c.
    ////////////////////////////////////////////////////////////////
    // char filename[20];
    // printf("Enter filename:");
    // scanf("%s",filename);
    // int oldfd = open(filename,O_RDWR | O_CREAT,0777);
    // int newfd;
    // newfd = fcntl(oldfd,F_DUPFD);   // ,0)?
    // if(newfd == -1){
    //     printf("Error in creating duplicate file descriptor\n");
    // }
    // else{
    //     write(oldfd,"From Old Fd\n",sizeof("From Old Fd\n"));
    //     write(newfd,"From New Fd\n",sizeof("From New Fd\n"));
    // }
    // close(oldfd);
    // close(newfd);
    ////////////////////////////////////////////////////////////////

	return 0;
}

