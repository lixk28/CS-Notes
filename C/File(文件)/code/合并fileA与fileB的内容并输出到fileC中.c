#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *fp1,*fp2;
	
	if( (fp1=fopen("C:\\Users\\Lenovo\\Desktop\\Note\\file(�ļ�)\\test_file\\fileA.txt","r")) == NULL)
	{
		printf("Cannot open fileA!\n");
		exit(0);
	}
	fseek(fp1,0L,SEEK_END);
	long flenA=ftell(fp1); //��ȡ�ļ��ĳ��� 
	char tempA[flenA+1];
	rewind(fp1); //ע��ǰ���Ѿ���fseek���ļ���дָ�붨λ���ļ�β�� 
	fgets(tempA,flenA+1,fp1);
	fclose(fp1);
	
	if( (fp1=fopen("C:\\Users\\Lenovo\\Desktop\\Note\\file(�ļ�)\\test_file\\fileB.txt","r")) == NULL)
	{
		printf("Cannot open fileB!\n");
		exit(0);
	}
	fseek(fp1,0L,SEEK_END);
	long flenB=ftell(fp1);
	char tempB[flenB+1];
	rewind(fp1);
	fgets(tempB,flenB+1,fp1);
	fclose(fp1);
	
	if( (fp2=fopen("C:\\Users\\Lenovo\\Desktop\\Note\\file(�ļ�)\\test_file\\fileC.txt","w")) == NULL)
	{
		printf("Cannot open fileC!\n");
		exit(0);
	}
	fputs(tempA,fp2);
	fputs(tempB,fp2);
	fclose(fp2);
		
	return 0;
}
