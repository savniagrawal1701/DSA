#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        val = data;
        left = right = nullptr;
    }
};

class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int target)
    {
        while (root != nullptr && root->val != target)
        {
            if (target < root->val)
            {
                root = root->left;
            }

            else
            {
                root = root->right;
            }
        }
        return root;
    }
};

int main()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution obj;
    TreeNode *result = obj.searchBST(root, 2);

    if (result)
        cout << "Node found: " << result->val << endl;
    else
        cout << "Node not found" << endl;

    return 0;
}
