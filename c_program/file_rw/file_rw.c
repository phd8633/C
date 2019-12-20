#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char char_buf[1000] ;int len_buf;
    FILE *file_input = fopen("input.txt","r");
    int ret = fread(char_buf,1,1000,file_input);
    len_buf = strlen(char_buf);
    FILE *file_output = fopen("output.txt","w");
    printf("lenth :%d \n%s\n",len_buf,char_buf);
    fwrite(char_buf,1,1000,file_output);
    
    fclose(file_input);
    fclose(file_output);
    return 0;
}