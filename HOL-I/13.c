// Program Number : 13
// Name : Vidhish Trivedi
// Register Number : IMT2021055
// Date : 22/01/2023
// Description : Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
// verify whether the data is available within 10 seconds or not (check in $man 2 select).

#include<stdio.h>
#include<fcntl.h>
#include<sys/select.h>

int main(){
    fd_set fds;
    struct timeval t_val;
    int retval;

    t_val.tv_sec = 5;
    t_val.tv_usec = 0;

    FD_ZERO(&fds);
    FD_SET(0, &fds);

    retval = select(1 ,&fds, NULL, NULL, &t_val);
    if (retval == -1)
    {
        perror("Error");
    }
    else if(retval){
        printf("Data is available now.\n");
    }
    else{
        printf("No data available in five seconds.\n");
    }
}
