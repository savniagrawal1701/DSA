#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<int> postOrder(Node *root)
{
    vector<int> postorder;

    if (root == NULL)
    {
        return postorder;
    }

    stack<Node *> st1, st2;
    st1.push(root);

    while (!st1.empty())
    {

        root = st1.top();
        st1.pop();

        st2.push(root);
        if (root->left != NULL)
        {
            st1.push(root->left);
        }

        if (root->right != NULL)
        {
            st1.push(root->right);
        }
    }
    while (!st2.empty())
    {
        postorder.push_back(st2.top()->data);
        st2.pop();
    }

    return postorder;
}
void printVector(const vector<int> &vec)
{

    for (int num : vec)
    {
        cout << num << " ";
    }
    cout << endl;
}

int main()
{

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> result = postOrder(root);
    cout << "Postorder traversal: ";
    printVector(result);

    return 0;
}