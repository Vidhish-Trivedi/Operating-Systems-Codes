/*
Program Number : 30 - a
Name : Vidhish Trivedi
Register Number : IMT2021055
Date : 08/04/2023
Description : Program to create a shared memory.
                a. write some data to the shared memory
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

int main()
{
    key_t key = ftok(".", 'a');
    int shmid = shmget(key, 1024, IPC_CREAT | 0666);

    char *data = shmat(shmid, (void *)0, 0);
    printf("Enter text to put in shared memory: ");
    scanf("%[^\n]s", data);

    printf("Write successful\n");
    return(0);
}