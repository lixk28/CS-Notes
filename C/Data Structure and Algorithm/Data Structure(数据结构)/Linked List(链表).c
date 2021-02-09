#include<stdio.h>
#include<stdlib.h>
 
typedef struct listNode{  // ����ڵ�Ķ��� 
	int data; // �ڵ������������������� 
	struct listNode *pNext;  // �ڵ�ĵ�ַ(ָ��)�򣬶���һ���ṹ��ָ�룬ָ����һ�ڵ� 
}listNode;

listNode *create_list(int n); //��������(����ͷָ��)
void init_list(listNode *pHead); //��ʼ������ 

listNode *search_list(listNode *pHead, int n); //����Ԫ�صĲ���
listNode *insert_node(listNode *pHead, int n, int value); //����ڵ� 
listNode *delete_node(listNode *pHead, int n); //ɾ���ڵ�

void sort_list(listNode *pHead); //����Ԫ������ 

void visit_list(listNode *pHead); //�������� 

void destroy_list(listNode *pHead); //��������

int main()
{
	int length; //����ĳ���(����ڵ�ĸ���) 
	printf("Please input the length of the Linked List:\n");
	scanf("%d", &length);
	listNode *pHead = create_list(length); //����ͷָ��
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

listNode *create_list(int n) // ������n���ڵ������ �����������ͷָ�� 
{
	listNode *pHead = (listNode *)malloc(sizeof(listNode)); //������ʱͷָ��(��Ϊ��������ֵ����ͷָ��)
	listNode *pEnd = NULL; // ����βָ�� 
	pHead->pNext = pEnd;
	
	listNode *pTemp = pHead; //������ʱ�ṹ��ָ�룬����ͷָ���ֵ 
	int i; 
	for(i=1; i<n; i++) //ע����С��n 
	{
		listNode *pNode = (listNode *)malloc(sizeof(listNode)); //�����½ڵ� 
		pTemp->pNext = pNode; //��ʱָ�������ָ��Ľṹ���pNextָ���½ڵ� 
		pTemp = pNode; //����ʱָ�������λ�ú���һλ 
	}
	pTemp->pNext = pEnd; //���һ����ӵĽڵ���ָ��Ľṹ���pNextָ��βָ��(��NULL) 
	return pHead; 
}

void init_list(listNode *pHead) // ������ֵ ��ʼ������ 
{
	listNode *pTemp = pHead;
	while(pTemp != NULL)
	{
		scanf("%d", &pTemp->data); //��������ڵ��ֵ 
		pTemp = pTemp->pNext;
	}
}

listNode *insert_node(listNode *pHead, int n, int value) // ����n���� ��Ҫ�ڵ�n���ڵ�֮���λ�ò���ڵ� 
{
	if(n == 0) // n����0��ʾ��ͷ���֮ǰ����һ���ڵ� 
	{
	    listNode *pNewhead = (listNode *)malloc(sizeof(listNode));
	    pNewhead->data = value;
	    pNewhead->pNext = pHead;
	    return pNewhead; //ע�� ����Ҫ����pNewhead ��Ϊhead���βΣ���дhHead=pNewhead��main�����е�headֵ��δ�ı�!
	}                    // ������ pHead Ϊȫ�ֱ���������insert_node��delete_node������������void����������ֵ 
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
	   listNode *pNode = (listNode *)malloc(sizeof(listNode)); //�����µĽڵ�
	   pTemp1->pNext = pNode; //ʹ��n���ڵ��pNextָ�������½ڵ� 
	   pNode->pNext = pTemp2; //ʹ������½ڵ��pNextָ���n+1���ڵ� 
       pNode->data = value; 
       return pHead;
    }
}

listNode *delete_node(listNode *pHead, int n) // ����n���� ɾ������ĵ�n���ڵ� 
{
	listNode *pLast;
	listNode *pTemp = pHead;
	if(n == 1) //��ɾ����1���ڵ㼴ͷ��㣬���⴦�� 
	{
		pTemp = pHead->pNext;
		free(pHead);
		pHead = pTemp;
		return pHead; // ע�� pHead Ӧ����Ϊͷ���δɾ��ǰ����ĵڶ����ڵ� 
	}
	else if(n >= 2)
	{
	    int i;
	    for(i=1; i<n; i++)
	    {
		    pLast = pTemp; //��ɾ���ڵ����һ���ڵ� 
		    pTemp = pTemp->pNext;
	    }
	    pLast->pNext = pTemp->pNext; //����n���ڵ㱻ɾ����������������� 
	    free(pTemp); //ɾ����n���ڵ� 
	    return pHead;
    }
}

listNode *search_list(listNode *pHead, int n) // ��������ĵ�n���ڵ� 
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

void visit_list(listNode *pHead) // ����ı������ 
{
	listNode *pTemp = pHead; 
	while(pTemp != NULL)
	{
		printf("%d ", pTemp->data); //���pTemp��ָ��Ľṹ���е����� 
		pTemp = pTemp->pNext; //ʹpTempָ���������һ���ڵ� 
	}
	printf("\n");
}

void destroy_list(listNode *pHead) // �ͷ�����Ĵ洢��Ԫ 
{
	listNode *pTemp1=pHead;
	listNode *pTemp2;
	while(pTemp1 != NULL)
	{
		pTemp2=pTemp1->pNext;
		free(pTemp1);  //��ͷ��β�����ڵ�������� 
		pTemp1=pTemp2;
	}
}
