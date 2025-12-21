#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sieve(int n) {
        vector<int> prime(n+1,1); //a vector till n+1 with all values 1 
        if (n <= 1) return 0;
        prime[0] = prime[1] = 0;

        for (int i = 2; i * i <= n; i++) {
            if (prime[i] == 1) {
            
                for (int j = i * i; j <= n; j += i) {
                    prime[j] = 0;
                }
            }
        }
        for (int i = 2; i <= n; i++) {
            if (prime[i] == 1) cout << i << " ";
        }
    }
};

int main() {
    int n;
    cout << "Enter the value of N: ";
    cin >> n;

    Solution sol;
    sol.sieve(n);

    return 0;
}