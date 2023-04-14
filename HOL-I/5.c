// Program Number : 05
// Name : Vidhish Trivedi
// Register Number : IMT2021055
// Date : 15/01/2023
// Description : Write a program to create five new files with infinite loop. Execute the program in the background
// and check the file descriptor table at /proc/pid/fd.

#include <stdio.h>
#include <fcntl.h>
#include <unistdio.h>

int main(){
	int f1 = open("file1_5.txt", O_CREAT, 0777);
	int f2 = open("file2_5.txt", O_CREAT, 0777);
	int f3 = open("file3_5.txt", O_CREAT, 0777);
	int f4 = open("file4_5.txt", O_CREAT, 0777);
	int f5 = open("file5_5.txt", O_CREAT, 0777);
	for(;;){}
	return(0);
}
