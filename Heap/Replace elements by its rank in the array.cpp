#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void rankUniqueElements(vector<int>& arr) {
    int n = arr.size();
    
    priority_queue<pair<int, int>> pq;

    
    for (int i = 0; i < n; i++) {
        pq.push({arr[i], i});
    }

    
    int currentRank = n;
    while (!pq.empty()) {
        pair<int, int> top = pq.top();
        pq.pop();

        int originalIndex = top.second;
        arr[originalIndex] = currentRank;
        
        currentRank--; 
    }
}

int main() {
    
    vector<int> arr = {20, 15, 26, 2, 98, 6};
    
    rankUniqueElements(arr);

    cout << "Ranked Array: ";
    for (int x : arr) {
        cout << x << " ";
    }
    
    
    return 0;
}
