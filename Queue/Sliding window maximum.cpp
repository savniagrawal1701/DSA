#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to return the max of each sliding window of size k
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // Deque to store indices of useful elements in the current window
        deque<int> dq;

        // Result vector to store the maximums
        vector<int> result;

        // Loop through each element in the array
        for (int i = 0; i < nums.size(); i++) {
            // Remove elements from the front if they are out of this window's range
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Remove all elements from the back that are smaller than current element
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            // Add the current index to the deque
            dq.push_back(i);

            // Once the first window is completed, add front element to result
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }

        // Return the final result
        return result;
    }
};

// Driver code
int main() {
    Solution obj;

    vector<int> arr = {4, 0, -1, 3, 5, 3, 6, 8};
    int k = 3;

    vector<int> ans = obj.maxSlidingWindow(arr, k);

    // Print the result
    for (int num : ans) {
        cout << num << " ";
    }

    return 0;

}
