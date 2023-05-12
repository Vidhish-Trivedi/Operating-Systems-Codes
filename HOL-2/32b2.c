/*
Program Number : 32 - b - 2
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

struct sembuf sops;

int main()
{
    // Generate unique keys for shared memory and semaphore
    // Current directory and different id to differentiate
    int shm_key = ftok(".", 'S');
    int sem_key = ftok(".", 'T');

    // Create the shared memory segment of size 1024
    int shm_id = shmget(shm_key, 1024, 0);

    // Attach the shared memory segment to process address space
    int *shm_ptr = shmat(shm_id, NULL, 0);
    if (shm_ptr == (void *)-1)
    {
        // Error while attaching
        printf("Error in shmat call\n");
        return -1;
    }

    int sem_id = semget(sem_key, 1, 0);
    if (sem_id == -1)
    {
        printf("Error in semget system call\n");
        return -1;
    }

    // Use the semaphore to protect the shared memory
    sops.sem_num = 0;
    sops.sem_op = -1;
    sops.sem_flg = 0;

    printf("Before critical section: counter = %d\n", *shm_ptr);

    if (semop(sem_id, &sops, 1) == -1)
    {
        printf("Error in semop system call\n");
        return -1;
    }

    // This is the critical section
    int temp = *shm_ptr;
    temp++;
    *shm_ptr = temp;
    // CHANGING SHARED MEMORY SEGMENT

    printf("After critical section: counter = %d\n", *shm_ptr);

    printf("Enter u to unlock the lock\n");
    char ch;
    scanf("%c", &ch);

    while (ch != 'u')
    {
        printf("Invalid input, enter 'u' to unlock: ");
        scanf(" %c", &ch);
    }

    // Release the semaphore
    sops.sem_op = 1;
    if (semop(sem_id, &sops, 1) == -1)
    {
        printf("Error in semop system call\n");
        return -1;
    }

    // Detach the shared memory segment
    if (shmdt(shm_ptr) == -1)
    {
        printf("Error in shmdt system call\n");
        return -1;
    }

    return 0;
}
