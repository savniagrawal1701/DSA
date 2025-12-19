#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int numberofFlips(int start,int goal) {
        int ans=start^goal;
        int count=0;
        for(int i=0;i<31;i++){
            if(ans & (1<<i)) count=count+1;
        }
       return count;
    }
};

int main() {
    Solution sol;
      int start= 10; 
    int goal=7;
  
    cout<<"The number of flips required to convert "<<start<<"to "<<goal<<" is :"<<sol.numberofFlips(start,goal);

    return 0;
}