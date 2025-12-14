#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
 
    int funcsum(int N) {
        
        if (N==0)
            return 0;
       return N+funcsum(N-1);
    }
};

int main() {
    Solution sol;
 
    cout<<"The sum is:"<<sol.funcsum(3)<<endl;
   
    return 0;

}
