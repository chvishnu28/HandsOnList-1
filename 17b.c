
/*
----------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------

Name 17.b 
Author :CHAVALA LAKSHMI VISHNU
Description:
Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.




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
    int ticket;
    struct flock lock;

    fd = open("ticket.txt", O_RDWR);
    if (fd < 0) {
        perror("open");
        exit(1);
    }

    // Set write lock (exclusive)
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    printf("Trying to acquire write lock...\n");
    fcntl(fd, F_SETLKW, &lock);

    // Read current ticket number
    read(fd, &ticket, sizeof(ticket));

    // Increment ticket number
    ticket++;
    printf("New ticket number reserved: %d\n", ticket);

    // Move file pointer to start and update the ticket
    lseek(fd, 0, SEEK_SET);
    write(fd, &ticket, sizeof(ticket));
     printf("Enter to unlock");
     getchar();
    // Unlock
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    close(fd);
    return 0;
}
/*
----------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------

Output: 
 ./a.out a.c
Trying to acquire write lock...
New ticket number reserved: 101
Enter to unlock

----------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------
*/
