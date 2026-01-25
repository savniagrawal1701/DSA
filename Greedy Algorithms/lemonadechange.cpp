#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int count5 = 0;
        int count10 = 0;
        int count20 = 0;

        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5) {
                count5++;
            } 
            else if (bills[i] == 10) {
                if (count5 <= 0) return false; // Early exit if no $5 available
                count10++;
                count5--;
            } 
            else { // bill is 20
                count20++;
                // Greedy Choice: Use a $10 and a $5 first to save $5 bills
                if (count10 >= 1 && count5 >= 1) {
                    count10--;
                    count5--;
                } 
                else if (count5 >= 3) {
                    count5 -= 3;
                } 
                else {
                    return false; // Cannot make change
                }
            }
        }
        return true;
    }
};


int main() {
    Solution sol;

    vector<int> case1 = {5, 5, 5, 10, 20};
    cout << "Test Case 1 {5, 5, 5, 10, 20}: " << (sol.lemonadeChange(case1) ? "Passed" : "Failed") << endl;

    return 0;
}