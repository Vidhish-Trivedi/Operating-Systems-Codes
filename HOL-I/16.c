// Program Number : 16
// Name : Vidhish Trivedi
// Register Number : IMT2021055
// Date : 28/01/2023
// Description : Write a program to perform mandatory locking.
                // a. Implement write lock
                // b. Implement read lock

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main(){
    int fd = open(argv[1], O_RDWR);
    printf("Press 1 for read lock, press 2 for write lock\n");
    int val;
    scanf("%d", &val);

    if(val == 1){
        //read lock

        char name[100];
        printf("Enter file name to lock: \n");
        scanf("%s", name);

        struct flock lock;
        lock.l_start = 0;
        lock.l_len = 0;
        lock.l_whence = SEEK_SET;
        lock.l_type = F_RDLCK;

        int fd;
        fd = open(name, O_RDONLY, 0744);
        printf("Before read lock\n");

        int res = fcntl(fd, F_SETLKW, &lock);
        if (res < 0){
            printf("Lock unsuccessful\n");
            return 0;
        }

        printf("Locked\n");

        getchar();
        getchar();
        printf("Unlocking\n");

        lock.l_type = F_UNLCK;
        fcntl(fd, F_SETLKW, &lock);  
        printf("Unlock successful");

        close(fd);
    }
    else if(val == 2){
        //write lock

        char name[100];
        printf("Enter name: \n");
        scanf("%s", name);

        struct flock lock;
        lock.l_start = 0;
        lock.l_len = 0;
        lock.l_whence = SEEK_SET;
        lock.l_type = F_WRLCK;

        int fd = open(name, O_WRONLY, 0744);
        printf("Before write lock\n");
        
        int res = fcntl(fd, F_SETLKW, &lock);
        if (res < 0){
            printf("Lock unsuccessful\n");
            return 0;
        }
        
        printf("Locked\n");

        getchar();
        getchar();
        printf("Unlocking\n");

        lock.l_type = F_UNLCK;
        fcntl(fd, F_SETLKW, &lock);  
        printf("Unlock successful");

        close(fd);
    }
    else{
        printf("Invalid choice\n");
    }
    return 0;
}