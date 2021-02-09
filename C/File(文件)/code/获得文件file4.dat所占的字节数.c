#include<stdio.h>
#include<stdlib.h>

int main()
{
	long flen;
	FILE *fp;
	if( (fp=fopen("C:\\Users\\Lenovo\\Desktop\\Note\\file(文件)\\test_file\\file4.dat","r")) == NULL)
	{
		printf("Cannot open this file!\n");
		exit(0);
	}
	
	fseek(fp,0L,SEEK_END);
	flen=ftell(fp);
	printf("file4.dat uses %ld bytes.\n",flen); //注意文件中 \n 都被转换为 \r+\n 了 
	
	if(fclose(fp) != 0)
	{
		printf("Error in closing this file!\n");
		exit(0);
	}
	
	return 0;
} 
