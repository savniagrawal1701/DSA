#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    TreeNode *first, *prev, *middle, *last;

    void inorder(TreeNode* root) {
        if (root == NULL) return;

        inorder(root->left);

        if (prev != NULL && (root->val < prev->val)) {
            if (first == NULL) {
                first = prev;
                middle = root;
            } else {
                last = root;
            }
        }

        prev = root;
        inorder(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN); 
        
        inorder(root);

        if (first && last) swap(first->val, last->val);
        else if (first && middle) swap(first->val, middle->val);
    }
};

void printInorder(TreeNode* root) {
    if (root == NULL) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    Solution sol;

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);

    cout << "Before recovery: ";
    printInorder(root);
    cout << endl;

    sol.recoverTree(root);

    cout << "After recovery:  ";
    printInorder(root);
    cout << endl;

    return 0;
}