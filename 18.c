
/*
----------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------

Name 18.c
Author :CHAVALA LAKSHMI VISHNU
Description:
. Write a program to perform Record locking.
a. Implement write lock
b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition.




Date:7 Sept,2025


----------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

// Record structure
struct record {
    int id;
    char name[20];
};

int main() {
    int fd;
    struct record rec;
    struct flock lock;
    fd = open("18exmp.txt", O_RDWR | O_CREAT, 0644);
    if (fd < 0) {
        perror("open");
        exit(1);
    }
    if (lseek(fd, 0, SEEK_END) == 0) {
        for (int i = 0; i < 3; i++) {
            rec.id = i + 1;
            sprintf(rec.name, "Record_%d", i + 1);
            write(fd, &rec, sizeof(rec));
        }
    }

    int recno;
    printf("Enter record number (1-3): ");
    scanf("%d", &recno);
    lock.l_type = F_WRLCK;   
    lock.l_whence = SEEK_SET;
    lock.l_start = (recno - 1) * sizeof(rec); 
    lock.l_len = sizeof(rec);                 
    lock.l_pid = getpid();
    printf("Trying to lock record %d...\n", recno);
    fcntl(fd, F_SETLKW, &lock);
    
    printf("Locked record %d successfully!\n", recno);

   
    lseek(fd, (recno - 1) * sizeof(rec), SEEK_SET);
    read(fd, &rec, sizeof(rec));
    printf("Current record: id=%d name=%s\n", rec.id, rec.name);
    printf("Enter new name: ");
    scanf("%s", rec.name);

    lseek(fd, (recno - 1) * sizeof(rec), SEEK_SET);
    write(fd, &rec, sizeof(rec));

    printf("Record updated!\n");
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    printf("Unlocked record %d\n", recno);

    close(fd);
    return 0;
}
/*
----------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------

Output:
./a.out a.c
Enter record number (1-3): 1
Trying to lock record 1...
Locked record 1 successfully!
Current record: id=1 name=hi
Enter new name: 2
Record updated!
Unlocked record 1

----------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------
*/
