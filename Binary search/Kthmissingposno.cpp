#include <bits/stdc++.h>
using namespace std;
class solution
{
public:
    int missingK(vector<int> &v, int k)
    {
        int n = v.size();
        int low = 0;
        int high = n - 1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int missing=v[mid]-(mid+1);
            if(missing<k) low=mid+1;
            else high=mid-1;

        }
        return low+k;
    }
};
int main() {
    vector<int> vec = {4, 7, 9, 10}; 
    int n = vec.size();            
    solution s1;         
    int ans = s1.missingK(vec,7); 

    cout << "The missing number is: " << ans << "\n"; 
    return 0;
}