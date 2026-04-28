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
class Solution {
public:
    void solve(TreeNode* root, int i, vector<int>& result) {
        if(root == NULL) {
            return;
        }
        if(i == result.size()) result.push_back(root->val);

        solve(root->right, i+1, result);
        solve(root->left, i+1, result);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        solve(root, 0, result);
        return result;
    }
};