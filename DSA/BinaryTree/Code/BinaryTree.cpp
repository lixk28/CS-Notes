#include "BinaryTree.h"

Node *BinaryTree::createTree(char n[10])
{
    NEWNODE(n, 1);
    NEWNODE(n, 2);
    NEWNODE(n, 3);
    NEWNODE(n, 4);
    NEWNODE(n, 5);
    NEWNODE(n, 6);
    NEWNODE(n, 7);
    NEWNODE(n, 8);
    NEWNODE(n, 9);
    NEWNODE(n, 10);

    node1->left = node2, node1->right = node3;
    node2->left = node4, node2->right = node5;
    node3->left = node6, node3->right = node7;
    node4->left = node8, node4->right = node9;
    node6->left = node10;

    return node1;
}


void BinaryTree::destroyTree(Node *node)
{
    if(node != NULL)
    {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
        node = NULL;
    }
}


Node *BinaryTree::findNode(Node *node, char key)
{
    if(node == NULL)
        return NULL;
    if(node->data == key)
        return node;
    
    Node *node1 = findNode(node->left, key);
    Node *node2 = findNode(node->right, key);
    if(node1 == NULL && node2 == NULL)
        return NULL;
    else if(node1 != NULL)
        return node1;
    else if(node2 != NULL)
        return node2;
    else
        return NULL;
}


int BinaryTree::calculateHeight(Node *node)
{
    int leftHeight, rightHeight;
    if(node == NULL)
        return -1;
    else
    {
        leftHeight = calculateHeight(node->left);
        rightHeight = calculateHeight(node->right);
        return leftHeight > rightHeight ? (leftHeight + 1) : (rightHeight + 1);
    }
}


int BinaryTree::calculateNodeNum(Node *node)
{
    int leftNodeNum, rightNodeNum;
    if(node == NULL)
        return 0;
    else
    {
        leftNodeNum = calculateNodeNum(node->left);
        rightNodeNum = calculateNodeNum(node->right);
        return leftNodeNum + rightNodeNum + 1;
    }
}




BinaryTree::BinaryTree(char n[10])
{
    root = createTree(n);
}


BinaryTree::~BinaryTree()
{
    destroyTree(root);
}


Node *BinaryTree::getRoot()
{
    return root;
}


Node *BinaryTree::getNode(char key)
{
    return findNode(root, key);
}


int BinaryTree::getHeight()
{
    return calculateHeight(root);
}


int BinaryTree::getNodeNum()
{
    return calculateNodeNum(root);
}




void BinaryTree::preOrder_recursive(Node *root)
{
    if(root != NULL)
    {
        cout << root->data;
        preOrder_recursive(root->left);
        preOrder_recursive(root->right);
    }
}


void BinaryTree::inOrder_recursive(Node *root)
{
    if(root != NULL)
    {
        inOrder_recursive(root->left);
        cout << root->data;
        inOrder_recursive(root->right);
    }
}


void BinaryTree::postOrder_recursive(Node *root)
{
    if(root != NULL)
    {
        postOrder_recursive(root->left);
        postOrder_recursive(root->right);
        cout << root->data;
    }
}


void BinaryTree::preOrder_nonrecursive1()
{
    Node *p = root;
    stack<Node *> s;
    if(p != NULL)
    {
        s.push(p);
        while(!s.empty())
        {
            p = s.top();
            cout << p->data;
            s.pop();
            if(p->right != NULL)
                s.push(p->right);
            if(p->left != NULL)
                s.push(p->left);
        }
    }
}


void BinaryTree::preOrder_nonrecursive2()
{
    Node *curr = root;
    stack<Node *> s;
    while(!s.empty() || curr != NULL)
    {
        while(curr != NULL)
        {
            cout << curr->data;
            s.push(curr);
            curr = curr->left;
        }

        if(!s.empty())
        {
            curr = s.top()->right;
            s.pop();
        }
    }
}


void BinaryTree::inOrder_nonrecursive()
{
    Node *curr = root;
    stack<Node *> s;
    while(!s.empty() || curr != NULL)
    {
        while(curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }

        if(!s.empty())
        {
            cout << s.top()->data;
            curr = s.top()->right;
            s.pop();
        }
    }
}


void BinaryTree::postOrder_nonrecursive()
{
    Node *curr = root;
    stack<Node *> s1, s2;
    s1.push(root);
    while(!s1.empty())
    {
        curr = s1.top();
        s2.push(curr);
        s1.pop();
        if(curr->left != NULL)
            s1.push(curr->left);
        if(curr->right != NULL)
            s1.push(curr->right);
    }

    while(!s2.empty())
    {
        cout << s2.top()->data;
        s2.pop();
    }
}


void BinaryTree::levelOrder()
{
    queue<Node *> q;
    Node *curr = root;
    if(root != NULL)
    {
        q.push(root);
        while(!q.empty())
        {
            curr = q.front();
            q.pop();
            cout << curr->data;

            if(curr->left != NULL)
                q.push(curr->left);
            if(curr->right != NULL)
                q.push(curr->right);
        }
    }
}
