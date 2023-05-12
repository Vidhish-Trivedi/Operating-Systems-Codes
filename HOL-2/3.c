/*
Program Number : 03
Name : Vidhish Trivedi
Register Number : IMT2021055
Date : 26/03/2023
Description : Program to set (any one) system resource limit using setrlimit system call.
*/

#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <errno.h>

// Use sudo.
int main()
{
    struct rlimit rlim;
    printf("Old limits\n");
    getrlimit(RLIMIT_NICE, &rlim);

    printf("Soft - %lu\n", rlim.rlim_cur);
    printf("Hard - %lu\n", rlim.rlim_max);

    rlim.rlim_cur = 2;
    rlim.rlim_max = 3;

    if (setrlimit(RLIMIT_NICE, &rlim) != -1)
    {
        printf("New limits\n");
        getrlimit(RLIMIT_NICE, &rlim);

        printf("Soft - %lu\n", rlim.rlim_cur);
        printf("Hard - %lu\n", rlim.rlim_max);
    }
    else
    {
        perror("Error");
    }

    return(0);
}
