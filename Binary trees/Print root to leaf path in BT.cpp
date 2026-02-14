#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
public:
    
    bool getPath(TreeNode* root, vector<int>& arr, int x) {
        
        if (!root) {
            return false;
        }
        arr.push_back(root->val);
        if (root->val == x) {
            return true;
        }
        if (getPath(root->left, arr, x) ||
            getPath(root->right, arr, x)) {
            return true;
        }
        arr.pop_back();
        return false;
    }
    vector<int> solve(TreeNode* A, int B) {
        vector<int> arr;
        if (A == NULL) {
            return arr;
        }
        getPath(A, arr, B);
        return arr;
    }
};
int main() {
    
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    Solution sol;
    int targetLeafValue = 7;
    vector<int> path = sol.solve(root, targetLeafValue);
    cout << "Path from root to node with value ";
    cout << targetLeafValue << ": ";

    for (int i = 0; i < path.size(); ++i) {
        cout << path[i];
        if (i < path.size() - 1) {
            cout << " -> ";
        }
    }

    return 0;

}
