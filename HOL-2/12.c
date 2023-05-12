/*
Program Number : 12
Name : Vidhish Trivedi
Register Number : IMT2021055
Date : 26/03/2023
Description : Program to create an orphan process. Use kill system call to send SIGKILL signal to 
              the parent process from the child process.
*/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main()
{
    // Child Process
    if (!fork())
    {
        sleep(5);
        printf("Child is waiting, pid: %d\n", getpid());
        kill(getppid(), 9);
        printf("Parent process killed\n");
        sleep(10);
    }
    else
    {
        printf("Parent Process, pid: %d\n", getpid());
        sleep(15);
    }

    return 0;
}
