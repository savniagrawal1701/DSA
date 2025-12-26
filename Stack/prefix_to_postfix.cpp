#include <bits/stdc++.h>
using namespace std;

string prefixTopostfix(string prefix)
{
    stack<string> s;
    int n = prefix.size();

    for (int i = n-1; i>=0; i--)
    {
        char c = prefix[i];

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

            s.push(top1 + top2 +c);
        }
    }

    return s.top();
}

int main()
{
    string prefix = "/-AB*+DEF";
    cout << "Postfix Expression: " << prefixTopostfix(prefix) << endl;
    return 0;
}