// Program Number : 02
// Name : Vidhish Trivedi
// Register Number : IMT2021055
// Date : 15/01/2023
// Description : Write a simple program to execute in an infinite loop at the background. Go to /proc directory and
// identify all the process related information in the corresponding proc directory.

#include <stdio.h>

int main(){
	for(;;){}
	return 0;
}

// ./a.out & -> & is used to run in the background, it returns the pid
// cd /proc/pid will take you to the respective process
// then cat status
// then to kill the process bring it to foreground using fg and ctrl+c
// or do kill pid
