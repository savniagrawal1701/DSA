#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
     
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int studentIndex = 0; 
        int cookieIndex = 0;  

        while (studentIndex < g.size() && cookieIndex < s.size()) {
            if (s[cookieIndex] >= g[studentIndex]) {
                studentIndex++; 
            }

            cookieIndex++; 
        }

        return studentIndex;
    }
};
  
int main() {
    vector<int> student = {1, 2, 3,4,3,1,8,2,1};
    vector<int> cookie = {1, 1,2,5,2};

    Solution solver;

    
    int result = solver.findContentChildren(student, cookie);
    cout << "Maximum number of content students: " << result << endl;

    return 0;
}
