#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
long long power(long long x, long n) {
     const int kMod = 1e9 + 7; 
    
        if (n == 0) return 1.0;

        if (n == 1) return x;

        if (n % 2 == 0) {
          
            return power(x * x, n / 2)  ;
        }
        return x* power(x, n - 1) ;
    }

    int countGoodNumbers(long long n) {
         const int kMod = 1e9 + 7; 
        long long evenPositions = (n + 1) / 2;
        long long oddPositions = n / 2;

        long long count5 = power(5, evenPositions) % kMod;
        long long count4 = power(4, oddPositions) % kMod;

        long long totalCount = (count5 * count4) % kMod;
        
        return (int)totalCount;
    }
    
};

int main() {
    Solution sol;
 
    cout<<"The total count of good numbers is :"<<sol.countGoodNumbers(4)<<endl;
   
    return 0;
}
