/*
Program Number : 01 - c
Name : Vidhish Trivedi
Register Number : IMT2021055
Date : 26/03/2023
Description : Program (for ITIMER_PROF) to set a interval timer in 10sec and 10 micro second.
*/

#include <stdio.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>

void handler()
{
    printf("Signal received\n");
}

int main()
{
    struct itimerval it;
    signal(SIGPROF, handler);

    /* Time to the next timer expiration.  */
    it.it_value.tv_sec = 10;
    it.it_value.tv_usec = 10;

    /* Value to put into `it_value' when the timer expires.  */
    it.it_interval.tv_sec = 10;
    it.it_interval.tv_usec = 10;

    setitimer(ITIMER_PROF, &it, NULL);

    while (1)
    {
    }
}
