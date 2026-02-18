#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
    {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};
void inorder(TreeNode *root)
{
    if (!root)
    {
        return;
    }
    inorder(root->left);

    cout << root->val << " ";

    inorder(root->right);
}

class Solution
{
public:
    string serialize(TreeNode *root)
    {
        if (!root)
        {
            return "";
        }

        string s = "";

        queue<TreeNode *> q;

        q.push(root);

        while (!q.empty())
        {
            TreeNode *curNode = q.front();
            q.pop();

            if (curNode == nullptr)
            {
                s += "#,";
            }
            else
            {
                s += to_string(curNode->val) + ",";
                q.push(curNode->left);
                q.push(curNode->right);
            }
        }
        return s;
    }
    TreeNode *deserialize(string data)
    {

        if (data.empty())
        {
            return nullptr;
        }

        stringstream s(data);
        string str;

        getline(s, str, ',');

        TreeNode *root = new TreeNode(stoi(str));

        queue<TreeNode *> q;

        q.push(root);

        while (!q.empty())
        {

            TreeNode *node = q.front();
            q.pop();

            getline(s, str, ',');

            if (str != "#")
            {
                TreeNode *leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }

            getline(s, str, ',');

            if (str != "#")
            {
                TreeNode *rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }

        return root;
    }
};

int main()
{

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Solution solution;

    cout << "Orignal Tree: ";
    inorder(root);
    cout << endl;

    string serialized = solution.serialize(root);
    cout << "Serialized: " << serialized << endl;

    TreeNode *deserialized = solution.deserialize(serialized);

    cout << "Tree after deserialisation: ";
    inorder(deserialized);
    cout << endl;

    return 0;
}
