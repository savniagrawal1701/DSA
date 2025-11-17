
#include <bits/stdc++.h>
using namespace std;

bool search(vector<int>& arr, int n, int k) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;

       
        if (arr[mid] == k) return true;
if(arr[low]==arr[mid] && arr[mid]==arr[high]){
    low++;
    high--;
    continue;
}
        if (arr[low] <= arr[mid]) {
            if (arr[low] <= k && k <= arr[mid]) {
                
                high = mid - 1;
            }
            else {
         
                low = mid + 1;
            }
        }
        else { 
            if (arr[mid] <= k && k <= arr[high]) {
              
                low = mid + 1;
            }
            else {
         
                high = mid - 1;
            }
        }
    }
    return false;
}

int main()
{
    vector<int> arr = {3,3,1,2,3,3,3,3,3};
    int n = 9, k = 1;
    bool ans = search(arr, n, k);
    if (ans == false)
        cout << "Target is not present.\n";
    else
        cout << "Target is present"<<" "<<endl;
    return 0;
}