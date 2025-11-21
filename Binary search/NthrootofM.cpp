#include <bits/stdc++.h>
using namespace std;
class solution
{
public:
int function(int mid ,int n,int m){
    long long ans=1;
    for(int i=1;i<=n;i++){
        ans=ans*mid;
        if(ans>m) return 2;

    }
    if(ans==m) return 1;
    return 0;
}
int Nthroot(int n ,int m){
    int low=1;
    int high=m;
    while(low<=high){
        int mid=low+(high-low)/2;
        int midn=function(mid,n,m);
        if(midn==1){
            return mid;
        }
        else if(midn==0) low=mid+1;
        else high=mid-1;
    }
    return -1;
}
};
int main()
{

    solution obj;
    int ans = obj.Nthroot(4,16);
    cout << "The ans is :" << ans << endl;

    return 0;
}