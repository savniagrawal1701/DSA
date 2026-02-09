#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
class Solution
{
public:
    vector<vector<int>> preInPostTraversal(Node *root)
    {

        vector<int> pre, in, post;
        if (root == NULL)
        {
            return {};
        }
        stack<pair<Node *, int>> st;
        st.push({root, 1});

        while (!st.empty())
        {
            auto it = st.top();
            st.pop();
            if (it.second == 1)
            {
                pre.push_back(it.first->data);
                it.second = 2;

                st.push(it);
                if (it.first->left != NULL)
                {
                    st.push({it.first->left, 1});
                }
            }
            else if (it.second == 2)
            {

                in.push_back(it.first->data);
                it.second = 3;

                st.push(it);
                if (it.first->right != NULL)
                {
                    st.push({it.first->right, 1});
                }
            }

            else
            {
                post.push_back(it.first->data);
            }
        }
        vector<vector<int>> result;
        result.push_back(pre);
        result.push_back(in);
        result.push_back(post);
        return result;
    }
};
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    Solution sol;

    vector<int> pre, in, post;
    vector<vector<int>> traversals = sol.preInPostTraversal(root);
    pre = traversals[0];
    in = traversals[1];
    post = traversals[2];
    cout << "Preorder traversal: ";
    for (int val : pre)
    {
        cout << val << " ";
    }
    cout << endl;

    cout << "Inorder traversal: ";
    for (int val : in)
    {
        cout << val << " ";
    }
    cout << endl;

    cout << "Postorder traversal: ";
    for (int val : post)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}