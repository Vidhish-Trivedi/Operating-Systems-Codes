// Program Number : 09
// Name : Vidhish Trivedi
// Register Number : IMT2021055
// Date : 15/01/2023
// Description : Write a program to print the following information about a given file.
                // a. inode
                // b. number of hard links
                // c. uid
                // d. gid
                // e. size
                // f. block size
                // g. number of blocks
                // h. time of last access
                // i. time of last modification
                // j. time of last change

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

// Will use test_1.txt;
// Can also see comments in 14.c

int main(){
	struct stat fileStat;
	int fd = open("test_1.txt", O_RDONLY);

    int stats = lstat("test_1.txt", &fileStat);
    if(stats < 0){
        perror("Error");
        return(-1);
    }
	
	printf("Information for %s\n", "test_1.txt");
    printf("---------------------------\n");

    printf("File inode: \t\t%ju\n", fileStat.st_ino);
    printf("Number of Links: \t%ju\n", fileStat.st_nlink);
    printf("UID: \t\t%ju\n", (u_int64_t) fileStat.st_uid);
    printf("GID: \t%ju\n", (u_int64_t) fileStat.st_gid);
    printf("File Size: \t\t%jd bytes\n", fileStat.st_size);
    printf("Block Size: \t\t%jd\n", fileStat.st_blksize);
    printf("Number of Blocks: \t\t%jd\n", fileStat.st_blocks);
    printf("Time of Last Access: \t\t%s\n", ctime(&fileStat.st_atime));
    printf("Time of Last Modification: \t\t%s\n", ctime(&fileStat.st_mtime));
    printf("Time of Last Change: \t\t%s\n", ctime(&fileStat.st_ctime));

	close(fd);
	
	return 0;
}

