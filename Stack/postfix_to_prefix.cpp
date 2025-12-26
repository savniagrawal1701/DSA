#include <bits/stdc++.h>
using namespace std;

string postfixToprefix(string postfix)
{
    stack<string> s;
    int n = postfix.size();

    for (int i =0;i<n;i++)
    {
        char c = postfix[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            {
                s.push(string(1, c));
            }
        else
        {

            string top1 = s.top();
            s.pop();
            string top2 = s.top();
            s.pop();

            s.push(c+top2+top1);
        }
    }

    return s.top();
}

int main()
{
    string postfix = "AB-DE+F*/";
    cout << "Prefix Expression: " << postfixToprefix(postfix) << endl;
    return 0;
}