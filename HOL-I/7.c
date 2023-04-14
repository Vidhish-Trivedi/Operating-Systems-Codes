// Program Number : 07
// Name : Vidhish Trivedi
// Register Number : IMT2021055
// Date : 15/01/2023
// Description : Write a program to copy file1 into file2 ($cp file1 file2).

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
	int fsrc = open("src_7.txt", O_RDONLY);
	char t[10000];
	read(fsrc, t, 10000);

	/* for(int i = 0; i < 1000; i++){ */
	/* 	printf("%c\n", t[i]); */
	/* } */

	int fdes = open("des_7.txt", O_CREAT | O_WRONLY);
	int i = 0;
	while(t[i] != '\0'){
		write(fdes, &t[i], 1);
		i++;
	}
	printf("Done!\n");

    close(fsrc);
    close(fdes);
	
	return 0;
}

