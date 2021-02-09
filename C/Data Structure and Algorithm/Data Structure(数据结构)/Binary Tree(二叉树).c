#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode{  //定义二叉树的节点 
    /* 节点的数据域 */
	int data; 
	/* 节点的指针域 */ 
	struct TreeNode *leftchild;  // 左子树 
	struct TreeNode *rightchild; // 右子树 
}TreeNode;
 
void Create1_Tree(TreeNode **root); //二叉树的创建 方法一 
// 使用二级指针作参数 函数中的root是指向根节点地址的指针变量 

void Create2_Tree(TreeNode *root); //二叉树的创建 方法二
// 传入一级指针 
 
void pre_order(TreeNode *root); //先序遍历二叉树  
void in_order(TreeNode *root); //中序遍历二叉树 
void post_order(TreeNode *root); //后序遍历二叉树 
void level_order(TreeNode *root); //层序遍历二叉树

void Destroy_tree(TreeNode *root); //销毁二叉树 

int main()
{
	TreeNode *root=NULL; //定义根节点 
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
	
	*root=(TreeNode *)malloc(sizeof(TreeNode)); // 将传入的节点值作为子树的根节点 
	(*root)->data=value;
	
	Create1_Tree(&((*root)->leftchild)); // 递归定义 
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


