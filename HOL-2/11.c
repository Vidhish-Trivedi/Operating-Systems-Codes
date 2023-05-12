/*
Program Number : 11
Name : Vidhish Trivedi
Register Number : IMT2021055
Date : 26/03/2023
Description : Program to ignore a SIGINT signal then reset the default action of the SIGINT signal using sigaction system call.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <bits/sigaction.h>

int main(){
    struct sigaction act;
    
    memset(&act,0,sizeof(act));
    act.sa_handler = SIG_IGN;
    printf("Ignoring SIGINT\n");
    sigaction(SIGINT,&act,NULL);
    sleep(7);
    
    memset(&act,0,sizeof(act));
    act.sa_handler = SIG_DFL;
    printf("\nDefault of SIGINT\n");
    sigaction(SIGINT,&act,NULL);
    sleep(7);
    
    return(0);
}
