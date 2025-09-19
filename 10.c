

/*
----------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------

Name 10.c
Author :CHAVALA LAKSHMI VISHNU
Description: Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.





Date:7 Sept,2025


----------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------
*/


#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
	int fd;
	off_t offset,filesize;
	if(argc!=2) {
		printf("Error");
	}
	char buf1[]="ABCDEFGHIJ";
	char buf2[]="1234567890";
	fd=open(argv[1],O_RDWR|O_CREAT|O_TRUNC,0644);

	write(fd,buf1,10);
	offset=lseek(fd,10,SEEK_CUR);
	printf("lseek moved to offset:%ld\n",offset);
	write(fd,buf2,10);
	close(fd);
	return 0;


}

/*
----------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------

Output:
 gcc 10.c
 HP-Laptop-15-da0xxx:~/syst$ ./a.out  9.c
lseek moved to offset:20
vishnu@vishnu-HP-Laptop-15-da0xxx:~/syst$

----------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------
*/

Hello from fd
Hello from fd_new
