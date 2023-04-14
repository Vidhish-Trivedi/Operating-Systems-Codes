// Program Number : 14
// Name : Vidhish Trivedi
// Register Number : IMT2021055
// Date : 22/01/2023
// Description : Write a program to find the type of a file.
// a. Input should be taken from command line.
// b. program should be able to identify any type of a file.

#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

// Run: ./a.out <file_name>
int main(int argc, char *argv[]) {
    struct stat sb;
    
    // Error handling.
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }
    if (lstat(argv[1], &sb) == -1) {
        perror("stat");
        return 2;
    }

    stat(argv[1], &sb);

    printf("File type: ");
    // With normal stat, softlink was giving wrong answer

    // Use man inode to get info about all this
    // printf("%d\n", (s.st_mode & __S_IFMT)>>12);

    // Macros to test the mode of the file, in <sys/stat.h>
    // Mode contains the opening mode as well as the file info
    if (S_ISREG(s.st_mode)){
        printf("Regular file\n");
    }
    else if (S_ISDIR(s.st_mode)){
        printf("Directory\n");
    }
    else if (S_ISCHR(s.st_mode)){
        printf("Character Device File\n");
    }
    else if (S_ISBLK(s.st_mode)){
        printf("Block device file\n");
    }
    else if (S_ISFIFO(s.st_mode)){
        printf("FIFO file\n");
    }
    else if (S_ISLNK(s.st_mode)){
        printf("Softlink file\n");
    }
    else if (S_ISSOCK(s.st_mode)){
        printf("Socket file\n");
    }
    else{
        printf("Unknown?\n");
    }

    // Details of file.
    // printf("I-node number:            %ld\n", (long) sb.st_ino);
    // printf("Mode:                     %lo (octal)\n", (unsigned long) sb.st_mode);
    // printf("Link count:               %ld\n", (long) sb.st_nlink);
    // printf("Ownership:                UID=%ld   GID=%ld\n", (long) sb.st_uid, (long) sb.st_gid);
    // printf("Preferred I/O block size: %ld bytes\n", (long) sb.st_blksize);
    // printf("File size:                %lld bytes\n", (long long) sb.st_size);
    // printf("Blocks allocated:         %lld\n", (long long) sb.st_blocks);
    // printf("Last status change:       %s", ctime(&sb.st_ctime));
    // printf("Last file access:         %s", ctime(&sb.st_atime));
    // printf("Last file modification:   %s", ctime(&sb.st_mtime));
    
    return(0);
}
