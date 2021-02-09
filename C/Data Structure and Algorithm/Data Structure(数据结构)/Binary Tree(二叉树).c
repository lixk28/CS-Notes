#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode{  //����������Ľڵ� 
    /* �ڵ�������� */
	int data; 
	/* �ڵ��ָ���� */ 
	struct TreeNode *leftchild;  // ������ 
	struct TreeNode *rightchild; // ������ 
}TreeNode;
 
void Create1_Tree(TreeNode **root); //�������Ĵ��� ����һ 
// ʹ�ö���ָ�������� �����е�root��ָ����ڵ��ַ��ָ����� 

void Create2_Tree(TreeNode *root); //�������Ĵ��� ������
// ����һ��ָ�� 
 
void pre_order(TreeNode *root); //�������������  
void in_order(TreeNode *root); //������������� 
void post_order(TreeNode *root); //������������� 
void level_order(TreeNode *root); //�������������

void Destroy_tree(TreeNode *root); //���ٶ����� 

int main()
{
	TreeNode *root=NULL; //������ڵ� 
	printf("Please input data:\n");
	Create1_Tree(&root);
	pre_order(root);
	
	return 0;
}

void Create1_Tree(TreeNode **root)
{
	int value;
	scanf("%d",&value);
	if(value < 0)
	{
		*root=NULL;
		return;
	}
	
	*root=(TreeNode *)malloc(sizeof(TreeNode)); // ������Ľڵ�ֵ��Ϊ�����ĸ��ڵ� 
	(*root)->data=value;
	
	Create1_Tree(&((*root)->leftchild)); // �ݹ鶨�� 
	Create1_Tree(&((*root)->rightchild));
}

void pre_order(TreeNode *root)
{
	if(root == NULL)
	  return;
	printf("%d ",root->data);
	pre_order(root->leftchild);
	pre_order(root->rightchild);
}


