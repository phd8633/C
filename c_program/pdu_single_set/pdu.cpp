// PDU_date_generate.cpp : Defines the entry point for the console application.
//

#include "string.h"
#include "stdio.h"
#include "stdlib.h"

char msgid_store[1000][9]={"00000000"};
char write_msgid_txt[1000][12]={"00 00 00 00"};
char write_payload_txt[1000][24]={"00 00 00 00 00 00 00 00"};

const char length[]=" 00 00 00 08 ";
int signal_len,start_bit;
long long int msg_value;


char msg_id[9] = "00000000";
int id_len = 0;
char msg_id_temp[9]={'0'};
int id_len_temp = 0;

long long int value_store[1000][16]={0};
long long int value[16]={0};
char char_value[16]={'0'};  //payload without formate
char write_value[24]={' '};  // payload with formate
int value_top = 0;
int z = 0;
const char chrlen[14]=" 00 00 00 08 ";

int make_txt_falg = 0;
int make_txt()
{
	FILE * file = fopen("output.txt","a");
	char x = '\n';
	for(int j=0;j<=z;j++)
	{
		for(int i=0;i<12;i++)
			printf("%c",write_msgid_txt[j][i]);
		fwrite(write_msgid_txt[j],1,12,file);
		printf(" 00 00 00 08 ");
		fwrite(&chrlen,1,13,file);
		for(int i=0;i<24;i++)	
			printf("%c",write_payload_txt[j][i]);
		fwrite(write_payload_txt[j],1,24,file);		
	//	fwrite(&x,1,1,file);
	}
	fwrite(&x,1,1,file);
	fclose(file);
	make_txt_falg = 1;
	return 0;
}
long long int push(long long int x)
{
	value[value_top++] = x%16;	
	return x/16;
}
char pop(int i)  //转化过程，int to char ；不想在这一步打印就去掉 printf();
{
	switch (i%16){
	case 0: return '0';
	case 1: return '1';
	case 2: return '2';
	case 3: return '3';
	case 4: return '4';
	case 5: return '5';
	case 6: return '6';
	case 7: return '7';
	case 8: return '8';
	case 9: return '9';
	case 10: return 'A';
	case 11: return 'B';
	case 12: return 'C';
	case 13: return 'D';
	case 14: return 'E';
	case 15: return 'F';
	default : return '0';
	}
}


int change_value()  //将value转化成对应的十六进制数据；并存放在char_value[16]中
{
	while(value_top)
	{
		value_top--;
		
		char_value[15-value_top] = pop(value[value_top]);		
	}
	return 0;
}

int make_payload()////////////////////////   不带格式的char_value[16]转化成带格式(payload)的write_value[24] ；需要把它放在 write_payload_txt[1000][24]中再调用fwrite()
{
	int x = 0;
	for(int i=0;i<24;i++)
	{
		
		if(i==23)
			write_value[i] = '\n';
		else if(i%3==2)
			write_value[i] = ' ';	
		else
			write_value[i]=char_value[x++];	
	//	printf("%c",char_value[x-1]);
	}
	return 0;
}

int msgid_in_store(char *msg_id)  //判断新输入的msg_id是否在store中；
{
	char str[9]="00000000";
	int x = 0;
	for(int i=0;i<10;i++)  //判断新输入的msg_id是否在store中；
	{
		if(!strcmp(msgid_store[i],msg_id)) //in
		{
			printf("Already msg_id,store in msgid_store[%d]\n",i);
			return i;
		}
		else
			if(!strcmp(msgid_store[i],str)) // not in;write 
			{	
				for(int m=0;m<9;m++)      // write msgid_store
					msgid_store[i][m] = msg_id[m];
				for(int j=0;j<12;j++)  // write write_msgid_txt
				{
					if(j%3==2)
						write_msgid_txt[i][j]=' ';
					else
					{
						write_msgid_txt[i][j] = msg_id[x++];		
					
					}
				}	
				printf("\nNEW msg_id ,store in msgid_store[%d] \n",i);
				return i;
			}
	}
	return 0;
}


