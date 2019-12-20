#include "stdio.h"
#include "unistd.h"
#include "pthread.h"

void * StartPthread1();
void * StartPthread2();



int main()
{
    pthread_t tid;
    int arg =10;
    pthread_create(&tid,NULL,StartPthread1,NULL);
    printf("I am main:%ld\n\n",tid);
   
    sleep(2);
    pthread_join(tid,NULL);
    printf("main stop\n");
}

void *StartPthread2 ()
{
    printf("I am pthread2\n");  
   // pthread_cancel(tid);  
   // printf("pthread1 canceled!\n");
}


void *StartPthread1 ()
{
    printf("I am pthread1:%ld\npthread1 calling pthread2 then sleeping\n",pthread_self());   
    pthread_t tid2;
    pthread_create(&tid2,NULL,StartPthread2,NULL);
    sleep(1);
    printf("pthread1 wakeup ok!\n");

}
