// 数组元素 可以作为函数参数
// 数组名 也可以作为函数参数(包括形参和实参) 

//*** 用数组元素作实参时，向形参变量传递的是数组元素的值
//*** 而用数组名作函数实参时，向形参变量(这时的形参应是 数组名 或 指针变量 )传递的是数组首元素的地址 

// 求10名学生的平均成绩 篡改学生成绩 
#include<stdio.h>
float average_array(float array[]) // 声明形参数组时不必声明数组长度，但必须跟一个空的方括号 
{                      
    // C编译系统并不会检查形参数组的大小，只是将 实参数组的首元素的地址 传递给 形参数组名
    // 这样形参数组就获得了与实参数组相同的初始地址
 
	int i;                // 实际上C编译系统是把形参数组作为形参指针变量来处理 即 float array[] >>> float *array 
	float average,sum=0;    
	for(i=0;i<10;i++)     //*** 形参数组 完全等价于 形参指针变量  
	sum+=array[i];        // int array[] == int *pointer
	average=sum/10;       // 对指针做的 任何 操作和运算都可以作用在array上!!!!
	return average;
}

float average_pointer(float *p) //指针法求十名学生平均成绩 
{
	int i;
	float average,sum=0;
	for(i=0;i<10;i++)
	sum+=*p++;
	average=sum/10;
	return average;
}

void modify(float array[]) // 篡改某一名学生的成绩 ^_^
{
	int i;
	float grade;
	printf("I konw your grade sucks, dude.\n");
	printf("But I can help you.^_^\n") ;
	printf("Please input your student number:");
	scanf("%d",&i);
	printf("Please input the grade you want:");
	scanf("%f",&grade);
	
	//***** 用数组名做函数实参时，形参数组与实参数组 就共同占用一段相同的内存单元
	//***** 也就是说，形参数组中元素的值若发生改变，实参数组中元素的值也会同时发生相同改变
	 
	array[i-1]=grade;  // 也可以写成 *(array+i-1)=grade 
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
