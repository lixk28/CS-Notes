/* �ַ����ȽϺ��� strcmp (STRing CoMPare) */

// һ����ʽΪ strcmp(�ַ���1,�ַ���2)
#include<stdio.h>
#include<string.h> 

int main()
{ 
  /***** �ַ����ıȽϹ��� *****/
  // �������ַ�������������ַ���ȣ���ASCII��ֵ�Ĵ�С�Ƚϣ�ֱ�����ֲ�ͬ���ַ������� '\0'Ϊֹ 
  // (1) ��ȫ���ַ��������ͬ������Ϊ�����ַ������
  // (2) �����ֲ���ͬ���ַ������Ե�һ�Բ���ͬ���ַ��ıȽϽ��Ϊ׼
  
  /***** �ȽϵĽ���ɺ���ֵ���أ�strcmp�����з���ֵ *****/ 
  // (1) ��� �ַ���1 = �ַ���2������ֵΪ 0
  // (2) ��� �ַ���1 > �ַ���2������ֵΪһ��������(һ����1)
  // (3) ��� �ַ���1 < �ַ���2������ֵΪһ��������(һ����-1) 
  
  //Example�� 
  char str8[]={"computer"},str9[]={"compare"};
  int return_value1,return_value2,return_value3;
  
  return_value1=strcmp(str8,str9);
  return_value2=strcmp("A","a");
  return_value3=strcmp("DOG","cat");
  
  printf("return_value1=%d\n",return_value1);
  printf("return_value2=%d\n",return_value2);
  printf("return_value3=%d\n",return_value3);
  
  getchar(); // Press a key to continue the next part
  printf("Please input two strings:\n");
  char str10[100],str11[100];
  gets(str10);
  gets(str11);
  if(strcmp(str10,str11) == 0)
  printf("str1 = str2");
  else if(strcmp(str10,str11) > 0)
  printf("str1 > str2");
  else if(strcmp(str10,str11) < 0)
  printf("str1 < str2");
  
  // Сд��ĸ�ȴ�д��ĸ�󣡣��� ��ΪASCII��ֵ��        
   
	return 0;
} 
