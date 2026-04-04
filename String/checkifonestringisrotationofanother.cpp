#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    bool rotateString(string& s, string& goal) {
        
        if (s.length() != goal.length()) return false;
        
        
        string doubledS = s + s;
        return doubledS.find(goal) != string::npos;
    }
};

int main() {
    Solution sol;

    string s = "rotation";
    string goal = "tionrota";
    cout << (sol.rotateString(s, goal) ? "true" : "false") << endl;

    return 0;
}