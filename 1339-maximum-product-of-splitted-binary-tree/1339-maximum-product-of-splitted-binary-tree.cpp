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

    long SUM = 0;
    long maxP = 0;

    int totalSum(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }

        int leftSum = totalSum(root->left);
        int rightSum = totalSum(root->right);
        long S1 = root->val + leftSum + rightSum;

        long S2 = SUM - S1;
        maxP = max(maxP, S1*S2);

        return S1;
    }

    int maxProduct(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }

        SUM = totalSum(root);

        totalSum(root);

        return maxP%1000000007;
    }
};