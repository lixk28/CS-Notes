#include<stdio.h>
#include<stdlib.h>
 
// 一个元素全部是指针型数据的数组称为 指针数组
// 也就是说 指针数组中的每一个元素都存放一个地址，相当于一个指针变量

// 定义一个一维指针数组的一般形式为：
// 类型名 *数组名[数组长度];
 
int main()
{
	int n;
	printf("Please input the number of the strings:\n");
	scanf("%d",&n);
	char *a[n];
	printf("Please enter the strings:\n");
	getchar(); // get '\n'
	// 指针数组可以初始化
	// 用与数组初始化相同的初始化列表的方式，则指针数组中每个元素指向每个子列表的首地址
	// 其他注意事项与数组基本相同 
	
	int i;
	for(i=0;i<n;i++)
	{
		a[i]=(char *)malloc(sizeof(char)*100); 
		gets(a[i]); 
	}
	//***** 注意!!!：若只是定义了一个指针数组 而未对其初始化，那么该指针数组中的每个指针变量的指向是不确定的 
	//               要想将变量的值赋给其所指向的内存空间，就无法完成，因为这是野指针（指向不清） 
	//               就必须先malloc一段内存空间给它，才能将变量的值存储到它所指向的内存空间 
	for(i=0;i<n;i++)
	{
	    puts(a[i]);
	    free(a[i]);
	}
	
	return 0;
}
