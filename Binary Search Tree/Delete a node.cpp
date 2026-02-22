#include<bits/stdc++.h>
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

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) {
            return NULL;
        }

        if (root->val == key) {
            return helper(root);
        }

        TreeNode* dummy = root;
        while (root != NULL) {
            if (root->val > key) {
                if (root->left != NULL && root->left->val == key) {
                    root->left = helper(root->left);
                    break;
                } else {
                    root = root->left;
                }
            } else {
                if (root->right != NULL && root->right->val == key) {
                    root->right = helper(root->right);
                    break;
                } else {
                    root = root->right;
                }
            }
        }
        return dummy;
    }

    TreeNode* helper(TreeNode* root) {
        if (root->left == NULL) {
            return root->right;
        } else if (root->right == NULL) {
            return root->left;
        }

        TreeNode* rightChild = root->right;
        TreeNode* lastRight = findLastRight(root->left);
        lastRight->right = rightChild;
        return root->left;
    }

    TreeNode* findLastRight(TreeNode* root) {
        if (root->right == NULL) {
            return root;
        }
        return findLastRight(root->right);
    }
};
void printInorder(TreeNode* node) {
    if (node == NULL) return;
    printInorder(node->left);
    cout << node->val << " ";
    printInorder(node->right);
}
int main() {
    Solution sol;

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    cout << "Original Tree (Inorder): ";
    printInorder(root);
    cout << endl;

    int keyToDelete = 3;
    root = sol.deleteNode(root, keyToDelete);

    cout << "After deleting " << keyToDelete << " (Inorder): ";
    printInorder(root);
    cout << endl;

    return 0;
}

