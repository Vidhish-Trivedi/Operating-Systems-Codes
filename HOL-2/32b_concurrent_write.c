/*
Program Number : 32 - b
Name : Vidhish Trivedi
Register Number : IMT2021055
Date : 08/04/2023
Description : Program to implement semaphore to protect any critical section.
                b. protect shared memory from concurrent write access
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

union semun
{
    int val;
    struct semid_ds *buf;
    unsigned short int *array;
};

int main()
{
    union semun arg;

    // Set up a shared memory.
    key_t key = ftok(".", 'a');
    int shmid = shmget(key, 1024, IPC_CREAT | 0744);
    int semid = semget(key, 1, IPC_CREAT | 0744);
    char *data = shmat(shmid, (void *)0, 0);

    int pid = fork();
    if (!pid)
    {
        // Lock from child process.
        struct sembuf buf = {0, -1, SEM_UNDO};
        int retval = semop(semid, &buf, 1);
        printf("Child is writing\n");
        printf("Enter the text: ");
        scanf("%[^\n]s", data);
        printf("Data written by child \n");

        // Unlock from child.
        buf.sem_op = 1;
        semop(semid, &buf, 1);
        return 0;
    }
    else
    {
        // Lock from parent.
        struct sembuf buf = {0, -1, SEM_UNDO};
        int retval = semop(semid, &buf, 1);
        int wstatus;
        printf("Parent is writing\n");
        printf("Enter the text: ");
        scanf("%[^\n]s", data);
        printf("Data written by Parent\n");
        buf.sem_op = 1;

        // Wait for user to press return.
        getchar();
        getchar();

        // Unlock from parent.
        semop(semid, &buf, 1);
        waitpid(pid, &wstatus, W_OK);
    }

    // Fetch data from the shared memory.
    printf("Data: %s\n", data);
    shmdt(data);
    shmctl(shmid, IPC_RMID, NULL);
    return (0);
}
