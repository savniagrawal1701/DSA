#include <bits/stdc++.h>
using namespace std;
class solution
{
public:
int countPainters(vector<int>& arr ,int pages){
    long long pagestudent =0;
    int students=1;
    for(int i =0;i<arr.size();i++){
        if(pagestudent+arr[i]<=pages){
            pagestudent+=arr[i];
        }
        else{
            students+=1;
            pagestudent=arr[i];
        }
    }
    return students;
}
int findLargestMinDistance(vector<int>& arr, int n, int m) {
    //book allocation impossible:
    if (m > n) return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while (low <= high) {
        int mid = (low + high) / 2;
        int students = countPainters(arr, mid);
        if (students > m) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return low;
}
};
int main()
{
    vector<int> arr = {25, 46, 28, 49, 24};
    int n=arr.size();
    solution s1;
    int ans=s1.findLargestMinDistance(arr,n,4);
    cout << "The answer is: " << ans << "\n";
    return 0;
}
