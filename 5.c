/*
----------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------

Name: 5.c 
Author :CHAVALA LAKSHMI VISHNU
Description:
Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd.




Date:7 Sept,2025


----------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------
*/


#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	int fd[5];
	char s[20];

	for(int i=0;i<5;i++)
	{
		sprintf(s,"file%d",i+1);
		fd[i]=creat(s,0666);
         

		if(fd[i]==-1)
		{
			perror("creat");
			return -1;
		}
	
	printf("Created succesfull filename %s and file descriptor %d\n",s,fd[i]);

	}
	while(1)
	{
	}
}

/*
----------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------

Output:
Created succesfull filename file1 and file descriptor 3
Created succesfull filename file2 and file descriptor 4
Created succesfull filename file3 and file descriptor 5
Created succesfull filename file4 and file descriptor 6
Created succesfull filename file5 and file descriptor 7



----------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------
*/

