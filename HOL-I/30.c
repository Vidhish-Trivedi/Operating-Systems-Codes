// Program Number : 30
// Name : Vidhish Trivedi
// Register Number : IMT2021055
// Date : 18/02/2023
// Description : Write a program to run a script at a specific time using a Daemon process.

# include <stdio.h>
# include <unistd.h>
# include <sys/stat.h>
# include <stdlib.h>
int main()
{
    int ret = fork();
    
    // if(ret < 0){
    //     printf("Error\n");
    //     exit();
    // }

    if (ret > 0){
        //parent, fork returns the child pid value

        printf("Daemon process id: %d\n", ret);
        exit(0);
    }else if (ret < 0){
        perror("Error in fork:");
    }

    setsid();
    chdir("/");
    umask(0);

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    while(1){
        continue;
    }

    // When we get the process id, we can do kill -15 pid to kill the Daemon process

    return 0;
}