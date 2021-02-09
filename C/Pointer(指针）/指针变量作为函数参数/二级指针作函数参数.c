/* 二级指针作函数参数 */
#include<stdio.h>

//*** 当你想传递一个实参到一个函数中，经过改变再拿来使用的话，需要这样: 
// (1) 想改变 int a 的值需要传递 a 的地址 &a（a的指针）的值
// (2) 想改变 int *a 指针的内容，需要传递 &a（就是指针的指针）

//*** 也就是说在函数中你不能通过改变形参的值来改变实参的值 
//*** 但是可以间接传入实参的地址，通过该地址在函数中找到储存实参的内存单元，修改内存单元中的值，进而改变实参的值

// 如果实参是一个指针变量，那么传入它的指针，通过这个指针修改实参
// 也就是可以达到修改实参的指向的目的
// 这点在链表、二叉树等数据结构中有很广泛的应用 

void change1(int *a,int value);
void change2(int **a,int value);

int main()
{
	int num,value;
	printf("Please input integer and the value you want to change to\n");
	printf("num:");
	scanf("%d",&num);
	printf("value:");
	scanf("%d",&value);
	
	int *p=&num; 
	
	change1(p,value);
	printf("num after change 1 = %d\n",*p);
	
	change2(&p,value);
	printf("num after change 2 = %d\n",*p);
	
	return 0;
} 

void change1(int *p, int value)
{
	p=&value; //改变的是形参p的值，并没有改变实参p的值 
}

void change2(int **p,int value)
{
	*p=&value; //通过二级指针，改变了指针p的指向，从而改变了p所指向内存单元的值 
}
