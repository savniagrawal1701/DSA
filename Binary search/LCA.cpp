#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left, *right;

    Node(int value)
    {
        data = value;
        left = right = nullptr;
    }
};

Node *lowestCommonAncestor(Node *root, int n1, int n2)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if (root->data > n1 && root->data > n2)
    {
        return lowestCommonAncestor(root->left, n1, n2);
    }
    if (root->data < n1 && root->data < n2)
    {
        return lowestCommonAncestor(root->right, n1, n2);
    }
    return root;
}

Node *insert(Node *root, int data)
{
    if (root == nullptr)
    {
        return new Node(data);
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    return root;
}

int main()
{
    Node *root = nullptr;

    root = insert(root, 20);
    insert(root, 8);
    insert(root, 22);
    insert(root, 4);
    insert(root, 12);
    insert(root, 10);
    insert(root, 14);

    int n1 = 10, n2 = 14;
    Node *lca_node = lowestCommonAncestor(root, n1, n2);
    cout << "LCA of " << n1 << " and " << n2 << " is: " << lca_node->data << endl;

    return 0;
}
