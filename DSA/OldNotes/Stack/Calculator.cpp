#include <iostream>
#include "Calculator.h"

int main()
{
    string exp;
    cout << "Please enter an expression:\n";
    getline(cin, exp);


    string postexp = IntoPost(exp);
    cout << "The postfix expression of exp is:\n";
    cout << postexp << endl;

    int value = Calculator(postexp);
    cout << "The value of the expression is:\n";
    cout << value << endl;

    return 0;
}