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
    int maxi = 0;

    int height(TreeNode* root) {
        if(root == NULL) return 0;
        int l = height(root->left);
        int r = height(root->right);
        return 1 + max(l,r);
    }

    void diameter(TreeNode* root) {
        if(root == NULL) return;

        int l = height(root->left);
        int r = height(root->right);

        maxi = max(maxi, l + r);

        diameter(root->left);
        diameter(root->right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        diameter(root);
        return maxi;
    }
};