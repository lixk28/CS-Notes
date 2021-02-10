#include <iostream>
#include <string>
#include <cstddef>
using namespace std;

struct TreeNode
{
    char data;
    TreeNode *left;
    TreeNode *right;
};

void preorder(TreeNode *root)
{
    if(root != NULL)
    {
        cout << root->data;
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(TreeNode *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        cout << root->data;
        inorder(root->right);
    }
}

void postorder(TreeNode *root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data;
    }
}

TreeNode *BuildTree_PreAndIn(string pre, string in) //根据先序序列和中序序列构造二叉树
{
    if(pre.empty() || in.empty())
        return NULL;
    
    TreeNode *root = new TreeNode;
    root->data = pre[0];
    
    int i;	//根节点在中序序列中的位置
    for(i = 0; i < in.length(); i++)
        if(pre[0] == in[i])
            break;
    
    string leftpre = pre.substr(1, i);
    string rightpre = pre.substr(i+1);

    string leftin = in.substr(0, i);
   	string rightin = in.substr(i+1);
    
    root->left = BuildTree_PreAndIn(leftpre, leftin);
    root->right = BuildTree_PreAndIn(rightpre, rightin);
    
    return root;
}

TreeNode *BuildTree_InAndPost(string in, string post)   //根据中序序列和后序序列构造二叉树
{
    if(in.empty() || post.empty())
        return NULL;

    TreeNode *root = new TreeNode;
    unsigned int lastpos = post.length() - 1;
    root->data = post[lastpos];

    int i;
    for(i = 0; i < in.length(); i++)
        if(post[lastpos] == in[i])
            break;
    
    string leftin = in.substr(0, i);
    string rightin = in.substr(i+1, in.length()-i-1);

    string leftpost = post.substr(0, i);
    string rightpost = post.substr(i, post.length()-i-1);

    root->left = BuildTree_InAndPost(leftin, leftpost);
    root->right = BuildTree_InAndPost(rightin, rightpost);

    return root;
}

void DestroyTree(TreeNode *root)
{
    if(root != NULL)
    {
        DestroyTree(root->left);
        DestroyTree(root->right);
        delete root;
    }
}



int main()
{
    int mode;
    TreeNode *tree;
    cout << "Please choose mode (1 / 2): ";
    cin >> mode;

    if(mode == 1)
    {
        string pre, in;
        cout << "Please enter the pre and in sequence of the binary tree:\n";
        cout << "pre: "; cin >> pre;
        cout << "in: "; cin >> in;
        tree = BuildTree_PreAndIn(pre, in);
    }
    else if(mode == 2)
    {
        string in, post;
        cout << "Please enter the in and post sequence of the binary tree:\n";
        cout << "in: "; cin >> in;
        cout << "post: "; cin >> post;
        tree = BuildTree_InAndPost(in, post);
    }
    else
    {
        cout << "Invalid input!" << endl;
    }

    cout << "pre seq: "; preorder(tree); cout << endl;
    cout << "in seq: "; inorder(tree); cout << endl;
    cout << "post seq: "; postorder(tree); cout << endl;

    DestroyTree(tree);

    return 0;
}