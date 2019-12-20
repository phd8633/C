#include "common.h"

static int CommMsgQueue(int cmd)
{
    key_t key = ftok("./MsgQueue",0x6666);
    if ( -1 == key)
        perror("ftok");
    int msg_id = msgget(key,cmd);
    if (-1 == msg_id)
        perror("msgget");
    return msg_id;
}

int CreatMsgQueue()
{
    return CommMsgQueue(IPC_CREAT|IPC_EXCL|0666);
}
int GetMsgQueue()
{
    return CommMsgQueue(IPC_CREAT);
}
int DestoryMsgQueue(int msgid)
{
    int ret = msgctl(msgid,IPC_RMID,NULL);
    if (ret<0)
    {
        perror("Destory");
        return -1;
    }
    return 0;
}
int SendMsgQueue(int msgid,int who,char * msg)
{
    msgbuf_s buf;
    buf.mtype = who;
    strcpy(buf.mtext,msg);

    if(msgsnd(msgid,&buf,sizeof(buf.mtext),0)<0)
    {
         perror("msgsnd");
         return -1;
    }   
    return 0;   

}
int RecvMsgQueue(int msgid, int msgtype, char out[])
{
    msgbuf_s buf;
    if(msgrcv(msgid,&buf,sizeof(buf.mtext),msgtype,0)<0)
        perror("Recv");
    strncpy(out,buf.mtext,sizeof(buf.mtext));
    
    return 0;
}