//#include<stdio.h>
//
//int main()
//{
//	unsigned int a=1;  // �����unsignedȥ�� ����Ľ���ͻ���Yes ����ʵ����No 
//	int b=-1;
//	if(a>b)
//	  printf("Yes\n");
//	else if(a<b)
//	  printf("No\n");
//	
//	return 0;
//}
/*  C�����У������������޷��������з�����֮��Ĳ���(���㣬�Ƚϴ�С) 
    ���������Զ����з�������ʽת��Ϊ�޷��������� 
    �����з������Ĳ���ֱ����Ϊ�µ��޷������Ĳ���
	��a=-1 �����ʾΪ11111111 11111111  ֱ�ӱ�ʾ��ʮ����������65535 (2^16-1)
*/

//#include<stdio.h>
//
//int main()
//{
//	unsigned int a=2;
//	int b=-1;
//	if(a+b>b)
//	  printf("Yes\n");
//	else 
//	  printf("\n\n\n\tSurprise Motherfucker\n\n\n");
//	
//	return 0;
//}

/* a�Ĳ��룺 00000000 00000010
   b�Ĳ��룺 11111111 11111111 ת����unsigned��һλ�Ͳ���ʾ����λ�ˣ�ʮ���ƵĻ�����65535 
*/  
 

//#include<stdio.h>
//
//int main()
//{
//	unsigned int i=-1;
//   	printf("%d\n",i); //  ���Ϊ-1��%d�����з���ʮ����������ʽ��� 
//	printf("%u\n",i); //  ���Ϊ2��32�η���һ��%u�����޷���ʮ����������� 
//	
//	return 0;
//}  
