#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (!root) return {};
        unordered_map<TreeNode*, TreeNode*> parentMap;
        mapParentNodes(root, parentMap);

        
        return bfsFromTarget(target, parentMap, k);
    }

private:
    
    void mapParentNodes(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parentMap) {
        queue<TreeNode*> q;
        q.push(root);

        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) {
                parentMap[node->left] = node;
                q.push(node->left);
            }

            if (node->right) {
                parentMap[node->right] = node;
                q.push(node->right);
            }
        }
    }
    vector<int> bfsFromTarget(TreeNode* target, unordered_map<TreeNode*, TreeNode*>& parentMap, int k) {
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited; 
        q.push(target);
        visited.insert(target);

        int currentLevel = 0;

        while (!q.empty()) {
            int size = q.size();

            
            if (currentLevel++ == k) break;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left && visited.find(node->left) == visited.end()) {
                    visited.insert(node->left);
                    q.push(node->left);
                }
                if (node->right && visited.find(node->right) == visited.end()) {
                    visited.insert(node->right);
                    q.push(node->right);
                }
                if (parentMap.count(node) && visited.find(parentMap[node]) == visited.end()) {
                    visited.insert(parentMap[node]);
                    q.push(parentMap[node]);
                }
            }
        }
        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front()->val);
            q.pop();
        }

        return result;
    }
};

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    TreeNode* target = root->left;
    int k = 2;

    Solution sol;
    vector<int> result = sol.distanceK(root, target, k);

    for (int val : result) {
        cout << val << " ";
    }

    return 0;
}