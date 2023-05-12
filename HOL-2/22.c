/*
Program Number : 22
Name : Vidhish Trivedi
Register Number : IMT2021055
Date : 30/03/2023
Description : Program to wait for data to be written into FIFO within 10 seconds, use select
              system call with FIFO.
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/time.h>

// Use 22_write.c as writer.
int main()
{
    fd_set rfds;
    struct timeval tv;
    int retval;

    int fd;

    printf("10 second timer will start when writer is available.\n");

    fd = open("myFifo", O_RDONLY, 0666);
    /* Watch fd of myFifo to see when it is ready for reading. */
    printf("Starting 10 second timer.\n");

    FD_ZERO(&rfds);
    FD_SET(fd, &rfds);

    /* Wait up to ten seconds. */

    tv.tv_sec = 10;
    tv.tv_usec = 0;

    // Waiting
    // printf("Waiting...\n");
    retval = select(fd + 1, &rfds, NULL, NULL, &tv);
    // printf("Waiting Over\n");

    if (retval == -1){
        perror("select()");
    }
    else if (retval){
        printf("Data is available now.\n");
        char buf[100];
        read(fd, buf, sizeof(buf));
        printf("Message from writer: %s", buf);
    }
    else{
        printf("No data within ten seconds.\n");
    }

    close(fd);
    exit(EXIT_SUCCESS);

    return (0);
}
