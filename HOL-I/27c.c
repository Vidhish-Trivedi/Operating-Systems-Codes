// Program Number : 27
// Name : Vidhish Trivedi
// Register Number : IMT2021055
// Date : 17/02/2023
// Description : Write a program to execute ls -Rl by the following system calls
                // a. execl
                // b. execlp
                // c. execled
                // d. execv
                // e. execvp

#include<stdio.h>
#include<unistd.h>

int main(int argc, char *argv[], char *envp[]){
    printf("Executes ls -Rl using execle");
    execle("/bin/ls", "/bin/ls", "-R", "-l", NULL, envp);
    return(0);
}
