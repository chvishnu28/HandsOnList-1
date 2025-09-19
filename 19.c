
/*
----------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------

Name 19.c 
Author :CHAVALA LAKSHMI VISHNU
Description:

Write a program to find out time taken to execute getpid system call. Use time stamp counter.



Date:7 Sept,2025


----------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------
*/
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>

// Function to read the CPU time stamp counter
unsigned long long rdtsc() {
    unsigned int lo, hi;
    __asm__ __volatile__("rdtsc" : "=a"(lo), "=d"(hi));
    return ((unsigned long long)hi << 32) | lo;
}

int main() {
    unsigned long long start, end;
    int pid;

    // Take timestamp before system call
    start = rdtsc();

    // Call system call
    pid = getpid();

    // Take timestamp after system call
    end = rdtsc();

    printf("Process ID = %d\n", pid);
    printf("Time taken by getpid() = %llu CPU cycles\n", end - start);

    return 0;
}
/*
----------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------

Output:
Process ID = 10494
Time taken by getpid() = 41320 CPU cycles

----------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------
*/
