#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        if (hand.size() % groupSize != 0)
            return false;

        unordered_map<int, int> countMap;
        for (int card : hand)
            countMap[card]++;

        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (auto const &x : countMap)
        {

            minHeap.push(x.first);
        }

        while (!minHeap.empty())
        {
            int first = minHeap.top();
            if (countMap[first] == 0)
            {
                minHeap.pop();
                continue;
            }

            for (int i = 0; i < groupSize; i++)
            {
                int current = first + i;
                if (countMap[current] == 0)
                    return false;
                countMap[current]--;
            }
        }
        return true;
    }
};
int main()
{
    Solution sol;

    vector<int> hand1 = {1, 2, 3, 6, 2, 3, 4, 7, 8};
    int groupSize1 = 3;
    cout << sol.isNStraightHand(hand1, groupSize1) << endl;

    return 0;
}
