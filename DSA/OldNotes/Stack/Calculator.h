#include <string>
#include <stack>
#include <typeinfo>
using namespace std;

bool Priority(char c1, char c2)
{
    if(c1 == '*' || c1 == '/')
        if(c2 == '+' || c2 == '-')
            return true;
        if(c2 == '*' || c2 == '/')
            return false;
    
    if(c1 == '+' || c1 == '-')
        return false;
}

int Operate(int opnd1, char optr, int opnd2)
{
    switch (optr)
    {
        case '+': return opnd1 + opnd2;
        case '-': return opnd1 - opnd2;
        case '*': return opnd1 * opnd2;
        case '/': return opnd1 / opnd2;
    }
}

string IntoPost(string inexp)
{
    char c;
    stack<char> op;
    string postexp;
    int i = 0;
    
    while(i < inexp.length())
    {
        c = inexp[i];
        switch (c)
        {
            case '(': 
                op.push(c);
                i++;
                break;

            case ')': 
                while(op.top() != '(')
                {
                    postexp.push_back(op.top());
                    op.pop();
                }
                op.pop();
                i++;
                break;

            case '+':
            case '-':
            case '*':
            case '/':
                if(op.empty())
                    op.push(c);
                else 
                {
                    if(op.top() == '(')
                        op.push(c);
                    
                    if(Priority(c, op.top()))
                        op.push(c);
                    else
                    {
                        while(!Priority(c, op.top()))
                        {
                            postexp.push_back(op.top());
                            op.pop();
                        }
                        op.push(c);
                    }
                }
                i++;
                break;

            default:
                while(c >= '0' && c <= '9')
                {
                    postexp.push_back(c);
                    c = inexp[++i];
                }
                postexp.push_back('#');
        }
    }

    while(!op.empty())
    {
        postexp.push_back(op.top());
        op.pop();
    }
}

int Calculator(string postexp)
{

}