/*
Program Number : 06
Name : Vidhish Trivedi
Register Number : IMT2021055
Date : 26/03/2023
Description : Simple program to create three threads.
*/

#include <pthread.h>
#include <stdio.h>
// Use gcc 6.c -lpthread

void show_thread(void)
{
    printf("This is a thread\n");
}

int main()
{
    pthread_t t1, t2, t3;

    pthread_create(&t1, NULL, (void *)show_thread, NULL);
    pthread_create(&t2, NULL, (void *)show_thread, NULL);
    pthread_create(&t3, NULL, (void *)show_thread, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    return 0;
}
