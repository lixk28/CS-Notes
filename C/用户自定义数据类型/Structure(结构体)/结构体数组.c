/* �ṹ������ */ 
// ��ǰ������鲻֮ͬ�����ڽṹ�������е�ÿ��Ԫ�ض���һ���ṹ����������ṹ������а���������Ա 
// һ��һά�ṹ��������൱��һ����ǿ���ά���飬�ö�ά�����ÿһ�ж����Դ�Ų�ͬ���͵�����
 
#include<stdio.h>

struct Person // �������˾�ѡĳһְλ��ͳ�Ƹ���ѡ�˵�Ʊ�� 
{
	char name;
	int vote;
}leader[3]={'L',0,'W',0,'C',0};
/*** ����ṹ�������һ����ʽ ***/ 

// <1> struct �ṹ����
//     {
//      ��Ա���� 
//     } ������[���鳤��]; 

// <2> �ṹ������ ������[���鳤��]��

// �Խṹ�������ʼ������ʽ��
//  ���ϳ�ʼ�����У� ={��ʼ������}
// <1> ���ṹ������ĸ���Ԫ�صĳ�Ա�в����ṹ�����������ֵ�ö��ŷֿ� {"string",'character','integer'}
// <2> ���ṹ������ĸ���Ԫ�صĳ�Ա�ں��нṹ�������{"string",'character','integer',{a,b,c}}

int main()
{
	int i,n;
	char c;
	printf("Please input the number of the votes:\n");
	scanf("%d",&n);
	printf("Please input the leader's name:\n");
	for(i=0;i<n;i++)
	{
		getchar();
		scanf("%c",&c);
		switch(c)
			{
				case 'L':leader[0].vote++;break;
				case 'W':leader[1].vote++;break;
				case 'C':leader[2].vote++;break;
			}
	}
	
	printf("\nResult:\n");
	for(i=0;i<3;i++)
	printf(" %c: %d\n",leader[i].name,leader[i].vote);
	
	return 0;
}
