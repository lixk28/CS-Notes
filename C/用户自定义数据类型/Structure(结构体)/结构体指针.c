/* 结构体指针 */
// 所谓结构体指针就是指向结构体变量的指针
// 一个结构体变量的起始地址就是该结构体变量的指针
 
#include<stdio.h>
#include<string.h>

struct Student
{
	int num;
	char name[10];
	char sex;
	float score;
}me;
 
int main()
{
	// 指向结构体对象的指针变量既可指向结构体变量，又可指向结构体数组中的元素
	// 指针变量的基类型必须与结构体变量的类型相同 
	
	/*** <1> 指向结构体变量的指针 ***/ 
	struct Student *p1=&me;
	(*p1).num=19335109;
	strcpy((*p1).name,"李雪堃");
	(*p1).sex='M';
	(*p1).score=100.00;
	printf("No:%d\n",(*p1).num);
	printf("name:%s\n",(*p1).name);
	printf("sex:%c\n",(*p1).sex);
	printf("score:%.2f\n\n",(*p1).score);
	//***** 注意：(*p).member 的括号不能省！！！
	//***** 因为成员运算符 . 的优先级高于 *  如果去掉的话，就等价于 *(p.num) 了
	
	// 为了使用方便和直观，C语言允许把 (*p).member 用 p->member 代替
	// ->代表一个箭头，p->member表示 p所指向的结构体变量中的member成员
	// ->称为指向运算符 
	
	// 设 p=&structure_name以下三者等价： (structure_name是结构体变量名，member是成员名) 
	//(1) structure_name.member
	//(2) (*p).member
	//(3) p->member 
	printf("No:%d\n",p1->num);
	printf("name:%s\n",p1->name);
	printf("sex:%c\n",p1->sex);
	printf("score:%.2f\n\n",p1->score);
	
	/* <2> 指向结构体数组的指针 */
	// 可以用指针变量指向结构体数组的元素 实质上还是指向结构体变量 
	// 指向结构体变量的指针变量不能用来指向结构体中的某一成员 
	struct Student stu[3]={{19335109,"李雪堃",'M',100},{19335110,"李宜谦",'M',100},{19335111,"李俞乐",'M',100}};
	struct Student *p2=stu;
	int i;
	for(i=0;i<3;i++)
	printf("No:%d\nname:%s\nsex:%c\nscore:%.2f\n\n",(p2+i)->num,(p2+i)->name,(p2+i)->sex,(p2+i)->score);
	// 注意：p2+i指向的是结构体数组的第 i 个元素 
	
	// (++p)->member : 先使p自加1，然后得到p指向的元素中的member成员的值
	// (p++)->member : 先使用p的值，即p->member，得到member的值，再令p自加1
	
	return 0;
} 
