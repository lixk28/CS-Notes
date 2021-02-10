#include <iostream>
#include <stack>
#include <queue>
#include <cstddef>
using namespace std;
typedef char ElemType;

struct TreeNode
{
    ElemType data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(ElemType n, TreeNode *p = NULL, TreeNode *q = NULL): data(n), left(p), right(q) {}
    TreeNode(TreeNode *node): data(node->data), left(node->left), right(node->right) {}

};

class BinarySearchTree
{
    private:
        TreeNode *root;
        TreeNode *CreateTree();
        void DestroyTree(TreeNode *root);

    public:
        BinarySearchTree();
        BinarySearchTree(BinarySearchTree &T);
        ~BinarySearchTree();

        int getHeight(TreeNode *root);
        int getNodeNum(TreeNode *root);

        void preorder(TreeNode *root);
        void inorder(TreeNode *root);
        void postorder(TreeNode *root);

        TreeNode *findNode(TreeNode *root, ElemType key);
        void Insert(ElemType key);
        void Delete(ElemType key);

};