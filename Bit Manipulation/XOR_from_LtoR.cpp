#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int XORtillN(int n)
    {
        if (n % 4 == 1)
            return 1;
        if (n % 4 == 2)
            return n + 1;
        if (n % 4 == 3)
            return 0;
        return n;
    }
    int findRangeXOR(int l, int r)
    {
        return XORtillN(l - 1) ^ XORtillN(r);
    }
};
int main()
{
    int l=4;
    int r=7;
    Solution sol;

    int ans = sol.findRangeXOR(l,r);

    cout << "The XOR of numbers from " << l<<"to " <<r<< " is: " << ans;

    return 0;
}
