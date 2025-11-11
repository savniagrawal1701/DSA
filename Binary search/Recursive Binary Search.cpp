#include <bits/stdc++.h>
using namespace std;
class solution
{
public:
    int binarysearch(vector<int> &v,int low,int high, int target){
    if(low>high) return -1;
    int mid=low+high/2;
    if(v[mid]==target) return mid;
    else if(target>v[mid]) return binarysearch(v,mid+1,high,target);
    return binarysearch(v,low,high-1,target);

}};
int main()
{
    solution s1;
    vector<int> x = {2, 3, 4, 5, 6, 7, 9};
    int ans = s1.binarysearch(x, 0,x.size()-1,3);
    cout << "Index at which the target is present is: " << ans;
    return 0;
}
