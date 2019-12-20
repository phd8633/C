#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
int main() {
	pid_t id = fork();
	if (id < 0) {
		perror("子进程创建失败！");
	} else {
		if (id == 0) {
            sleep(3);
			printf("子进程工作:PID=%d,PPID=%d\n", getpid(), getppid());
            sleep(5);
		}else
		{
            
			printf("父进程工作:PID=%d,PPID=%d，子进程PID=%d\n", getpid(), getppid(),id);
			sleep(5);
		}
	}
}