int main_payload()
{
	char c ;
	printf("Formate:(msg_id signal_bit start_bit msg_value)\n");
//////////////////////////////////////////////////msg_id set
	msg_id_temp[0]='0';
	while(1)
	{
		
		c= getchar();
		if(c=='q')
		{
			make_txt();
			return 0;
		}
		if(c==' '&&msg_id_temp[0]!='0')			
			break;
		else if(c!='\n')
			if(c!=' ')
				msg_id_temp[id_len_temp++] = c;
	}
	
	for(int i = 0;i<9;i++)
	{
		if(i<=7-id_len_temp)
			msg_id[i] = '0';
		if(i==8)
			msg_id[i]='\0';
		if(i>7-id_len_temp&&i!=8)
			msg_id[i] = msg_id_temp[id_len++];
	}
	
	id_len_temp = id_len = 0;
///////////////////////////////////////////////////       msg_id   (char []) set ok
	scanf("%d %d %d", &signal_len,&start_bit,&msg_value);//signal_bit start_bit msg_value  (int) set ok;	
//检验跨字节
	if( (signal_len+start_bit) > ( (start_bit/4 +1)*4 -1) )
	{
		switch (start_bit%4)
		{
			case 0:	break;
			case 1: msg_value*=2;break;
			case 2: msg_value*=4;break;
			case 3:	msg_value*=8;break;
		}
	}

//数据溢出检验（>2^signal_bit）
	long long int check_signal_bit=1;    
	if (signal_len>=59)
		check_signal_bit=9223372036854775807;
	else
		for(int temp=signal_len;temp>0;temp--)
			check_signal_bit*=2;
	if(check_signal_bit<msg_value)
		printf("Warning:msg_value more than 2^signal_bit");

	check_signal_bit=1;
	if (signal_len>=59)
		check_signal_bit=9223372036854775807;
	else
		for(int temp=(signal_len/4 +1)*4;temp>0;temp--)
			check_signal_bit*=2;
	if(check_signal_bit<msg_value)
		printf(",abandon high bit value!!!");

//判断是否新msg_id
	z=msgid_in_store(msg_id);


	for(int ii=0;ii<16;ii++)   // write value_store,value(int[16])  need  convert to char[]
	{ 	
		
		if(ii>=start_bit/4&&ii<=(start_bit+signal_len)/4)//特定位写数据
		{
			
			if(msg_value%16+value_store[z][ii]>=16)   //数据溢出检验(>16)
			{
				printf("\nError!!! data overflow, Already data:\n");				
				
				for(int i=0;i<12;i++)
					printf("%c",write_msgid_txt[z][i]);
				printf(" 00 00 00 08 ");
				for(int i=0;i<24;i++)	
					printf("%c",write_payload_txt[z][i]);

				printf("input new msg_value(able less than 0)\n");
				scanf("%d",&msg_value);
				
			}			
			msg_value= push(msg_value+value_store[z][ii]);			
		}
		else
		{
			push(value_store[z][ii]);
		}
	}

	for(int ii=0;ii<16;ii++)	
		value_store[z][ii]=value[ii];	
	change_value();
	make_payload(); 	
	for(int j=0;j<24;j++)// write write_payload_txt[i][j] ; need write to output.txt while end;
	{
		//printf("%c",write_value[j]);
		write_payload_txt[z][j] = write_value[j];
	}
	return 0;
}

int main_list_payload()
{
	for(int i=0;i<12;i++)
		printf("%c",write_msgid_txt[z][i]);
	printf(" 00 00 00 08 ");
	for(int i=0;i<24;i++)
		printf("%c",write_payload_txt[z][i]);
	printf("\n");
	return 0;
}
 

int main()
{
	printf("\n\n******Opreation*********Instruction*****************:\nInput Formate:(Msg_id Signal_bit Start_bit Msg_value)\nInput 'q' to quit and generate output.txt\nThe new 16 Byte data will be add to output.txt\n\n");
	for(int i =0;i<1000;i++)
		for(int j = 0;j<9;j++)
		{
			if(j==8)
			msgid_store[i][j]='\0';
			else
			msgid_store[i][j]='0';
		}
	while(1)
	{	
		main_payload();			
		if(make_txt_falg == 1)
			break;	
		main_list_payload();
	}

	return 0;
}
