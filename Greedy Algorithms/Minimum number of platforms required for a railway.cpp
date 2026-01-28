#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
   int countPlatforms(int n, int arr[], int dep[]) {
        sort(arr, arr + n);
        sort(dep, dep + n);

        int platforms = 1;
        int result = 1;
        int i = 1, j = 0;

        while (i < n && j < n) {
            if (arr[i] <= dep[j]) {
                platforms++;
                i++;
            } else {
                platforms--;
                j++;
            }

            result = max(result, platforms);
        }
        return result;
    }
};

int main() {
    int arr[] = {2,4,6,8,1};
    int dep[] = {3,5,7,9,10};
    int n = sizeof(arr) / sizeof(arr[0]);
    Solution obj;
    cout << "Minimum number of Platforms required " 
         << obj.countPlatforms(n, arr, dep) << endl;

    return 0;

}
