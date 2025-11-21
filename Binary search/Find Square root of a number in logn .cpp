#include <bits/stdc++.h>
using namespace std;
class solution
{
public:
    int squareroot(int N)
    {
        int low = 0;
        int high = N;
        int ans=0;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(mid*mid<=N){
          ans=mid;
          low=mid+1;
            }else{
                high=mid-1;
            }
            
        }
        return ans;
    }};
    int main()
{
    solution s1;
   
    int ans = s1.squareroot(104);
    cout << "Square root of the number is " << ans;
    return 0;
}
