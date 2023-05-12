/*
Program Number : 34 - Using threads
Name : Vidhish Trivedi
Register Number : IMT2021055
Date : 08/04/2023
Description : Program to create a concurrent server using threads, use 33_client.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <fcntl.h>
#include <pthread.h>
#include <arpa/inet.h>

void *connection(void *nsd)
{
    int nsfd = *(int *)nsd;
    write(nsfd, "Message From server\n", sizeof("Message From server\n"));
}

int main()
{
    struct sockaddr_in server, client;
    int sd, nsd, clientLen;
    pthread_t threads;
    bool result;
    sd = socket(AF_INET, SOCK_STREAM, 0);

    // Keeping localhost as the server address , same as client for demo purpose
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(5555);

    bind(sd, (struct sockaddr *)&server, sizeof(server));
    listen(sd, 5);

    write(1, "Waiting for the client.....\n", sizeof("Waiting for the client.....\n"));

    while (1)
    {
        clientLen = sizeof(client);
        nsd = accept(sd, (struct sockaddr *)&client, &clientLen);

        write(1, "Connected to the client.....\n", sizeof("Connected to the client.....\n"));
        if (pthread_create(&threads, NULL, (void *)connection, (void *)&nsd) < 0)
        {
            perror("could not create thread");
            return 1;
        }
    }
    pthread_exit(NULL);
    close(sd);
    return 0;
}