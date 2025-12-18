#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int TOGGLEithBIT(int n, int i) {
        
        return (n ^ (1 << i)); 
    }
};

int main() {
    Solution sol;
    int num = 13; 
    int bitIndex = 1;  

   cout<<"The number obtained by Toggle the "<<bitIndex<<"th bit is "<<sol.TOGGLEithBIT(num,bitIndex);

    return 0;
}