#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
 
    void printName(string name, int count, int N) {
        
        if (count == N)
            return;

        cout << name << "\n";

        printName(name, count + 1, N);
    }
};

int main() {
    Solution sol;
    int N = 5;
    string name = "Savni";

    sol.printName(name, 0, N);

    return 0;
}