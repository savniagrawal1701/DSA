#include <bits/stdc++.h>
using namespace std;

string postfixToInfix(string postfix)
{
    stack<string> s;
    int n = postfix.size();

    for (int i = 0; i < n; i++)
    {
        char c = postfix[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            {
                s.push(string(1, c));
            }
        else
        {

            string op2 = s.top();
            s.pop();
            string op1 = s.top();
            s.pop();

            s.push("(" + op1 + c + op2 + ")");
        }
    }

    return s.top();
}

int main()
{
    string postfix = "AB-DE+F*/";
    cout << "Infix Expression: " << postfixToInfix(postfix) << endl;
    return 0;
}
