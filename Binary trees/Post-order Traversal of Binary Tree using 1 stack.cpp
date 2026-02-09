#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;  
    Node* left;  
    Node* right;  
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
vector<int> postOrder(Node* root) {
    if (root == NULL)
        return {};
    Node* curr = root;
    stack<Node*> st;  
    vector<int> postorder;  
    while (curr != NULL || !st.empty()) {
        
        if (curr != NULL) {
            st.push(curr);
            curr = curr->left;
        } else {
            Node* temp = st.top()->right;
            if (temp == NULL) {
                
                temp = st.top();
                st.pop();
                postorder.push_back(temp->data);
                while (!st.empty() && temp == st.top()->right) {
                    temp = st.top();
                    st.pop();
                    postorder.push_back(temp->data);
                }
            } else {
                
                curr = temp;
            }
        }
    } 
    return postorder;
}
void printVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    vector<int> result = postOrder(root);
    cout << "Postorder traversal: ";
    printVector(result);

    return 0;
}
