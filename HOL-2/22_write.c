/*
Program Number : 22 - helper
Name : Vidhish Trivedi
Register Number : IMT2021055
Date : 30/03/2023
Description : Helper program for 22.c
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>

// To be used with 22.c
int main()
{
    // int res = mkfifo("myFifo", S_IFIFO | 0666);

    int choice = 0;
    printf("1.\t write (program 1)\n2.\t read (program 2)\n\t Enter choice (choose 1): ");
    scanf("%d", &choice);
    int fd = -1;

    switch (choice)
    {
    case 1:
        fd = open("myFifo", O_WRONLY, 0666);
        getchar();
        getchar();
        write(fd, "Hello from writer\n", sizeof("Hello from writer\n"));
        close(fd);
        break;
    case 2:
        fd = open("myFifo", O_RDONLY, 0666);
        char buf[100];
        read(fd, buf, sizeof(buf));
        printf("Message from writer: %s", buf);
        close(fd);
        break;

    default:
        printf("Choose a valid choice\n");
        break;
    }

    return (0);
}
