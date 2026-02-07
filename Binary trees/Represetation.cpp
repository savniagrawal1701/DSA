
#include <iostream>
using namespace std;
class Node {
public:
    int data;      
    Node* left;    
    Node* right;   

    
    Node(int key) {
        data = key;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    Node* createBinaryTree() {
        Node* root = new Node(1);
        root->left = new Node(2);
        root->right = new Node(3);
        root->right->left = new Node(5);

        return root;
    }
};

int main() {
    Solution solution;
    Node* root = solution.createBinaryTree();

    
    return 0;
}