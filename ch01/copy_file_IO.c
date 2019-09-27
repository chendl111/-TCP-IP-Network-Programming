#include <stdio.h>
#define BUF_SIZE 100

int main()
{
	FILE *fd,*fd1;
	char buf[BUF_SIZE];
	if((fd = fopen("data.txt","r"))==NULL)
		printf("open1 error!\n");

	int sz = fread(buf,1,sizeof(buf),fd);

	if((fd1 = fopen("data2.txt","w+"))==NULL)
		printf("open2 error!\n");

	fwrite(buf,1,sz,fd1);

	fclose(fd);
	fclose(fd1);
	return 0;
}
