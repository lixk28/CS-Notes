#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode
{
    char data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(char c = '#') {data = c; left = NULL; right = NULL;}
};

void levelorder(TreeNode *root)
{
    queue<TreeNode *> q;
    if(root != NULL)
    {
        q.push(root);
        while(!q.empty())
        {
            TreeNode *t = q.front();
            cout << t->data;
            q.pop();
            
            if(t->left != NULL)
                q.push(t->left);
            if(t->right != NULL)
                q.push(t->right);
        }
    }
}

int search(vector<string> tree, char key)
{
    int i;
    for(i = 0; i < tree.size(); i++)
        if(tree[i][0] == key)
            break;

    return i;
}

TreeNode *BuildTree(vector<string> tree, int index)
{
    TreeNode *root = new TreeNode(tree[index][0]);

    if(tree[index][1] != '#')
    {
        int i = search(tree, tree[index][1]);
        root->left = BuildTree(tree, i);
    }

    if(tree[index][2] != '#')
    {
        int i = search(tree, tree[index][2]);
        root->right = BuildTree(tree, i);
    }

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
    int level;
    cin >> level;
    vector<string> tree;
    for(int i = 0; i < level; i++)
    {
        string temp;
        cin >> temp;
        tree.push_back(temp);
    }

    TreeNode *root = BuildTree(tree, 0);
    levelorder(root);
    DestroyTree(root);

    return 0;
}