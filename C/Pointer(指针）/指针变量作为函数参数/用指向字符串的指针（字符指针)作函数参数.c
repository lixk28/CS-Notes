// 下面编写出几个函数，来实现几个常用的字符串处理函数 
// ^_^ Y

#include<stdio.h>
#include<string.h>
char *string_copy(char *p1,char *p2); // 这些函数完全可以用字符数组名作形参，原理是一样的 
int string_length(char *p);
char *string_catenate(char *p1,char *p2);
int string_compare(char *p1,char *p2);

int main()
{ 
	char str1[100],str2[50],str3[100],str4[50],str5[100],str6[50],str7[100],str8[50];
	printf("Please input two strings:\n");
	printf("str1=");
	gets(str1);
	printf("str2=");
	gets(str2);
	strcpy(str3,str1);
	strcpy(str4,str2);
	strcpy(str5,str1);
	strcpy(str6,str2);
	strcpy(str7,str1);
	strcpy(str8,str2);
	
	printf("strlen(str1)=%d\n",strlen(str1));
	printf("strlen(str2)=%d\n",strlen(str2));
	printf("string_length(str1)=%d\n",string_length(str1));
	printf("string_length(str2)=%d\n\n",string_length(str2));
	
	printf("string_compare(str1,str2)=%d\n",string_compare(str1,str2));
	printf("strcmp(str1,str2)=%d\n\n",strcmp(str1,str2));

	printf("strcat=%s\n",strcat(str3,str4)); 
	printf("string_catenate(str1,str2)=%s\n\n",string_catenate(str5,str6));
	
	printf("strcpy(str1,str2)=%s\n",strcpy(str7,str8));
	printf("string_copy(str1,str2)=%s\n\n",string_copy(str7,str8));

	return 0;
}

char *string_copy(char *p1,char *p2)
{
	int i;
	for(i=0;*(p2+i)!='\0';i++)
	*(p1+i)=*(p2+i);
	*(p1+i)='\0';
	return p1;
}

int string_length(char *p)
{
	int length=0,i;
	for(i=0;*(p+i)!='\0';i++)
	length++;
	return length;
}

char *string_catenate(char *p1,char *p2)
{
	int i,j,k,flag;
	for(i=0;;i++)
	if(*(p1+i) == '\0')
	{
		flag=i;
		break;
	}
	for(j=0,k=flag;*(p2+j)!='\0';j++,k++)
	*(p1+k)=*(p2+j);
	*(p1+k)='\0';
	return p1;
}

int string_compare(char *p1,char *p2)
{
	int i;
	for(i=0;;i++)
	{
		if(*(p1+i) > *(p2+i))
		return 1;
		else if(*(p1+i) < *(p2+i))
		return -1;
		else if(*(p1+i)=='\0' && *(p2+i)=='\0') // 1 
		return 0;
		else if(*(p1+i) == *(p2+i)) //2
		continue;
		//注意：上面两处的else if不能调换位置 
	}
}
