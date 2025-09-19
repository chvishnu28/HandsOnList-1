/*
----------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------

Name 29.c
Author :CHAVALA LAKSHMI VISHNU
Description:

Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
SCHED_RR).



Date:7 Sept,2025


----------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>
#include <errno.h>
#include <string.h>

int main() {
    int policy;
    struct sched_param param;
    policy = sched_getscheduler(0); 
    printf("Current scheduling policy: ");
    switch (policy) {
        case SCHED_OTHER: printf("SCHED_OTHER (normal)\n"); break;
        case SCHED_FIFO:  printf("SCHED_FIFO (real-time, FIFO)\n"); break;
        case SCHED_RR:    printf("SCHED_RR (real-time, Round Robin)\n"); break;
        default:          printf("Unknown\n"); break;
    }

    // Set scheduling policy to SCHED_FIFO with priority 50
    param.sched_priority = 50; 
    sched_setscheduler(0, SCHED_FIFO, &param);
     printf("Scheduling policy changed to SCHED_FIFO with priority %d\n", param.sched_priority);
    

    return 0;
}
/*
----------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------

Output:
Current scheduling policy: SCHED_OTHER (normal)
Scheduling policy changed to SCHED_FIFO with priority 50

----------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------
*/
