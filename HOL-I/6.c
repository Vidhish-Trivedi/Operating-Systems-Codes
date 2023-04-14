// Program Number : 06
// Name : Vidhish Trivedi
// Register Number : IMT2021055
// Date : 15/01/2023
// Description : Write a program to take input from STDIN and display on STDOUT.
// Use only read/write system calls

#include <stdio.h>
#include <unistd.h>
#include<string.h>

int main(){
	char t[1000];
	read(0,t, 1000);
	int cnt = 0;

	for(int i = 0; i < 1000; i++){
		if(t[i] == '\n'){
			break;
		}
		else{
			cnt++;
		}
	}
	
	write(1, t, cnt);
	return(0);
}

