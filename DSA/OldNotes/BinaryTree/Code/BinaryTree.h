#include <iostream>
#include <stack>
#include <queue>
#define NEWNODE(A, N) Node *node ## N = new Node(A, N - 1);
using namespace std;

struct Node
{
    char data;
    Node *left;
    Node *right;

    Node(char n[], int index)
    {
        data = n[index];
        left = NULL;
        right = NULL;
    }
};


class BinaryTree
{
    private:
        Node *root;

        void destroyTree(Node *node);
        Node *createTree(char n[10]);  //随机生成一棵二叉树
        Node *findNode(Node *node, char key);
        int calculateHeight(Node *node);
        int calculateNodeNum(Node *node);

    public:
        BinaryTree(char n[10]);
        ~BinaryTree();
 
        Node *getRoot();
        Node *getNode(char key);
        int getHeight();
        int getNodeNum();

        void preOrder_recursive(Node *root);
        void inOrder_recursive(Node *root);
        void postOrder_recursive(Node *root);

        void preOrder_nonrecursive1();
        void preOrder_nonrecursive2();
        void inOrder_nonrecursive();
        void postOrder_nonrecursive();

        void levelOrder();

        // void depthFirstTraverse();
        // void breadthFirstTraverse();

        // void displayLeaf();
};


