/*
----------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------

Name 
Author :CHAVALA LAKSHMI VISHNU
Description:
Write a program to find out the opening mode of a file. Use fcntl




Date:7 Sept,2025


----------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------
*/


#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	int fd,flag;
        int acc;
	if(argc!=2)
	{
		write(2,"Error",5);
		exit(1);
	}
               
	fd=open(argv[1],O_RDWR|O_CREAT, 0644);
	flag=fcntl(fd,F_GETFL);
        acc=flag & O_ACCMODE;
	
		if(acc== O_RDONLY)
			printf("File opened in Read Only Node\n");
		if(acc== O_WRONLY)
		        printf("File opened in write only mode\n");
		
		if(acc== O_RDWR)
		         printf("File opened in read and write mode\n");
		else
			 printf("Unknown mode");

	
	close(fd);
	return 0;

}
/*
----------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------

Output:
:~/syst$ ./a.out a.c
File opened in read and write mode

----------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------
*/
