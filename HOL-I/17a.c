// Program Number : 17
// Name : Vidhish Trivedi
// Register Number : IMT2021055
// Date : 28/01/2023
// Description : Write a program to simulate online ticket reservation. Implement write lock
// Write a program to open a file, store a ticket number and exit. Write a separate program, to
// open the file, implement write lock, read the ticket number, increment the number and print
// the new ticket number then close the file.

// Note: Run Q17b.c first, then this program. It will read the tickets entered in the file,
// increment and write back to the file. It uses write lock.
 

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/stat.h>

int main(int argc,char *argv[]){
    int fd;
    write(1, "Before lock\n", sizeof("Before lock\n"));
    fd = open("tickets.txt", O_RDWR);

    struct flock lock;
    lock.l_whence = SEEK_SET;
    lock.l_len = 0;
    lock.l_start = 0;
    lock.l_type = F_WRLCK;

    fcntl(fd, F_SETLKW, &lock);
    int num;
    lseek(fd, 0, SEEK_SET);
    read(fd, &num, sizeof(int));

    printf("Number of tickets: %d\n", num);
    printf("Incrementing\n");
    num += 1;

    lseek(fd, 0, SEEK_SET);
    write(fd, &num, sizeof(int));

    char ch;
    read(0, &ch, sizeof(char));
    write(1, "Incremented. Now unlocking\n", sizeof("Incremented. Now unlocking\n"));

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLKW, &lock);
    printf("Unlocked\n");

    close(fd);

    return 0;   
}