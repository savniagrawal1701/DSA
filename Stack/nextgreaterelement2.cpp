#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> nextGreaterElements(vector<int> arr) {
        
        int n = arr.size(); 
        vector<int> ans(n);
        
        stack<int> st;
       for(int i = 2*n-1; i >= 0; i--) {
              int ind = i % n;
           
            int currEle = arr[ind];

            while(!st.empty() && st.top() <= currEle) {
                st.pop();
            }
            
            if(i < n) {
                
                if(st.empty()) 
                    ans[i] = -1;
                    
                
                else 
                    ans[i] = st.top();
            }
        
            st.push(currEle);
        }
        
        return ans;
    }
};

int main() {
    int n = 6;
    vector<int> arr = {5, 7, 1, 7, 6, 0};
 
    Solution sol; 
 
    vector<int> ans = sol.nextGreaterElements(arr);
    
    cout << "The next greater elements are: ";
    for(int i=0; i < n; i++) {
        cout << ans[i] << " ";
    }
    
    return 0;
}