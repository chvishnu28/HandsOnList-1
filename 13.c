
/*
----------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------

Name 13.c
Author :CHAVALA LAKSHMI VISHNU
Description:
Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select).




Date:7 Sept,2025


----------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/select.h>

int main() {
    fd_set readfds;
    struct timeval timeout;
    int ret;

    FD_SET(0, &readfds);
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    printf("Waiting for input (10 seconds)...\n");

    ret = select(1, &readfds, NULL, NULL, &timeout);

    if (ret == -1) {
        perror("select error");
        exit(1);
    } else if (ret == 0) {
        printf("Timeout! No data within 10 seconds.\n");
    } else {
        if (FD_ISSET(0, &readfds)) {
            printf("Data is available on STDIN!\n");
        }
    }

    return 0;
}
/*
----------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------

Output:
/syst$ ./a.out
Waiting for input (10 seconds)...
h
Data is available on STDIN!

----------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------
*/
