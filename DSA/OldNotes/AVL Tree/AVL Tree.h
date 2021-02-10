#include <iostream>
#include <stack>
#include <queue>
using namespace std;

template <typename T>
struct Node
{
    T data;
    Node *left;
    Node *right;

    int leftHeight;
    int rightHeight;
    int balanceFactor;
};

template <typename T>
class AVL_Tree
{
    private:
        Node<T> *root;

    public:
        AVL_Tree();
        ~AVL_Tree();

        int Height();

        void Delete();
        void Insert();

        void Balance();

        void rightRotation();
        void leftRotation();
        void doubleRotation();

        void preOrder();
        void inOrder();
        void postOrder();


};