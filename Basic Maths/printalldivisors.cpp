#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    vector<int> getDivisors(int N) {
        
        vector<int> res;

        
        for (int i = 1; i * i <= N; i++) {
            
            if (N % i == 0) {
                
                res.push_back(i);

                
                if (i != N / i) {
                    res.push_back(N / i);
                }
            }
        }

        
        return res;
    }
};

int main() {
    
    Solution sol;

    
    int N = 36;

    
    vector<int> result = sol.getDivisors(N);

    
    cout << "Divisors of " << N << ": ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;}