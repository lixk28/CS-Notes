// C�����������ַ��������÷�ʽ
// <1> ͨ���ַ�����
// <2> ͨ��ָ�� 

#include<stdio.h>
#include<stdlib.h>

int main()
{
	// �����ַ�ָ�������char *p 
	// <1> �����ڶ�����ַ�ָ�������ͬʱ�����ʼ�� 
    char *str1="I am Groot"; 
	
	// <2> Ҳ���Զ���֮���ٳ�ʼ�� 
	char *str2;
	str2="I am Groot"; // ��Ҫд�� *str2="I am Groot" 
	
	//*** ���ַ�ָ�������ʼ����ʵ�����ǰ��ַ�����Ԫ�صĵ�ַ����ָ�������ʹ��ָ���ַ����ĵ�һ���ַ� 
	
	// ���Զ��ַ�ָ������ٸ�ֵ
	str1="Hello World";
	char str3[15]="I am Groot";
	str2=str3;
	printf("str1=%s\n",str1);
	printf("str2=%s\n",str2);
	printf("str3=%s\n",str3);
	
	//��������һ���ַ����������׵�ַ�����ַ�ָ�����
    //<1> ������scanf���� ��������ַ����ﲻ�ܰ����ո���Ϊ�ո����ַ����ָ���־ 
    //<2> Ҳ������gets���� ��ʱ�ո�Ҳ�ᱻ�����ַ����У�ֱ�����뻻�з�
    //ע��!!!����Ҫ������ malloc���� �����ַ�ָ���������һ���ڴ�ռ� 
    
    //Ҳ����ͨ���ַ�ָ������������ָ����ַ��� 
    //<1> ������printf��� 
	//<2> Ҳ������puts��� 
	// ����д�ַ�ָ�����������Ҫ��* 
    char *str4;
    unsigned int num1;
    printf("Please input the length of str4 you need:\n");
    scanf("%u",&num1);
    str4=(char *)malloc(num1*sizeof(char));
    printf("Please input str4:\n"); 
    scanf("%s",str4); 
	printf("str4=%s\n",str4); 
	//ϵͳ�����string��ָ����ַ����ĵ�һ���ַ���Ȼ���Զ�ʹ���1��ָ����һ���ַ�
	//ֱ������'\0'Ϊֹ��ע�����ڴ��У��ַ���������Զ���'\0'                         
	free(str4);
    
    char *str5;
    unsigned int num2;
    printf("Please input the length of str5 you need:\n");
    scanf("%u",&num2);
    str5=(char *)malloc(num2*sizeof(char));
    getchar();
    printf("Please input str5:\n"); 
	gets(str5);
    printf("str5=%s\n",str5);
    free(str5);
	 
	// ����ͨ��ָ������ַ�����ͨ���ı�ָ�������ֵ��ʹ��ָ���ַ����еĲ�ͬ�ַ�
	int num3;
	printf("Please input the length of str6 you want:\n");
	scanf("%d",&num3);
	getchar();
	char str6[num3+1];
	printf("Please input str6:\n");
	gets(str6);
	int i;
	char *p=str6;
	printf("str6=");
	for(i=0;*(p+i)!='\0';i++) // ͨ���ı�ָ�������ֵ��������ַ������ַ� 
	printf("%c",*(p+i));
	 
	return 0;
}
