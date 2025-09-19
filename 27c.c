/*
----------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------

Name 27c.c 
Author :CHAVALA LAKSHMI VISHNU
Description:
Write a program to execute ls -Rl by the following system calls
a. execl
b. execlp
c. execle
d. execv
e. execvp




Date:7 Sept,2025


----------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------
*/



#include <stdio.h>
#include <unistd.h>

int main() {
    char *envp[] = { "PATH=/bin", NULL }; 

    printf("Using execle:\n");
    execle("/bin/ls", "ls", "-Rl", NULL, envp);
    return 1;
}
/*
----------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------

Output:
Using execle:
.:
total 396
-rw-rw-r-- 1 vishnu vishnu     0 Sep  7 17:33 1.c
-rwxrwxr-x 1 vishnu vishnu  1380 Sep  7 17:33 1.sh
-rw-rw-r-- 1 vishnu vishnu  1885 Sep  7 17:59 10.c
-rw-rw-r-- 1 vishnu vishnu  1745 Sep  7 18:01 11.c
-rw-rw-r-- 1 vishnu vishnu   331 Sep  6 12:27 11a.c
-rw-rw-r-- 1 vishnu vishnu   448 Sep  6 14:27 11b.c
-rw-r--r-- 1 vishnu vishnu    33 Sep  6 12:32 11examp.txt
-rw-rw-r-- 1 vishnu vishnu  1765 Sep  7 18:05 12.c
-rw-rw-r-- 1 vishnu vishnu  1951 Sep  7 18:06 13.c
-rw-rw-r-- 1 vishnu vishnu  2095 Sep  7 18:10 14.c
-rw-rw-r-- 1 vishnu vishnu  4853 Sep  7 18:12 15.c
-rw-rw-r-- 1 vishnu vishnu  1925 Sep  7 18:15 16a.c
-rw-rw-r-- 1 vishnu vishnu  1919 Sep  7 18:16 16b.c
-rw-rw-r-- 1 vishnu vishnu  1909 Sep  7 18:19 17a.c
-rw-rw-r-- 1 vishnu vishnu  2369 Sep  7 18:21 17b.c
-rw-rw-r-- 1 vishnu vishnu  2906 Sep  7 18:22 18.c
-rw-r--r-- 1 vishnu vishnu    73 Sep  7 18:22 18exmp.txt
-rw-rw-r-- 1 vishnu vishnu  1833 Sep  7 18:25 19.c
-rw-rw-r-- 1 vishnu vishnu  1562 Sep  7 17:40 2.c
-rw-rw-r-- 1 vishnu vishnu  1395 Sep  7 18:27 20.c
-rw-rw-r-- 1 vishnu vishnu  1459 Sep  7 18:29 21.c
-rw-rw-r-- 1 vishnu vishnu  1761 Sep  7 18:31 22.c
-rw-rw-r-- 1 vishnu vishnu  1507 Sep  7 18:33 23.c
-rw-rw-r-- 1 vishnu vishnu  1403 Sep  7 18:37 24.c
-rw-rw-r-- 1 vishnu vishnu  1820 Sep  7 18:37 25.c
-rw-rw-r-- 1 vishnu vishnu  1448 Sep  7 18:40 26a.c
-rw-rw-r-- 1 vishnu vishnu  5319 Sep  7 18:43 27a.c
-rw-rw-r-- 1 vishnu vishnu  5307 Sep  7 18:45 27b.c
-rw-rw-r-- 1 vishnu vishnu   193 Sep  7 12:17 27c.c
-rw-rw-r-- 1 vishnu vishnu   171 Sep  7 12:18 27d.c
-rw-rw-r-- 1 vishnu vishnu   169 Sep  7 12:19 27e.c
-rw-rw-r-- 1 vishnu vishnu   239 Sep  7 15:40 28.c
-rw-rw-r-- 1 vishnu vishnu   821 Sep  7 15:45 29.c
-rw-rw-r-- 1 vishnu vishnu  1460 Sep  7 17:40 3.c
-rw-rw-r-- 1 vishnu vishnu   888 Sep  7 17:05 30.c
-rw-rw-r-- 1 vishnu vishnu  1423 Sep  7 17:43 4.c
-rw-rw-r-- 1 vishnu vishnu  1830 Sep  7 17:45 5.c
-rw-rw-r-- 1 vishnu vishnu  1836 Sep  7 17:47 6.c
-rw-rw-r-- 1 vishnu vishnu  1720 Sep  7 17:49 7.c
-rw-rw-r-- 1 vishnu vishnu  1883 Sep  7 17:53 8.c
-rw-rw-r-- 1 vishnu vishnu     0 Sep  7 17:53 9,c
-rw-rw-r-- 1 vishnu vishnu    30 Sep  7 17:57 9.c
-rw-rw-r-- 1 vishnu vishnu     0 Sep  7 17:53 9.v
-rw-rw-r-- 1 vishnu vishnu     0 Sep  1 14:21 My4txt.txt
-rw-r--r-- 1 vishnu vishnu    35 Sep  7 18:30 Output.txt
-rw-rw-r-- 1 vishnu vishnu   217 Sep  7 00:39 a.c
-rwxrwxr-x 1 vishnu vishnu 16056 Sep  7 18:46 a.out
-rwxrwxr-x 1 vishnu vishnu 16128 Sep  6 14:48 abc
-rwxrwxr-x 1 vishnu vishnu 16576 Sep  7 16:56 de
-rwxrwxr-x 1 vishnu vishnu 16080 Sep  6 12:28 dup
-rwxrwxr-x 1 vishnu vishnu 16304 Sep  6 17:01 ex
-rwxrwxr-x 1 vishnu vishnu 16000 Sep  7 18:39 exce
-rwxrwxr-x 1 vishnu vishnu 16120 Sep  1 14:52 exm
-rw-r--r-- 1 vishnu vishnu    32 Sep  6 14:49 exm11c.txt
-rw-r--r-- 1 vishnu vishnu    30 Sep  2 16:58 exmp
-rw-r--r-- 1 vishnu vishnu    29 Sep  6 14:28 exmp11b
---x-w---T 1 vishnu vishnu     0 Sep  6 15:11 exmp12
-rw-r--r-- 1 vishnu vishnu     0 Sep  7 17:48 exmp2
-rwxrwxr-x 1 vishnu vishnu    51 Sep  7 16:49 exp30.sh
-rwxrwxr-x 1 vishnu vishnu 16088 Aug 19 14:50 expfile
-rwxrwxr-x 1 vishnu vishnu 16128 Sep  6 14:28 exple11b
-rw-rw-r-- 1 vishnu vishnu     0 Sep  7 17:44 file1
-rw-rw-r-- 1 vishnu vishnu     0 Sep  7 17:44 file2
-rw-rw-r-- 1 vishnu vishnu     0 Sep  7 17:44 file3
-rw-rw-r-- 1 vishnu vishnu     0 Sep  7 17:38 file3rdqn.txt
-rw-rw-r-- 1 vishnu vishnu     0 Sep  7 17:44 file4
-rw-rw-r-- 1 vishnu vishnu     0 Sep  7 17:44 file5
-rw-rw-r-- 2 vishnu vishnu     7 Aug 18 14:36 hardlink.txt
-rwxrwxr-x 1 vishnu vishnu   122 Aug 18 15:34 inflopp.c
-rw-rw-r-- 1 vishnu vishnu     0 Sep  7 17:36 myfile.txt
-rw-rw-r-- 2 vishnu vishnu     7 Aug 18 14:36 original.txt
-rwxrwxr-x 1 vishnu vishnu 16000 Sep  7 11:55 par
-rwxrwxr-x 1 vishnu vishnu 16000 Sep  7 01:09 parent
lrwxrwxrwx 1 vishnu vishnu    12 Aug 18 14:26 softlink.txt -> original.txt
-rw-r--r-- 1 vishnu vishnu     4 Sep  7 18:20 ticket.txt
-rw-rw-r-- 1 vishnu vishnu    78 Aug 18 13:54 v.c

----------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------
*/
