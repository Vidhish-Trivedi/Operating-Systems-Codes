/*
Program Number : 26
Name : Vidhish Trivedi
Register Number : IMT2021055
Date : 05/04/2023
Description : Program to send messages to the message queue. Check $ipcs -q
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>

struct my_msg
{
    long mtype;
    char mtext[80];
};

int main()
{
    key_t key = ftok(".", 'a');
    int msqid = msgget(key, IPC_CREAT | 0666);
    // printf("%d\n", msqid);

    struct my_msg msg;
    msg.mtype = 10;
    char text[80];
    printf("Enter message:\n");
    scanf("%[^\n]s", text);

    strcpy(msg.mtext, text);
    
    (msgsnd(msqid, (struct msgbuf *)&msg, 80, 0) == -1) ? printf("Message send failed.\n") : printf("Message sent successfully.\n");

    return (0);
}
