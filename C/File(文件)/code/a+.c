#include<stdio.h>

int main()
{
	FILE *fp;
	fp=fopen("C:\\Users\\Lenovo\\Desktop\\Note\\file(文件)\\test_file\\testfile for a+.dat","a+");
	// testfile for a+.dat 文件原内容：I am Groot 
	
	rewind(fp); // 并不能改变写的起始位置，还是只能在文件尾追加 
	fputs("HelloWorld",fp);
	fseek(fp,10,0);
	fputs("abcd",fp);
	
	fclose(fp); //缓冲区内容全部执行，保存好数据! 
	 
	/* 重置文件 */ 
	fp=fopen("C:\\Users\\Lenovo\\Desktop\\Note\\file(文件)\\test_file\\testfile for a+.dat","w");  
	fputs("I am Groot",fp);
	fclose(fp);
	
	return 0;
}
