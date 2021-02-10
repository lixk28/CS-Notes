#include "BinaryTree.h"

int main()
{
    char n[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    BinaryTree tree(n);

    int h = tree.getHeight();
    cout << "The height of the tree: " << h << endl;

    int a = tree.getNodeNum();
    cout << "The node num of the tree: " << a << endl;

    cout << "Recursive preorder: ";
    tree.preOrder_recursive(tree.getRoot());
    cout << endl;

    cout << "Recursive inorder: ";
    tree.inOrder_recursive(tree.getRoot());
    cout << endl;

    cout << "Recursive postorder: ";
    tree.postOrder_recursive(tree.getRoot());
    cout << endl;

    cout << "Levelorder: ";
    tree.levelOrder();
    cout << endl;

    cout << "Nonrecursive1 preorder: ";
    tree.preOrder_nonrecursive1();
    cout << endl;

    cout << "Nonrecursive2 preorder: ";
    tree.preOrder_nonrecursive2();
    cout << endl;

    cout << "Nonrecursive inorder: ";
    tree.inOrder_nonrecursive();
    cout << endl;

    cout << "Nonrecursive postorder: ";
    tree.postOrder_nonrecursive();
    cout << endl;

    cout << "Search for node: ";
    char c;
    cin >> c;
    Node *node = tree.getNode(c);
    if(node == NULL)
        cout << "node " << c << " is not in the tree." << endl;
    else
        cout << "node " << c << " is in the tree." << endl;

    system("pause");

    return 0;
}