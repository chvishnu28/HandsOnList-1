
/*
----------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------

Name 30.c 
Author :CHAVALA LAKSHMI VISHNU
Description:
Write a program to run a script at a specific time using a Daemon process.





Date:7 Sept,2025


----------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s HH:MM\n", argv[0]);
        exit(1);
    }

    int target_hour, target_min;
    if (sscanf(argv[1], "%d:%d", &target_hour, &target_min) != 2) {
        fprintf(stderr, "Invalid time format. Use HH:MM\n");
        exit(1);
    }
    int pid = fork();
    setsid();
    chdir("/");

    close(STDIN_FILENO);
    while (1) {
        time_t now = time(NULL);
        struct tm *t = localtime(&now);

        if (t->tm_hour == target_hour && t->tm_min == target_min && t->tm_sec == 0) {
            printf("Hello! The daemon executed at %02d:%02d\n", target_hour, target_min);
            fflush(stdout);
            break;  
        }
        sleep(1);
    }

    return 0;
}

/*
----------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------

Output:
a.out 18:56
Hello! The daemon executed at 18:56
Hello! The daemon executed at 18:56

----------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------
*/

Write a program to get maximum and minimum real time priority.
