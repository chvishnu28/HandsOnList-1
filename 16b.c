/*
----------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------

Name 16b.c 
Author :CHAVALA LAKSHMI VISHNU
Description:
Write a program to perform mandatory locking.
a. Implement write lock
b. Implement read lock




Date:7 Sept,2025


----------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int fd;
    struct flock lock;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    fd = open(argv[1], O_RDONLY);
    lock.l_type = F_RDLCK;  
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;         

    printf("Trying for read lock...\n");
    fcntl(fd, F_SETLKW, &lock);
    printf("Read lock acquired! Press Enter to release...\n");
    getchar();

    lock.l_type = F_UNLCK;  
    fcntl(fd, F_SETLK, &lock);
    printf("Lock released.\n");

    close(fd);
    return 0;
}
/*
----------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------

Output:
/syst$ ./a.out a.c
Trying for read lock...
Read lock acquired! Press Enter to release...

Lock released.

----------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------
*/
