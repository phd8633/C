#include "stdio.h"
#include "hello.h"
 
int main()
{
    int a = 1;
    int b = 2;
    printf("a=%d b=%d",a,b);
    chg(&a,&b);
    printf("a=%d b=%d",a,b);
    printf("c=%d",c);
}