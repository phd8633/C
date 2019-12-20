#include "stdio.h"
#include "string.h"
#include "stdlib.h"

char msg_id[8]="00000000";
char msg_len[8]="00000008";
char payload[16]="0000000000000000";
char payload_1[16]="0000000000000000";
static char str[8];
int main()
{
    int count = 1;int count_2 = 1;
    int i = 1;int j=0;int len;int x = 7;char c ;
    int signal_length,start_bit;
while(1){ 
        for(j=0;j<8;j++)
        {    str[j]=msg_id[j]=msg_len[j]='0';}
        for(j=0;j<16;j++) 
        {    payload[j]=payload_1[j]='0';}
        j=0;x = 7;i =1;count = 1;count_2=1;msg_len[7] = '8'; str[5] = '0';

        printf("\nInput Format----messageID,signal_length,start_bit:\n");
        while(1)    //read msg_id
        {
            scanf("%c",&c);
            if(c!=','&&c!='\n')
                str[j++] = c; 
            if(c == ',')
                break;         
        }    
        len = j-1;
        j=0;
        for(len;len>=0;len--)       //set msg_id
        {
        msg_id[x] = str[len];
            x--;
        }
       
        scanf("%d,%d",&signal_length,&start_bit);  //read signal_length,start_bit

        

        for(i= 1;i<=signal_length;i++)   //count functions
            count*=2;

        if(start_bit%4 == 0)           //set function's payload
        { 
            for(i = 0;i<count;i++)
            {   
                switch (i)
                {
                    case 0:payload_1[i] = '0';break;  
                    case 1:payload_1[i] = '1';break;  
                    case 2:payload_1[i] = '2';break;  
                    case 3:payload_1[i] = '3';break;    
                    case 4:payload_1[i] = '4';break;  
                    case 5:payload_1[i] = '5';break;  
                    case 6:payload_1[i] = '6';break;  
                    case 7:payload_1[i] = '7';break;  
                    case 8:payload_1[i] = '8';break;  
                    case 9:payload_1[i] = '9';break;  
                    case 10:payload_1[i] = 'A';break;  
                    case 11:payload_1[i] = 'B';break;  
                    case 12:payload_1[i] = 'C';break;  
                    case 13:payload_1[i] = 'D';break;  
                    case 14:payload_1[i] = 'E';break;  
                    case 15:payload_1[i] = 'F';break;      
                    default:      break; 
                }
            }
        }
        else if(start_bit%4 == 1)
        {
            for(i = 0;i<count;i++)
            {   
                switch (i)
                {
                    case 0:payload_1[i] = '0';break;  
                    case 1:payload_1[i] = '2';break;  
                    case 2:payload_1[i] = '4';break;  
                    case 3:payload_1[i] = '6';break;    
                    case 4:payload_1[i] = '8';break;  
                    case 5:payload_1[i] = 'A';break;  
                    case 6:payload_1[i] = 'C';break;  
                    case 7:payload_1[i] = 'E';break;  
        
                    default:      break; 
                }
            }
        }
        else if(start_bit%4 == 2)
        {
            for(i = 0;i<count;i++)
            {   
                switch (i)
                {
                    case 0:payload_1[i] = '0';break;  
                    case 1:payload_1[i] = '4';break;  
                    case 2:payload_1[i] = '8';break;  
                    case 3:payload_1[i] = 'C';break;
                    default:      break; 
                }
            }        
        }
        else if(start_bit%4 == 3)
        {
            for(i = 0;i<count;i++)
            {   
                switch (i)
                {
                    case 0:payload_1[i] = '0';break;  
                    case 1:payload_1[i] = '8';break;  
                    default:      break; 
                }
            }
        }
        i = 0;
        
        while(i<count)
        {
            int start = start_bit/4;
            if(start%2==0)   
                payload[start+1] = payload_1[i];
            else
                payload[start-1] = payload_1[i];
            switch (i)
            {
                case 0:printf("Function    0 ----> "); break;
                case 1:printf("Function    1 ----> "); break;
                case 2:printf("Function   10 ----> "); break;
                case 3:printf("Function   11 ----> "); break;
                case 4:printf("Function  100 ----> "); break;
                case 5:printf("Function  101 ----> "); break;
                case 6:printf("Function  110 ----> "); break;
                case 7:printf("Function  111 ----> "); break;
                case 8:printf("Function 1000 ----> "); break;
                case 9:printf("Function 1001 ----> "); break;
                case 10:printf("Function 1010 ----> "); break;
                case 11:printf("Function 1011 ----> "); break;
                case 12:printf("Function 1100 ----> "); break;
                case 13:printf("Function 1101 ----> "); break;
                case 14:printf("Function 1110 ----> "); break;
                case 15:printf("Function 1111 ----> "); break;

                default:break;
            }

            for(j = 0;j<8;j++)
            {
                printf("%c",msg_id[j]);                
                if(j%2==1)
                    printf(" ");
            }
            for(j = 0;j<8;j++)
            {
                printf("%c",msg_len[j]);               
                if(j%2==1)
                    printf(" ");
            }
            for(j = 0;j<16;j++)
            {
                printf("%c",payload[j]);                
                if(j%2==1)
                    printf(" ");
            }
            payload[start] = '0';
            i++;
            printf("\n");
        }

    }return 0;
        
}
