#include<stdio.h>

int main()
{
	FILE *fp;
	fp=fopen("C:\\Users\\Lenovo\\Desktop\\Note\\file(�ļ�)\\test_file\\testfile for a+.dat","a+");
	// testfile for a+.dat �ļ�ԭ���ݣ�I am Groot 
	
	rewind(fp); // �����ܸı�д����ʼλ�ã�����ֻ�����ļ�β׷�� 
	fputs("HelloWorld",fp);
	fseek(fp,10,0);
	fputs("abcd",fp);
	
	fclose(fp); //����������ȫ��ִ�У����������! 
	 
	/* �����ļ� */ 
	fp=fopen("C:\\Users\\Lenovo\\Desktop\\Note\\file(�ļ�)\\test_file\\testfile for a+.dat","w");  
	fputs("I am Groot",fp);
	fclose(fp);
	
	return 0;
}
