#include "stdio.h"
#include "string.h"
#include "unistd.h"
#include "fcntl.h"

#define PATH "./namepipe"

int main()
{
    int fd = open(PATH,O_WRONLY);
    if (fd<0)
    {
        printf("W:open namepipe error!\n");
        return 0;
    }
    char str[100];
    while(1)
    {
       printf("write:");
       scanf("%s",str);
       if(!write(fd,str,strlen(str)) )
            {printf("write error !\n");break;}
       write(fd,'\0',1);
        sleep(1);
    }    
    close(fd);    
}
