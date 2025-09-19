#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc,char *argv[])
{
	if(argc!=2)
	{
		write(2,"Error",5);
	}
	int fd,fd_dup;
	fd=open(argv[1],O_WRONLY|O_CREAT|O_APPEND,0644);
	fd_dup=dup(fd);

	write(fd,"Hello from fd\n",14);
	write(fd_dup,"Hello from fd_dup",18);

	close(fd);
	close(fd_dup);
	return 0;


}
