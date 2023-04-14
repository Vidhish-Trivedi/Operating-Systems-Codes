// Program Number : 01
// Name : Vidhish Trivedi
// Register Number : IMT2021055
// Date : 15/01/2023
// Description : Create the following types of a files using (i) shell command (ii) system call
				// a. soft link (symlink system call)
				// b. hard link (link system call)
				// c. FIFO (mkfifo Library Function or mknod system call)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int main(){
	printf("Enter: file, soft link, hard link, fifo file name: ");
	char a[128], b[128], c[128], d[128];
	scanf("%s %s %s %s", a, b, c, d);

	int sl = symlink(a, b);
	int hl = link(a, c);
	int fifo = mkfifo(d, 0666);

	if(sl == 0){
		printf("Soft link created successfully.\n");
	}
	else{
		printf("Unable to create soft link.\n");
	}

	if(hl == 0){
		printf("Hard link created successfully.\n");
	}
	else{
		printf("Unable to create hard link.\n");
	}

	if(fifo == 0){
		printf("FIFO file created successfully.\n");
	}
	else{
		printf("Unable to create FIFO file.\n");
	}

	return 0;
}

