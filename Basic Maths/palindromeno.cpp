#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
int reverse(int x) {
       long revNum = 0;
     long num=x;
      if(x>=INT_MAX) return 0;
             if(x<=INT_MIN) return 0;
        while (num != 0) {
        
            int lastDigit = num % 10;

            revNum = revNum * 10 + lastDigit;

            num = num/ 10;
        }
                 if(revNum>=INT_MAX) return 0;
             if(revNum<=INT_MIN) return 0;
    return (int)revNum;
    }
    bool isPalindrome(int x) {
        if(x<0) return false;
        int a=reverse(x);
        if(x==a) return true ;
        return false;
    }
};
int main(){
    int n ;
    cin>>n;
    Solution s1;
    cout<<s1.isPalindrome(n);
    return 0;
}