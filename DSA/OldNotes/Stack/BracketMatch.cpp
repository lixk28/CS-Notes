#include <iostream>
#include <stack>
#include <string>
#define MAXSIZE 1000
using namespace std;

bool isPair(char c1, char c2)
{
    if(c1 == '(' && c2 == ')')  
        return true;
    else if(c1 == '[' && c2 == ']')
        return true;
    else if(c1 == '{' && c2 == '}')
        return true;
    else 
        return false;
}

int isMatch(string exp)
{
    stack<char> s;
    for(int i = 0; i < exp.length(); i++)
    {
        if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
            s.push(exp[i]);
        else if(exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
        {
            if(!s.empty())
            {
                if(isPair(s.top(), exp[i]))
                    s.pop();
                else
                    return 1;
            }
            else
                return 3;
        }
    }
    if(!s.empty())
        return 2;
    else
        return 0;
}

int main()
{
    while(true)
    {
        string exp;
        cout << "Please enter an expression:\n";
        getline(cin, exp);

        int flag = isMatch(exp);
        if(flag == 0)
            cout << "Bracket Match!" << endl;
        else if(flag == 1)
            cout << "Error Type 1: Doesn't match" << endl;
        else if(flag == 2)
            cout << "Error Type 2: There exist unpaired left bracket" << endl;
        else if(flag == 3)
            cout << "Error Type 3: There exist unpaired right bracket" << endl;
    }

    return 0;
}