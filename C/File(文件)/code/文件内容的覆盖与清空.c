#include<stdio.h>

int main()
{
	FILE *fp;
	fp=fopen("C:\\Users\\Lenovo\\Desktop\\Note\\file(文件)\\test_file\\file10.dat","a+");
//	fputs("wqdqwdqwqwfwqhfihqwiofwiqfiowqoe",fp);
//	rewind(fp);
	fputs("IamGroot",fp);
//	fclose(fp);
	char str[100]={'\0'};
	fgets(str,11,fp);
	puts(str);
	
	rewind(fp);// meiyong!!!
	fputs("IamGroot",fp);
	
	
//	char str[100]={'\0'};
//	fp=fopen("C:\\Users\\Lenovo\\Desktop\\Note\\file(文件)\\test_file\\file10.dat","r+");
//	fgets(str,11,fp);
//	puts(str);
//	fclose(fp);
//	
	return 0;
}
