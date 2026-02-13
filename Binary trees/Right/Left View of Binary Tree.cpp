#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(NULL), right(NULL) {}
};

class Solution {
public:
    
    void leftDFS(TreeNode* node, int level, vector<int>& res) {
        
        if (!node) return;
        if (res.size() == level)
            res.push_back(node->val);
        leftDFS(node->left, level + 1, res);
        leftDFS(node->right, level + 1, res);
    }
    void rightDFS(TreeNode* node, int level, vector<int>& res) {
        if (!node) return;

        if (res.size() == level)
            res.push_back(node->val);
        rightDFS(node->right, level + 1, res);
        rightDFS(node->left, level + 1, res);
    }

    vector<int> leftView(TreeNode* root) {
        vector<int> res;
        leftDFS(root, 0, res);
        return res;
    }
    vector<int> rightView(TreeNode* root) {
        vector<int> res;
        rightDFS(root, 0, res);
        return res;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->left->right->right = new TreeNode(5);
    root->left->right->right->right = new TreeNode(6);

    Solution sol;
    vector<int> left = sol.leftView(root);
    vector<int> right = sol.rightView(root);

    cout << "Left View: ";
    for (int val : left) cout << val << " ";
    cout << "\nRight View: ";
    for (int val : right) cout << val << " ";
    return 0;
}
