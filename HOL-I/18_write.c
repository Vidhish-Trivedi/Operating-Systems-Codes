// Program Number : 18
// Name : Vidhish Trivedi
// Register Number : IMT2021055
// Date : 28/01/2023
// Description : Write a program to perform Record locking.
                // a. Implement write lock
                // b. Implement read lock
// Create three records in a file. Whenever you access a particular record, first lock it then modify/access
// to avoid race condition.

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "Q18.h"

int main(){
    int fd = open("tickets.txt", O_RDWR | O_CREAT, 0744);
    
    int i=0;
    for (i=0; i<4; i++){
        struct Record rec;
        int n;
        rec.theatre_no=i;

        scanf("%d",&n);
        rec.tickets=n;
        write(fd, &rec, sizeof(struct Record));
    }
   
    printf("Write successsful\n");
    close(fd);

    return 0;
}

// This is a helper program to write a certain number of tickets to the file, which will be used by Q17_main.c
