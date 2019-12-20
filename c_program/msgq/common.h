#ifndef _COMMON_H
#define _COMMON_H

#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include <sys/fcntl.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>

#define SERVER_TYPE 1;
#define CLIENT_TYPE 2;


typedef struct msgbuf{
    int mtype;
    char mtext[1024];
}msgbuf_s;

int CreatMsgQueue();
int GetMsgQueue();
int DestoryMsgQueue(int msgid);
int SendMsgQueue(int msgid,int who,char * msg);
int RecvMsgQueue(int msgid, int msgtype, char out[]);

#endif