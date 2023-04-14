// Program Number : 15
// Name : Vidhish Trivedi
// Register Number : IMT2021055
// Date : 22/01/2023
// Description : Write a program to display the environmental variable of the user (use environ).

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
	extern char **environ;
	int i = 0;
	while(environ[i] != NULL){
		if(environ[i][0] == 'U' && environ[i][4] == '='){
			printf("%s\n", environ[i]);
		}
		i++;
	}
	return 0;
}

