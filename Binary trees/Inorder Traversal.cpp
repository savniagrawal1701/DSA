
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
 
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution{
    private:
    void recursiveInorder(TreeNode* root, vector<int> &arr){
        if(root == nullptr){
            return;
        }
        recursiveInorder(root->left, arr);
    
        arr.push_back(root->data);
    
        recursiveInorder(root->right, arr);
    }
    
    public:
    vector<int> inorder(TreeNode* root){ 
        vector<int> arr;
        
        recursiveInorder(root, arr);
        return arr;
    }
};


int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    Solution sol = Solution();
    
    vector<int> result = sol.inorder(root);
    cout << "Inorder Traversal: ";
    
    
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
