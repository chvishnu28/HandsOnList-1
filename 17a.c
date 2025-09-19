
/*
----------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------

Name 17a.c
Author :CHAVALA LAKSHMI VISHNU
Description:

Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the fil




Date:7 Sept,2025


----------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------
*/


#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    int ticket = 100; 
    struct flock lock;

    fd = open("ticket.txt", O_RDWR | O_CREAT, 0644);
    if (fd < 0) {
        perror("open");
        exit(1);
    }

    fcntl(fd, F_SETLKW, &lock);
      
    write(fd, &ticket, sizeof(ticket));

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    close(fd);
    printf("Ticket number initialized to %d\n", ticket);
    return 0;
}
/*
----------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------

Output:
~/syst$ ./a.out a.c
Ticket number initialized to 100

----------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------
*/
