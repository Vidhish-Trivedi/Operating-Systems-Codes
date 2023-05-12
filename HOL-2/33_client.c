/*
Program Number : 33 - client
Name : Vidhish Trivedi
Register Number : IMT2021055
Date : 08/04/2023
Description : Client program to communicate between two machines using socket.
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main()
{
    struct sockaddr_in serv;
    int sd;

    sd = socket(AF_INET, SOCK_STREAM, 0);
    serv.sin_family = AF_INET;
    serv.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv.sin_port = htons(5000);

    connect(sd, (struct sockaddr *)&serv, sizeof(serv));
    
    // read/write
    char buf[100];
    int ret;
    write(1, "Sending message to server...\n", sizeof("Sending message to server...\n"));
    write(sd, "Message From client\n", sizeof("Message From client\n"));
    write(1, "Sent!\nPress return key to read...\n", sizeof("Sent!\nPress return key to read...\n"));
    getchar();
    ret = read(sd, buf, sizeof(buf));
    write(1, buf, ret);
    
    close(sd);

    return (0);
}
