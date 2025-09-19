/*
----------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------

Name 14.c
Author :CHAVALA LAKSHMI VISHNU
Description:
Write a program to find the type of a file.
a. Input should be taken from command line.
b. program should be able to identify any type of a file.




Date:7 Sept,2025


----------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    struct stat fileStat;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }
    if (S_ISREG(fileStat.st_mode))
        printf("It is a Regular File\n");
    else if (S_ISDIR(fileStat.st_mode))
        printf("It is a Directory\n");
    else if (S_ISCHR(fileStat.st_mode))
        printf("It is a Character Device\n");
    else if (S_ISBLK(fileStat.st_mode))
        printf("It is a Block Device\n");
    else if (S_ISFIFO(fileStat.st_mode))
        printf("It is a FIFO (Named Pipe)\n");
    else if (S_ISLNK(fileStat.st_mode))
        printf("It is a Symbolic Link\n");
    else if (S_ISSOCK(fileStat.st_mode))
        printf("It is a Socket\n");
    else
        printf("Unknown File Type\n");

    return 0;
}
/*
----------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------

Output:
~/syst$ ./a.out 1.c
It is a Regular File
----------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------
*/
