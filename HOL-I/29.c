// Program Number : 29
// Name : Vidhish Trivedi
// Register Number : IMT2021055
// Date : 12/02/2023
// Description : Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
// SCHED_RR).

#include <bits/types/struct_sched_param.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sched.h>

int main(){
	printf("The current scheduling policy is: %d\n", sched_getscheduler(getpid()));
	printf("Enter a choice number to change policy:\n");
	printf("1. SCHED_RR\n");
	printf("2. SCHED_FIFO\n");
	
	struct sched_param sp;
	sp.sched_priority = 50;

	int choice = 0;
	while(choice != 1 && choice != 2){
		scanf("%d", &choice);
	}
	if(choice == 1){
		sched_setscheduler(getpid(), SCHED_RR, &sp);
		printf("Scheduling policy changed to SCHED_RR\n");
		printf("The current scheduling policy is: %d\n", sched_getscheduler(getpid()));
	}
	else if (choice == 2){
		sched_setscheduler(getpid(), SCHED_FIFO, &sp);
		printf("Scheduling policy changed to SCHED_FIFO\n");
		printf("The current scheduling policy is: %d\n", sched_getscheduler(getpid()));
	}
	return 0;
}

