#include <iostream>
#include <vector>
#include <queue>
#include <numeric>

using namespace std;

long long connectnRopes(vector<int>& ropes) {
    
    
    priority_queue<int, vector<int>, greater<int>> min_heap;

    
    for (int length : ropes) {
        min_heap.push(length);
    }

    long long total_cost = 0;

    
    while (min_heap.size() > 1) {
        
        int first = min_heap.top();
        min_heap.pop();

        int second = min_heap.top();
        min_heap.pop();

        
        int current_cost = first + second;
        total_cost += current_cost;

        
        min_heap.push(current_cost);
    }

    return total_cost;
}

int main() {
    vector<int> ropeLengths = {1,2,3,4,5};

    long long minCost = connectnRopes(ropeLengths);

    cout << "Total minimum cost to connect ropes: " << minCost << endl;

    return 0;
}