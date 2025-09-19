#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int fd, fd2 = 100;  

    if (argc != 2) {
        write(2, "Usage: ./a.out <filename>\n", 27);
        exit(1);
    }

    fd = open(argv[1], O_WRONLY | O_CREAT | O_APPEND, 0644);

    dup2(fd, fd2); 

    write(fd, "Hello from fd\n", 14);
    write(fd2, "Hello from fd2\n", 15);

    close(fd);
    close(fd2);
    return 0;
}

