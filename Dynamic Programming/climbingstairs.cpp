#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int climbStairs(int n)
    {

        if (n == 1)
            return 1;

        int prev2 = 1;

        int prev = 1;

        int curr;

        for (int i = 2; i <= n; i++)
        {

            curr = prev + prev2;

            prev2 = prev;

            prev = curr;
        }

        return curr;
    }
};
int main(){
    int n;
    cout<<"Tell us the number of stairs ";
    cin>>n;
    Solution s;
    int ans=s.climbStairs(n);
    cout<<"Number of ways are "<<ans;
    return 0;

}