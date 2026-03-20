
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
vector<int> inorder(TreeNode* root){
    
    stack<TreeNode*> st;
    
    TreeNode* node = root;
    vector<int> inorder;
    while(true){
        
        if(node != NULL){
  
            st.push(node);
            node = node->left;
        }
        else{
 
            if(st.empty()){
                break;
            }
            
            node = st.top();
            
            st.pop();
            
            inorder.push_back(node->data);
            node = node->right;
        }
    }
    
    return inorder;
}

};

int main() {
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    vector<int> result = sol.inorder(root);
    cout << "Inorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
