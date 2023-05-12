/*
Program Number : 32 - b - 1
Name : Vidhish Trivedi
Register Number : IMT2021055
Date : 08/04/2023
Description : Program to implement semaphore to protect any critical section.
                b. protect shared memory from concurrent write access
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <unistd.h>

#define SHM_SIZE 1024

union semun
{
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

int main()
{

    // Generate unique keys for shared memory and semaphore
    // Current directory and different id to differentiate
    int shm_key = ftok(".", 'S');
    int sem_key = ftok(".", 'T');

    // Create the shared memory segment of size 1024
    int shm_id = shmget(shm_key, 1024, IPC_CREAT | 0666);
    int sem_id = semget(sem_key, 1, IPC_CREAT | 0666);

    // Set the semaphore value to 1 - Binary semaphore
    union semun sem_args;
    sem_args.val = 1;
    if (semctl(sem_id, 0, SETVAL, sem_args) == -1)
    {
        printf("Error in semctl system call\n");
        return -1;
    }

    // Attach the shared memory segment to process address space
    int *shm_ptr = shmat(shm_id, NULL, 0);
    if (shm_ptr == (void *)-1)
    {
        // Error while attaching
        printf("Error in shmat call\n");
        return -1;
    }

    // Initialize the shared data - pointer
    *shm_ptr = 0;
}