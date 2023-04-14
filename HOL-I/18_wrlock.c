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
    int fd;
    fd = open("tickets.txt", O_RDWR);

    write(1, "Enter the theatre number\n", sizeof("Enter the theatre number\n"));
    int theatre;
    scanf("%d", &theatre);

    struct flock lock;
    lock.l_whence = SEEK_SET;
    lock.l_len = sizeof(struct Record);
    lock.l_start = theatre*sizeof(struct Record);
    lock.l_type = F_WRLCK;

    fcntl(fd, F_SETLKW, &lock);

    struct Record rec;
    lseek(fd, theatre*sizeof(struct Record), SEEK_SET);
    read(fd, &rec, sizeof(struct Record));

    printf("Number of tickets: %d\n", rec.tickets);
    write(1, "Incrementing\n", sizeof("Incrementing\n"));
    rec.tickets += 1;

    lseek(fd, theatre*sizeof(struct Record), SEEK_SET);
    write(fd, &rec, sizeof(struct Record));
    
    char ch;
    read(0, &ch, sizeof(char));
    write(1, "Incremented. Now unlocking\n", sizeof("Incremented. Now unlocking\n"));

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLKW, &lock);
    printf("Unlocked\n");

    close(fd);

    return 0;
}

// Note: Program takes user input as the theatre number, and reads the tickets and increments them, while not locking the other records in the file

