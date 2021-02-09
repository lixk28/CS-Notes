#include <iostream>
using namespace std;

int main()
{
    /* One-Dimension Dynamic Array */
    int n;
    cout << "Please input the length of the array:" << endl;
    cin >> n;

    int *p1 = new int[n];
    cout << "Please input the elements of the array:" << endl;
    for(int i = 0; i < n; i++)
        cin >> p1[i];
    
    cout << "The elements of the array is:" << endl;
    for(int i = 0; i < n; i++)
        cout << p1[i] << " ";
    cout << endl;

    delete[] p1;

    /* Two-Dimension Dynamic Array */
    int row, col;
    cout << "Please input the rows and the columns of the array:" << endl;
    cin >> row >> col;

    int **p2 = new int *[row];
    for(int i = 0; i < row; i++)
        p2[i] = new int[col];
    
    cout << "Please input the elements of the array:" << endl;
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            cin >> p2[i][j];

    cout << "The elements of the array is:" << endl;
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
            cout << p2[i][j] << " ";
        cout << endl;
    }

    for(int i = 0; i < row; i++)
        delete[] p2[i];
    delete p2;

    return 0;
}