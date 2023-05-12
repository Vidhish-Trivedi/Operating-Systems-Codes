/*
Program Number : 34 - Using fork
Name : Vidhish Trivedi
Register Number : IMT2021055
Date : 08/04/2023
Description : Program to create a concurrent server using fork(), use 33_client.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char const *argv[])
{
    int socket_fd, new_socket_fd;
    struct sockaddr_in server_address, client_address;
    char buffer[MAX_BUFFER_SIZE] = {0};

    // Create socket
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_address.sin_port = htons(5555);

    // Bind socket to address
    if (bind(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(socket_fd, 5) < 0)
    {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", 5555);

    // Handle incoming connections
    while (1)
    {

        int address_len = sizeof(client_address);

        // Accept new connection
        if ((new_socket_fd = accept(socket_fd, (struct sockaddr *)&client_address, (socklen_t *)&address_len)) < 0)
        {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        // Fork to handle new connection
        int pid = fork();
        if (pid < 0)
        {
            perror("Fork failed");
            exit(EXIT_FAILURE);
        }
        else if (pid == 0)
        {
            // Child process

            printf("Handling client from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

            // Receive message from client
            int read_size = read(new_socket_fd, buffer, MAX_BUFFER_SIZE);
            if (read_size < 0)
            {
                perror("Read failed");
                exit(EXIT_FAILURE);
            }

            printf("Received message from client: %s\n", buffer);

            // Send message to client
            char *message = "Hello from server";
            int write_size = write(new_socket_fd, message, strlen(message));
            if (write_size < 0)
            {
                perror("Write failed");
                exit(EXIT_FAILURE);
            }

            printf("Sent message to client: %s\n", message);

            // Close connection
            close(new_socket_fd);
            exit(EXIT_SUCCESS);
        }
        else
        {
            // Parent process
            close(new_socket_fd);
        }
    }

    // Close socket
    close(socket_fd);

    return 0;
}
