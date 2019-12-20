/*************************************************************************
  > File Name: pipe.c
  > Author: phd
  > Mail: panhd@neusoft.com 
  > Created Time: Thu 05 Dec 2019 11:12:13 PM PST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include <string.h>

int main()
{
printf("hello\n");    
int a = 1;

int fd[2];
if(pipe(fd))
    perror("create pipe error!\n");
else 
    perror("create pipe ok!");



    pid_t  pid = fork();
    pid = fork();
    if(0==pid)
    {
        char buf[]="message from child: hello!\n";
        write(fd[1],buf,strlen(buf));        



        printf("%d",a);
        printf("child\n");
        
    }
    if(-1==pid)
    {
        perror("create child process error!\n");

    }

    if(0<pid)
    {
        char buf[100];
        printf("read:%zd %s",read(fd[0],buf,sizeof(buf)),buf);

        
        printf("%d",a);
        printf("parent\n");
    }

}
