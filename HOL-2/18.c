/*
Program Number : 18
Name : Vidhish Trivedi
Register Number : IMT2021055
Date : 30/03/2023
Description : Write a program to find out total number of directories on the pwd.
                execute ls -l | grep ^d | wc ? Use only dup2.
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main()
{
    int fd1[2], fd2[2];
    pipe(fd1);
    pipe(fd2);

    if (!fork())
    {
        // write end of fd1
        dup2(fd1[1], 1); // fd1[1] --> STDOUT
        close(fd1[0]);
        close(fd2[0]);
        close(fd2[1]);
        execl("/bin/ls", "/bin/ls", "-l", NULL);
    }
    else
    {
        if (!fork())
        {
            // read end of fd1
            dup2(fd1[0], 0); // fd1[0] --> STDIN
            // write end of fd2
            dup2(fd2[1], 1); // fd2[1] --> STDOUT
            close(fd1[1]);
            close(fd2[0]);
            execl("/bin/grep", "/bin/grep", "^d", NULL);
        }
        else
        {
            // read end of fd1
            dup2(fd2[0], 0); // fd2[0] --> STDIN
            close(fd2[1]);
            close(fd1[0]);
            close(fd1[1]);
            execl("/bin/wc", "/bin/wc", "-l", NULL);
        }
    }

    return (0);
}
