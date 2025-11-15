#include <bits/stdc++.h>
using namespace std;
class solution
{
public:
    int lowerbound(vector<int> &v, int target)
    { 
        int n = v.size();
        int low = 0;
        int high = n - 1;
        int ans=n;
        while (low <= high)
        {
            int mid = low + (high-low) / 2;
            if (v[mid] >=target)
            {
               ans=mid;
               high=mid-1;
            }else{
                low=mid+1;
            }
            
        }
        return ans;
    }
     int upperbound(vector<int> &v, int target)
    { 
        int n = v.size();
        int low = 0;
        int high = n - 1;
        int ans=n;
        while (low <= high)
        {
            int mid = low + (high-low) / 2;
            if (v[mid] >target)
            {
               ans=mid;
               high=mid-1;
            }else{
                low=mid+1;
            }
            
        }
        return ans;
    }
    pair<int,int> firstlastposition(vector<int>& v,int target){
        int n=v.size();
        int lb=lowerbound(v,target);
        if(lb==n||v[lb]!=target)
        return {-1,-1};
        return {lb,upperbound(v,target)-1};
    }
};
int main() {
vector<int>v ={33,39,46,51,51,51,55,69,72,84};
	int n =v.size(), x = 51;
    solution s1;
	pair<int, int> ans = s1.firstlastposition(v,x);
	cout << "First and Last Occurence of a given number "<<ans.first<<" "<<ans.second<<endl;
	return 0;
}
