#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) return new TreeNode(val);
        TreeNode* cur = root;
        while(true) {
            if(cur->val <= val) {
                if(cur->right != NULL) cur = cur->right;
                else {
                    cur->right = new TreeNode(val);
                    break;
                }
            } else {
                if(cur->left != NULL) cur = cur->left;
                else {
                    cur->left = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};


void inOrderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    inOrderTraversal(root->left);
    std::cout << root->val << " ";
    inOrderTraversal(root->right);
}

int main() {
    Solution sol;
    TreeNode* root = nullptr;

    root = sol.insertIntoBST(root, 4);
    sol.insertIntoBST(root, 2);
    sol.insertIntoBST(root, 7);
    sol.insertIntoBST(root, 1);
    sol.insertIntoBST(root, 3);
    sol.insertIntoBST(root, 6);
    sol.insertIntoBST(root, 9);
    sol.insertIntoBST(root, 5);

    
    std::cout << "BST In-order Traversal: ";
    inOrderTraversal(root);
    std::cout << std::endl;

    
    

    return 0;
}