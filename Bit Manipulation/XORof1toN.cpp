#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int XORtillN(int n) {
        if(n % 4 == 1) return 1;
        if(n % 4 == 2) return n+1;
        if(n % 4 == 3) return 0;
        return n;
    }};
int main() {
 int n =8;
    Solution sol; 
    
    int ans = sol.XORtillN(n);
    
    cout << "The XOR of numbers from " << n<<" is: " << ans;
    
    return 0;
}