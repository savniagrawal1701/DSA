#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    
    unordered_map<int, int> countMap;
    for (int num : nums) {
        countMap[num]++;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for (auto it = countMap.begin(); it != countMap.end(); ++it) {
            minHeap.push({it->second, it->first});
            
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top().second);
        minHeap.pop();
    }

    return result;
}

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    vector<int> result = topKFrequent(nums, k);

    cout << "Top " << k << " most frequent elements: ";
    for (int x : result) {
        cout << x << " ";
    }
    
    
    return 0;
}
