#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
 
    int factorial(int N) {
        
        if (N==0||N==1)
            return 1;
       return N*factorial(N-1);
    }
};

int main() {
    Solution sol;
 
    cout<<"The sum is:"<<sol.factorial(6)<<endl;
   
    return 0;
}