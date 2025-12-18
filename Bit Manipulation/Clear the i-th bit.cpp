#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int CLEARithBIT(int n, int i) {
        
        return (n &(~ (1 << i))); 
    }
};

int main() {
    Solution sol;
    int num = 13; 
    int bitIndex = 2;  

   cout<<"The number obtained by clearing the "<<bitIndex<<"th bit is "<<sol.CLEARithBIT(num,bitIndex);

    return 0;
}
