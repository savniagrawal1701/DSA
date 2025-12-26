#include <bits/stdc++.h>
using namespace std;

string prefixToInfix(string postfix)
{
    stack<string> s;
    int n = postfix.size();

    for (int i = n-1; i>=0; i--)
    {
        char c = postfix[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            {
                s.push(string(1, c));
            }
        else
        {

            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();

            s.push("(" + op1 + c + op2 + ")");
        }
    }

    return s.top();
}

int main()
{
    string postfix = "*+PQ-MN";
    cout << "Infix Expression: " << prefixToInfix(postfix) << endl;
    return 0;

}
