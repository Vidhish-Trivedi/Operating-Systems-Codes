// Program Number : 08
// Name : Vidhish Trivedi
// Register Number : IMT2021055
// Date : 15/01/2023
// Description : Write a program to open a file in read only mode, read line by line and display each line as it is read.
// Close the file when end of file is reached.

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	int fd = open("src_8.txt", O_RDONLY);
	lseek(fd, 0, SEEK_SET);
	char t[1];
	t[0] = '1';
	while(&t[0] != NULL){
		read(fd, t, 1);
		if(t[0] == '\n'){
			getchar();
		}
		write(1, t, 1);
	}
    
    close(fd);

	return 0;
}

