/*
----------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------

Name 8.c
Author :CHAVALA LAKSHMI VISHNU
Description:
Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached




Date:7 Sept,2025


----------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------
*/



#include <fcntl.h>     
#include <unistd.h>    
#include <stdlib.h>   
#include <string.h>    
#include <stdio.h>    

int main(int argc,char *argv[]) {
    int fd,n,i;
    char buf[256];
  if(argc!=2)
  {
	  write(2,"Error",5);
  }  
    fd = open(argv[1], O_RDONLY);
    while ((n=read(fd,buf, sizeof(buf))) > 0) {
       for(i=0;i<n;i++)
       {
	       write(1,&buf[i],1);
	       
       }
       getchar();
    }

    close(fd);
    return 0;
}
/*
----------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------

Output:
./a.out a.c
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc > 1) {
        printf("Hello %s! This is a.out running.\n", argv[1]);
    } else {
        printf("Hello! No name given.\n");
    }
    return 0;
}

----------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------
*/

