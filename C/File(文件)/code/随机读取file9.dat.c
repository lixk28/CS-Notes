#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	FILE *fp;
	if( (fp=fopen("C:\\Users\\Lenovo\\Desktop\\Note\\file(�ļ�)\\test_file\\file9.dat","r+")) == NULL)
	{
		printf("Cannot open this file!\n");
		exit(0);
	}
	
	char str[100]={'\0'};
	printf("Please input a string:\n");
	gets(str);
	fputs(str,fp);
	
	fseek(fp,-strlen(str),2); //ע���� -strlen(str) 
	// Ҳ����д�� fseek(fp,0,0) 
	
	printf("Please input an integer between 0 and %d:\n",strlen(str));
	int n;
	scanf("%d",&n);
	fseek(fp,n-1,0);
	printf("The %dth character is: %c\n",n,fgetc(fp));
	
	long cur;
	cur=ftell(fp); //ע��ִ���� fgetc ���ļ�λ��ָ�����һλ 
	printf("The current position of file is: %ld\n",cur+1);
	
	long flen;
	fseek(fp,0,2);
	flen=ftell(fp);
	printf("The size of this file is: %ldbytes\n",flen); // �õ��ļ����ȣ����ֽ�����
	
////	char *temp=(char *)malloc(sizeof(char)*flen+1);
//	char temp[flen+2]={'\0'};
//	fread(temp,flen,1,fp);
	
	fclose(fp);
		
	return 0;
}
