/*
Program Number : 19
Name : Vidhish Trivedi
Register Number : IMT2021055
Date : 30/03/2023
Description : Create a FIFO file by
                a. mknod command
                b. mkfifo command
                c. use strace command to find out, which command (mknod or mkfifo) is better.
                c. mknod system call
                d. mkfifo library function
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>

// Using commands
// mkfifo 19_mkfifo_command --mode=0666
// mknod --mode=0666 19_mknod_command p

// Which is faster (better)?
// Answer: mkfifo calls mknod internally (see strace) => mknod is faster.
// Library functions may internally have mappings which may make them faster than system calls in some cases.

int main()
{
    char name[40];
    printf("Enter the name of fifo file: ");
    scanf("%s", name);

    int choice;
    printf("Choose an option:\n1.) mknod system call\n2.) mkfifo system call\n=> ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("Using mknod system call...\n");

        if (mknod(name, __S_IFIFO | 0744, 0) == -1)
        {
            perror("Error: ");
            return -1;
        }
        printf("FIFO file created using mknod\n");
        break;
    case 2:
        printf("Using mkfifo system call...\n");

        if (mkfifo(name, 0744) == -1)
        {
            perror("Error: ");
            return -1;
        }
        printf("FIFO file created using mkfifo\n");
        break;

    default:
        printf("Invalid choice\n");
        break;
    }

    return (0);
}
