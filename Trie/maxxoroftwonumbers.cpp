#include <bits/stdc++.h>
using namespace std;


class Node {
public:
    Node* links[2];

    
    bool containsKey(int bit) {
        return links[bit] != NULL;
    }

    
    Node* get(int bit) {
        return links[bit];
    }

    
    void put(int bit, Node* node) {
        links[bit] = node;
    }
};

class Solution {
public:
    Node* root;

    
    Solution() {
        root = new Node();
    }

    
    void insert(int num) {
        Node* node = root;
        for (int i = 31; i >= 0; i--) {
            
            int bit = (num >> i) & 1;

            
            if (!node->containsKey(bit)) {
                node->put(bit, new Node());
            }

            
            node = node->get(bit);
        }
    }

    
    int getMaxXOR(int num) {
        Node* node = root;
        int maxXor = 0;

        for (int i = 31; i >= 0; i--) {
            
            int bit = (num >> i) & 1;

            
            if (node->containsKey(1 - bit)) {
                maxXor |= (1 << i);
                node = node->get(1 - bit);
            } else {
                node = node->get(bit);
            }
        }

        return maxXor;
    }

    
    int findMaximumXOR(vector<int>& nums) {
        for (int num : nums) {
            insert(num);
        }

        int maxResult = 0;
        for (int num : nums) {
            maxResult = max(maxResult, getMaxXOR(num));
        }

        return maxResult;
    }
};


int main() {
    vector<int> nums = {3, 10, 5, 25, 2, 8};
    Solution sol;
    cout << sol.findMaximumXOR(nums) << endl;
    return 0;
}