#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int removetheRIGHTMOSTsetbit(int n) {
        
        return (n & (n-1)); 
    }
};

int main() {
    Solution sol;
    int num = 13; 
    cout<<"The number obtained by removing the rightmost set bit is "<<sol.removetheRIGHTMOSTsetbit(num);

    return 0;
}