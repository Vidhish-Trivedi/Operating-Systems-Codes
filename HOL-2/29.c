/*
Program Number : 29
Name : Vidhish Trivedi
Register Number : IMT2021055
Date : 05/04/2023
Description : Program to remove the message queue.
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>

// Remove a message queue.
int main()
{
    key_t key = ftok(".", 'a');
    int msqid = msgget(key, 0);

    (msgctl(msqid, IPC_RMID, NULL) == -1) ? printf("Delete unsuccessful\n") : printf("Delete successful\n");
    
    return (0);
}
