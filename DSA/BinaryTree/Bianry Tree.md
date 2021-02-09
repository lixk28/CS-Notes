# Binary Tree 二叉树

## 1. 二叉树的定义

二叉树（binary tree）是一个有限的节点集合，这个集合或为空，或者由一个根节点和两棵互不相交的称为左子树（left subtree）和右子树（right subtree）的二叉树构成

归纳定义：

+ 空树是二叉树
+ 由两棵二叉树分别作为左子树和右子树，一个非空节点作为根节点的树是二叉树

**:star:注意：二叉树 $\neq$ 2次树**

---

对于满树和完全树的定义，国内外教材有歧义，以下定义是国外教材的定义：

**满二叉树（full binary tree）**：在一棵二叉树中，如果每个节点的度不是0就是2，那么称为满二叉树

**完全二叉树（complete binary tree）**：在一棵满二叉树中，如果所有的叶子节点都在最底层，那么称为完全二叉树

---

## 2. 二叉树的存储结构

+ 顺序存储结构

+ 链式存储结构

  二叉树的链式存储结构通常称为**二叉链（binary linked list）**，每个节点都有一个存放数据的数据域、一个指向左孩子的指针域、一个指向右孩子的指针域，通过根节点指针来唯一地表示整个二叉树

  ~~~C++
  struct TreeNode
  {
      ElemType data;		//数据
      TreeNode *left;		//指向左孩子节点
      TreeNode *right;	//指向右孩子节点
  }
  ~~~

  二叉链存储结构比较节省存储空间

---

## 3. 二叉树的基本运算及操作

+ 创建二叉树

  ~~~C++
  void CreateTree()
  {
      
  }
  ~~~

+ 销毁二叉树

  ~~~C++
  void DestroyTree(TreeNode *root)
  {
      if(root != NULL)	//如果根节点不为空
      {
          DestroyTree(root->left);	//销毁左子树
          DestroyTree(root->right);	//销毁右子树
          delete root;	//再来删除根节点
          root = NULL;	//好习惯
      }
  }
  ~~~

+ 查找节点

  ~~~C++
  TreeNode *FindNode(TreeNode *root, ElemType key)
  {
      if(root == NULL)	//如果根节点为空
          return NULL;
     	if(root->data == key)	//如果找到
          return root;
      
      TreeNode *node1, *node2;
      node1 = FindNode(root->left, key);
      node2 = FindNode(root->right, key);
      
      if(node1 == NULL && node2 == NULL)	//左子树中和右子树中都没有找到
          return NULL;
     	else if(node1 != NULL)	//在左子树中找到
          return node1;
     	else if(node2 != NULL)	//在右子树中找到
         	return node2;
  }
  ~~~

+ 先序遍历

  ~~~C++
  void preoderTraversal(TreeNode *root)
  {
      if(root != NULL)
      {
          cout << root->data;				//访问根节点
          preorderTraversal(root->left);	//先序遍历左子树
          preorderTraversal(root->right);	//先序遍历右子树
      }
  }
  ~~~

+ 中序遍历

  ~~~C++
  void inorderTraversal(TreeNode *root)
  {
      if(root != NULL)
      {
          inorderTraversal(root->left);
          cout << root->data;
          inorderTraversal(root->right);
      }
  }
  ~~~

+ 后序遍历

  ~~~C++
  void postorderTraversal(TreeNode *root)
  {
      if(root != NULL)
      {
          postorderTraversal(root->left);
          postorderTraversal(root->right);
          cout << root->data;
      }
  }
  ~~~

+ 求二叉树高度

  空树的高度为 -1，只有根节点的树高度为 0

  ~~~C++
  int getHeight(TreeNode *root)
  {
      int leftHeight, rightHeight;
      if(root == NULL)	//空树的高度为-1
          return -1;
      else
      {
          leftHeight = getHeight(root->left);		//求左子树的高度
          rightHeight = getHeight(root->right);	//求右子树的高度
          return leftHeight > rightHeight ? (leftHeight + 1) : (rightHeight + 1);
          //两个子树高度的最大值+1为树的高度
      }
  }
  ~~~

+ 求二叉树节点个数

  ~~~C++
  int getNodeNum(TreeNode *root)
  {
  	int leftNum, rightNum;
  	if(root == NULL)
  		return 0;
  	else
  	{
  		leftNum = getNodeNum(root->left);		//求左子树的节点个数
  		rightNum = getNodeNum(root->right);		//求右子树的节点个数
  		return leftNum + rightNum + 1;
  		//两个子树的节点个数之和加上根节点为树的节点个数
  	}
  }
  ~~~

+ 求二叉树树叶的个数

  ~~~C++
  int getLeafNum(TreeNode *root)
  {
      
  }
  ~~~

---



