#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
   
    int maxScore(vector<int>& cardPoints, int k) {
     
        int n = cardPoints.size();
      int lsum=0;
      int rsum=0;
      int maxsum=0;
        for (int i = 0; i < k; ++i) {
           lsum=lsum+cardPoints[i];
           maxsum=lsum;
        }
       
       int rindex=n-1;
        for (int i = k-1; i >=0; i--) {
           lsum=lsum-cardPoints[i];
           rsum=rsum+cardPoints[rindex];
           rindex=rindex-1;
           maxsum=max(maxsum,lsum+rsum);

        }

        return maxsum;
    }
};

int main() {
   
    vector<int> cards = {6,2,3,4,7,2,1,7,1};
    int k = 4;

    Solution sol;

    cout << sol.maxScore(cards, k) << endl;

    return 0;
}
