#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minJumps(vector<int>& arr) {
    int n = arr.size();
    if (n <= 1) return 0;

    int jumps = 0, l = 0, r = 0;

    while (r < n - 1) {
        int farthest = 0;
    
        for (int ind = l; ind <= r; ind++) {
            farthest = max(ind + arr[ind], farthest);
        }
  
        l = r + 1;
        r = farthest;
        jumps = jumps + 1;
   
        if (l > r) return -1; 
    }
    return jumps;
}

int main() {
    vector<int> arr = {2, 3, 1, 1, 4};
    cout << "Minimum jumps: " << minJumps(arr) << endl;
    return 0;

}
