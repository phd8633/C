#include "stdio.h"
#include "string.h"
#include "unistd.h"

#define PATH "./namepipe"
#define MOD  (644)


int main()
{
    if(mkfifo(PATH,MOD))
        printf("create namepipe error!");
    else    
        printf("create namepipe ok!");    
}
