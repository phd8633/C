#include "stdio.h"
#include "string.h"
#include "unistd.h"
#include  "fcntl.h"

#define PATH "./namepipe"
#define MOD  (644)


int main()
{
    int fd = open(PATH,O_RDONLY);
    if (fd <0)
    {
        printf("R:open namepipe error!\n");
        return 0;
    }
    char str[100];
    while(1)
    {
       int size = read(fd,str,sizeof(str));
       if(size==-1)
            break;
        printf("read%d:%s\n",size,str);        
        sleep(1);
    }
   close(fd); 
}
