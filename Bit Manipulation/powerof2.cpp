#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool power_of_2(int n)
    {
        if (n>0 && (n & (n - 1)) == 0)
            return true;
        else
            return false;
    }
};

int main()
{
    Solution sol;
    int num = 13;

    cout << "The number " << num << "is power of 2 :" << sol.power_of_2(num);

    return 0;
}