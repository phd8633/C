#include "stdio.h"
#include "fcntl.h"
#include "unistd.h"
#include "string.h"
#include <sys/mman.h>

#define PATH "./mymap"


typedef struct Mmap{
    int size;
    char str[100];
}Mmap_s;

int main()
{
    int fd = open(PATH,O_RDONLY,0664);
    if(-1 == fd)
        printf("W:open error\n");
    Mmap_s * DataAddr;
    DataAddr = mmap(NULL,sizeof(Mmap_s),PROT_READ,MAP_SHARED,fd,0);
    if (MAP_FAILED == DataAddr)
        printf("W:map error!\n");
    close(fd);
    printf("size:%d,str:%s\n",DataAddr->size,DataAddr->str);
    munmap(DataAddr,sizeof(Mmap_s));
    return 0;
}
