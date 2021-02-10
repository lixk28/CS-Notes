#include "BinarySearchTree.h"

TreeNode *BinarySearchTree::CreateTree()
{

}

void BinarySearchTree::DestroyTree(TreeNode *root)
{
    if(root != NULL)
    {
        DestroyTree(root->left);
        DestroyTree(root->right);
        delete root;
        root = NULL;
    }
}

BinarySearchTree::BinarySearchTree()
{
    root = CreateTree();
}

BinarySearchTree::BinarySearchTree(BinarySearchTree &T)
{

}

BinarySearchTree::~BinarySearchTree()
{
    DestroyTree(root);
}

int BinarySearchTree::getHeight(TreeNode *root)
{
    int leftHeight, rightHeight;
    if(root == NULL)
        return -1;
    else
    {
        leftHeight = getHeight(root->left);
        rightHeight = getHeight(root->right);
        return leftHeight > rightHeight ? (leftHeight + 1) : (rightHeight + 1);
    }
}

int BinarySearchTree::getNodeNum(TreeNode *root)
{
    int leftNodeNum, rightNodeNum;
    if(root == NULL)
        return 0;
    else
    {
        leftNodeNum = getNodeNum(root->left);
        rightNodeNum = getNodeNum(root->right);
        return leftNodeNum + rightNodeNum + 1;
    } 
}

void BinarySearchTree::preorder(TreeNode *root)
{
    if(root != NULL)
    {
        cout << root->data;
        preorder(root->left);
        preorder(root->right);
    }
}

void BinarySearchTree::inorder(TreeNode *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        cout << root->data;
        inorder(root->right);
    }
}

void BinarySearchTree::postorder(TreeNode *root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data;
    }
}

TreeNode *BinarySearchTree::findNode(TreeNode *root, ElemType key)
{
    if(root == NULL)
        return NULL;
    else if(root->data == key)
        return root;
    else if(root->data < key)
        return findNode(root->right, key);
    else if(root->data > key)
        return findNode(root->left, key);
}

void BinarySearchTree::Insert(ElemType key)
{

}

void BinarySearchTree::Delete(ElemType key)
{

}
