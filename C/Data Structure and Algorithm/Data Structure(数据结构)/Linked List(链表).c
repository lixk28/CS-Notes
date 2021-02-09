#include<stdio.h>
#include<stdlib.h>
 
typedef struct listNode{  // 链表节点的定义 
	int data; // 节点的数据域，用来存放数据 
	struct listNode *pNext;  // 节点的地址(指针)域，定义一个结构体指针，指向下一节点 
}listNode;

listNode *create_list(int n); //创建链表(返回头指针)
void init_list(listNode *pHead); //初始化链表 

listNode *search_list(listNode *pHead, int n); //链表元素的查找
listNode *insert_node(listNode *pHead, int n, int value); //插入节点 
listNode *delete_node(listNode *pHead, int n); //删除节点

void sort_list(listNode *pHead); //链表元素排序 

void visit_list(listNode *pHead); //遍历链表 

void destroy_list(listNode *pHead); //销毁链表

int main()
{
	int length; //链表的长度(链表节点的个数) 
	printf("Please input the length of the Linked List:\n");
	scanf("%d", &length);
	listNode *pHead = create_list(length); //定义头指针
	printf("Please input the data of each node:\n");
	init_list(pHead);
	printf("The Linked List is:\n");
	visit_list(pHead);
	
	int n, value;
	printf("Please input the position and the value of the node you want to insert:\n");
	scanf("%d %d", &n, &value);
	printf("The Linked List after insert:\n");
	visit_list( pHead = insert_node(pHead, n, value) );
	
	printf("Please input the position of the node you want to delete:\n");
	scanf("%d", &n);
	printf("The Linked List after delete:\n");
	visit_list( pHead = delete_node(pHead, n) );
	
	printf("Please input the position of the node you want to search:\n");
	scanf("%d", &n);
	listNode *target = search_list(pHead, n);
	printf("The %dth element of the Linked List is %d\n", n, target->data);
	
	sort_list(pHead);
	printf("The sorted Linked List is:\n");
	visit_list(pHead);

	return 0;
} 

listNode *create_list(int n) // 建立有n个节点的链表 并返回链表的头指针 
{
	listNode *pHead = (listNode *)malloc(sizeof(listNode)); //定义临时头指针(作为函数返回值传给头指针)
	listNode *pEnd = NULL; // 定义尾指针 
	pHead->pNext = pEnd;
	
	listNode *pTemp = pHead; //定义临时结构体指针，保存头指针的值 
	int i; 
	for(i=1; i<n; i++) //注意是小于n 
	{
		listNode *pNode = (listNode *)malloc(sizeof(listNode)); //创建新节点 
		pTemp->pNext = pNode; //临时指针变量所指向的结构体的pNext指向新节点 
		pTemp = pNode; //将临时指针变量的位置后移一位 
	}
	pTemp->pNext = pEnd; //最后一个添加的节点所指向的结构体的pNext指向尾指针(即NULL) 
	return pHead; 
}

void init_list(listNode *pHead) // 输入数值 初始化链表 
{
	listNode *pTemp = pHead;
	while(pTemp != NULL)
	{
		scanf("%d", &pTemp->data); //输入各个节点的值 
		pTemp = pTemp->pNext;
	}
}

listNode *insert_node(listNode *pHead, int n, int value) // 输入n代表 想要在第n个节点之后的位置插入节点 
{
	if(n == 0) // n等于0表示在头结点之前插入一个节点 
	{
	    listNode *pNewhead = (listNode *)malloc(sizeof(listNode));
	    pNewhead->data = value;
	    pNewhead->pNext = pHead;
	    return pNewhead; //注意 必须要返回pNewhead 因为head是形参，若写hHead=pNewhead，main函数中的head值并未改变!
	}                    // 可以设 pHead 为全局变量，这样insert_node和delete_node函数都可以是void，不带返回值 
	else if(n >= 1)  
	{
	   listNode *pTemp1 = pHead;
	   listNode *pTemp2 = pHead->pNext;
	
	   int i;
	   for(i=1; i<n; i++)
	   {
		   pTemp1 = pTemp1->pNext;
		   pTemp2 = pTemp2->pNext;
	   }
	   listNode *pNode = (listNode *)malloc(sizeof(listNode)); //建立新的节点
	   pTemp1->pNext = pNode; //使第n个节点的pNext指向插入的新节点 
	   pNode->pNext = pTemp2; //使插入的新节点的pNext指向第n+1个节点 
       pNode->data = value; 
       return pHead;
    }
}

listNode *delete_node(listNode *pHead, int n) // 输入n代表 删除链表的第n个节点 
{
	listNode *pLast;
	listNode *pTemp = pHead;
	if(n == 1) //若删除第1个节点即头结点，特殊处理 
	{
		pTemp = pHead->pNext;
		free(pHead);
		pHead = pTemp;
		return pHead; // 注意 pHead 应当变为头结点未删除前链表的第二个节点 
	}
	else if(n >= 2)
	{
	    int i;
	    for(i=1; i<n; i++)
	    {
		    pLast = pTemp; //被删除节点的上一个节点 
		    pTemp = pTemp->pNext;
	    }
	    pLast->pNext = pTemp->pNext; //将第n个节点被删除后的链表连接起来 
	    free(pTemp); //删除第n个节点 
	    return pHead;
    }
}

listNode *search_list(listNode *pHead, int n) // 查找链表的第n个节点 
{
	listNode *pTemp = pHead;
	int i;
	for(i=1; i<n; i++)
	  pTemp = pTemp->pNext;  
	return pTemp;
}

void sort_list(listNode *pHead)
{
	listNode *pTemp1 = pHead;
	listNode *pTemp2;
	int temp;
	for(pTemp1; pTemp1->pNext != NULL; pTemp1 = pTemp1->pNext)
 	  for(pTemp2 = pTemp1->pNext; pTemp2 != NULL; pTemp2 = pTemp2->pNext)
 	  {
 	  	if(pTemp1->data > pTemp2->data)
 	  	temp = pTemp2->data,pTemp2->data = pTemp1->data,pTemp1->data = temp;
	  }
}

void visit_list(listNode *pHead) // 链表的遍历输出 
{
	listNode *pTemp = pHead; 
	while(pTemp != NULL)
	{
		printf("%d ", pTemp->data); //输出pTemp所指向的结构体中的数据 
		pTemp = pTemp->pNext; //使pTemp指向链表的下一个节点 
	}
	printf("\n");
}

void destroy_list(listNode *pHead) // 释放链表的存储单元 
{
	listNode *pTemp1=pHead;
	listNode *pTemp2;
	while(pTemp1 != NULL)
	{
		pTemp2=pTemp1->pNext;
		free(pTemp1);  //从头到尾，将节点逐个销毁 
		pTemp1=pTemp2;
	}
}
