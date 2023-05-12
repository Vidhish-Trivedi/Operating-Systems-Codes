/*
Program Number : 08
Name : Vidhish Trivedi
Register Number : IMT2021055
Date : 26/03/2023
Description : Program using signal system call to catch the following signals.
                a. SIGSEGV
                b. SIGINT
                c. SIGFPE
                d. SIGALRM (use alarm system call)
                e. SIGALRM (use setitimer system call)
                f. SIGVTALRM (use setitimer system call)
                g. SIGPROF (use setitimer system call)
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <signal.h>

void handler1()
{
    printf("Segmentation fault caught\n");
    exit(0);
}

void handler2()
{
    printf("\nSIGINT received\n");
    exit(0);
}

void handler3()
{
    printf("Floating point error caught\n");
    exit(0);
}

void handler(int signum)
{
    printf("Signal received (alarm related)\n");
    // exit(0);
}

int main()
{
    int choice, x, y;
    printf("Choose an option:\n1.) SIGSEGV\n2.) SIGINT\n3.) SIGFPE\n4.) SIGALRM (alarm system call)\n5.) SIGALRM (setitimer system call)\n6.) SIGVTALRM (setitimer system call)\n7.) SIGPROF (setitimer system call)\n=> ");
    scanf("%d", &choice);

    struct itimerval it;
    // Set timer value.
    it.it_value.tv_sec = 2;
    it.it_value.tv_usec = 0;

    // Reset value on timer after completion.
    it.it_interval.tv_sec = 2;
    it.it_interval.tv_usec = 0;

    switch (choice)
    {
    case 1:
        signal(SIGSEGV, handler1);

        char *str;
        str = NULL;
        printf("%c\n", *(str + 1));

        printf("No segmentation fault\n");
        break;
    case 2:
        signal(SIGINT, handler2);
        printf("Waiting 5 seconds for SIGINT\n");
        sleep(5);
        break;
    case 3:
        x = 3;
        y = 0;
        signal(SIGFPE, handler3);
        printf("%d\n", x / y);

        printf("No error\n");
        break;
    case 4:
        signal(SIGALRM, handler);

        while (1)
        {
            printf("Alarm set\n");
            alarm(2);
            sleep(3);
        }
        break;
    case 5:
        signal(SIGALRM, handler);
        setitimer(ITIMER_REAL, &it, NULL);

        while (1)
        {
        }
        break;
    case 6:
        signal(SIGVTALRM, handler);
        setitimer(ITIMER_VIRTUAL, &it, NULL);

        while (1)
        {
        }
        break;
    case 7:
        signal(SIGPROF, handler);
        setitimer(ITIMER_PROF, &it, NULL);

        while (1)
        {
        }
        break;

    default:
        printf("Invalid choice\n");
        break;
    }

    return (0);
}
