/*
Program Number : 24
Name : Vidhish Trivedi
Register Number : IMT2021055
Date : 05/04/2023
Description : Program to create a message queue and print the key and message queue id.
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>

// Create a message queue.
int main()
{
    key_t key = ftok(".", 'a');
    int msqid = msgget(key, IPC_CREAT | 0666);
    printf("Key: %d, ID: %d\n", key, msqid);
    return(0);
}
