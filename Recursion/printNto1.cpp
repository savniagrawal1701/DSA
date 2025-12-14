#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
 
    void print1toN( int count, int N) {
        
        if (count< 1)
            return;

        cout << count << "\n";

        print1toN( count - 1, N);
    }
};

int main() {
    Solution sol;
    int N = 5;
    

    sol.print1toN( N, N);

    return 0;
}