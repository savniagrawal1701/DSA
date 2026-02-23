#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p)
    {
        TreeNode *successor = nullptr;
        while (root != nullptr)
        {
            if (p->val >= root->val)
            {
                root = root->right;
            }
            else
            {
                successor = root;
                root = root->left;
            }
        }
        return successor;
    }
};

void printInOrder(TreeNode *root)
{

    if (root == nullptr)
        return;

    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

int main()
{

    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    cout << "BST: ";
    printInOrder(root);
    cout << endl;

    TreeNode *p = root->left->right;

    Solution solution;
    TreeNode *successor = solution.inorderSuccessor(root, p);

    if (successor != nullptr)
    {
        cout << "Inorder Successor of " << p->val << " is: " << successor->val << endl;
    }
    else
    {
        cout << "Inorder Successor of " << p->val << " does not exist." << endl;
    }

    return 0;
}