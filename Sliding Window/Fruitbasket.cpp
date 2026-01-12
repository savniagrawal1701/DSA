#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int longestSubarrayAtMostK(vector<int>& arr, int k) {
    int n = arr.size();
    int l = 0, r = 0, maxlen = 0;
    unordered_map<int, int> mpp;

    while (r < n) {
        mpp[arr[r]]++;

        if (mpp.size() > k) {
            mpp[arr[l]]--;
            if (mpp[arr[l]] == 0) {
                mpp.erase(arr[l]);
            }
            l++;
        }

        if (mpp.size() <= k) {
            maxlen = max(maxlen, r - l + 1);
        }

        r++;
    }
    return maxlen;
}

int main() {
    vector<int> nums = {3,3,3,1,2,1,1,2,3,3,4};
    int k = 2;
    cout << longestSubarrayAtMostK(nums, k) << endl;
    return 0;
}