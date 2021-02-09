/* 结构体数组 */ 
// 与前面的数组不同之处在于结构体数组中的每个元素都是一个结构体变量，而结构体变量中包含各个成员 
// 一个一维结构体数组就相当于一个加强版二维数组，该二维数组的每一列都可以存放不同类型的数据
 
#include<stdio.h>

struct Person // 有三个人竞选某一职位，统计各候选人得票数 
{
	char name;
	int vote;
}leader[3]={'L',0,'W',0,'C',0};
/*** 定义结构体数组的一般形式 ***/ 

// <1> struct 结构体名
//     {
//      成员表列 
//     } 数组名[数组长度]; 

// <2> 结构体类型 数组名[数组长度]；

// 对结构体数组初始化的形式是
//  加上初始化表列： ={初始化表列}
// <1> 若结构体数组的各个元素的成员中不含结构体变量：各个值用逗号分开 {"string",'character','integer'}
// <2> 若结构体数组的各个元素的成员在含有结构体变量：{"string",'character','integer',{a,b,c}}

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
