#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define BUF_SIZE 100

int main()
{
    char buf[BUF_SIZE];
    int fd = open("data.txt",O_RDONLY);
    int sz;
    if(fd == -1)
		printf("error() open\n");
    printf("file descriptor: %d\n",fd);

    if((sz=read(fd,buf,sizeof(buf)))==-1)
		printf("error() read\n");
    
    int fd1 = open("data1.txt",O_CREAT|O_WRONLY);
    if(fd1 == -1)
		printf("error open!");
    
    if(write(fd1,buf,sz)==-1)
		printf("error write!\n");
    close(fd);
    close(fd1);
}
