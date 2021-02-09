#include<stdio.h>

int main()
{
	int a=121;
	printf("%c\n",a);
	
	int b=377;
	printf("%c",b);
		
	return 0;
}
/*  a,b以字符形式输出的结果相同都为 Y
  这是因为 b过大超过了ASCII码0-127的范围
  计算机只把 b最后一个字节的信息义字符形式输出
  a 在计算机中存储的原码 01111001
  b 在计算机中存储的原码 00000001 01111001 
*/
