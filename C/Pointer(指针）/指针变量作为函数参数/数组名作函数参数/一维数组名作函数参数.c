// ����Ԫ�� ������Ϊ��������
// ������ Ҳ������Ϊ��������(�����βκ�ʵ��) 

//*** ������Ԫ����ʵ��ʱ�����βα������ݵ�������Ԫ�ص�ֵ
//*** ����������������ʵ��ʱ�����βα���(��ʱ���β�Ӧ�� ������ �� ָ����� )���ݵ���������Ԫ�صĵ�ַ 

// ��10��ѧ����ƽ���ɼ� �۸�ѧ���ɼ� 
#include<stdio.h>
float average_array(float array[]) // �����β�����ʱ�����������鳤�ȣ��������һ���յķ����� 
{                      
    // C����ϵͳ���������β�����Ĵ�С��ֻ�ǽ� ʵ���������Ԫ�صĵ�ַ ���ݸ� �β�������
    // �����β�����ͻ������ʵ��������ͬ�ĳ�ʼ��ַ
 
	int i;                // ʵ����C����ϵͳ�ǰ��β�������Ϊ�β�ָ����������� �� float array[] >>> float *array 
	float average,sum=0;    
	for(i=0;i<10;i++)     //*** �β����� ��ȫ�ȼ��� �β�ָ�����  
	sum+=array[i];        // int array[] == int *pointer
	average=sum/10;       // ��ָ������ �κ� ���������㶼����������array��!!!!
	return average;
}

float average_pointer(float *p) //ָ�뷨��ʮ��ѧ��ƽ���ɼ� 
{
	int i;
	float average,sum=0;
	for(i=0;i<10;i++)
	sum+=*p++;
	average=sum/10;
	return average;
}

void modify(float array[]) // �۸�ĳһ��ѧ���ĳɼ� ^_^
{
	int i;
	float grade;
	printf("I konw your grade sucks, dude.\n");
	printf("But I can help you.^_^\n") ;
	printf("Please input your student number:");
	scanf("%d",&i);
	printf("Please input the grade you want:");
	scanf("%f",&grade);
	
	//***** ��������������ʵ��ʱ���β�������ʵ������ �͹�ͬռ��һ����ͬ���ڴ浥Ԫ
	//***** Ҳ����˵���β�������Ԫ�ص�ֵ�������ı䣬ʵ��������Ԫ�ص�ֵҲ��ͬʱ������ͬ�ı�
	 
	array[i-1]=grade;  // Ҳ����д�� *(array+i-1)=grade 
	printf("Now your grade has been modified!\n");
}
 
int main()
{
	float score[10],average1,average2;
	int i;
	printf("Please input 10 scores:\n");
	for(i=0;i<10;i++)
	scanf("%f",&score[i]);
	printf("\n");
	average1=average_array(score);
	average2=average_pointer(score);
	printf("average1 = %5.2f\n",average1);
	printf("average2 = %5.2f\n",average2);
	printf("\n");
	
	modify(score);
	for(i=0;i<10;i++)
	printf("%5.2f ",score[i]);
	return 0;
}
