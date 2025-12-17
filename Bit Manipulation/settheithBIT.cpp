#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int SETithBIT(int n, int i) {
        
        return (n | (1 << i)); 
    }
};

int main() {
    Solution sol;
    int num = 13; 
    int bitIndex = 1;  

   cout<<"The number obtained by setting the "<<bitIndex<<"th bit is "<<sol.SETithBIT(num,bitIndex);

    return 0;
}