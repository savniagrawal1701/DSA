#include <bits/stdc++.h>
using namespace std;
class solution
{
public:
int noofD(vector<int>& weight,int capacity){
    int days=1;
    int load=0;
    for(int i =0;i<weight.size();i++){
        if(load+weight[i]>capacity){
            days=days+1;
            load=weight[i];
        }else{
            load+=weight[i];
        }
    }
    return days;

}
int leastcapacity(vector<int>& weight,int d){
    int low = *max_element(weight.begin(), weight.end());
    int high = accumulate(weight.begin(), weight.end(), 0);
    int ans=0;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(noofD(weight,mid)<=d){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return ans;
}
};

int main()
{
    vector<int> weights = {5, 4, 5, 2, 3, 4, 5, 6};
  solution s1;
    int ans = s1.leastcapacity(weights,5);
    cout << "The minimum capacity should be: " << ans << "\n";
    return 0;
}
