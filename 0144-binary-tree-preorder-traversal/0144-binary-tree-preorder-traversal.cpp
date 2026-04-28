/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
// void preorder(TreeNode* root, vector<int>& pre) {
//     if(root == NULL) return;

//     pre.push_back(root->val);
//     preorder(root->left, pre);
//     preorder(root->right, pre);
// }

// class Solution {
// public:
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> pre;
//         preorder(root, pre);
//         return pre;
//     }
// };

// class Solution {
// public:
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> preorder;

//         if (root == NULL)
//             return preorder;

//         stack<TreeNode*> st;
//         st.push(root);

//         while (!st.empty()) {
//             TreeNode* node = st.top();
//             st.pop();

//             preorder.push_back(node->val);

//             if (node->right != NULL) {
//                 st.push(node->right);
//             }

//             if (node->left != NULL) {
//                 st.push(node->left);
//             }
//         }

//         return preorder;
//     }
// };


class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> inorder;

        if (root == NULL)
            return inorder;

        TreeNode* curr = root;

        while (curr != NULL) {
            if (curr->left == NULL) {
                inorder.push_back(curr->val);
                curr = curr->right;
            } else {
                TreeNode* prev = curr->left;
                while(prev->right && prev->right != curr) {
                    prev = prev->right;
                }
                if(prev->right == NULL) {
                    prev->right = curr; //thread
                    inorder.push_back(curr->val);
                    curr = curr->left;
                } else {
                    prev->right = NULL; //reset thread
                    curr = curr->right;
                }
            }
        }

        return inorder;
    }
};