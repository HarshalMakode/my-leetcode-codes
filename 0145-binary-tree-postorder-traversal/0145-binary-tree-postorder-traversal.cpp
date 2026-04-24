/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

void postorder(TreeNode* root, vector<int>& pre) {
    if(root == NULL) return;
    
    postorder(root->left, pre);
    postorder(root->right, pre);
    pre.push_back(root->val);
}

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> pre;
        postorder(root, pre);
        return pre;
    }
};