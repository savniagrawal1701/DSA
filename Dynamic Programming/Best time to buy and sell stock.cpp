#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to calculate maximum profit using single pass
    int stockbuySell(vector<int>& prices) {
        // Initialize the minimum price to a large number
        int minPrice = INT_MAX;

        // Initialize the maximum profit to 0
        int maxProfit = 0;

        // Traverse each price in the array
        for (int price : prices) {
            // If current price is less than minPrice, update minPrice
            if (price < minPrice) {
                minPrice = price;
            }
            // Else calculate profit and update maxProfit if it's greater
            else {
                maxProfit = max(maxProfit, price - minPrice);
            }
        }

        // Return the maximum profit found
        return maxProfit;
    }
};

// Driver code
int main() {
    Solution obj;
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    cout << obj.stockbuySell(prices) << endl;

    return 0;
}
