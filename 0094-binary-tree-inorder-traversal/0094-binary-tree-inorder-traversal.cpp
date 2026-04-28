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
// void inorder(TreeNode* root, vector<int>& pre) {
//     if (root == NULL)
//         return;

//     inorder(root->left, pre);
//     pre.push_back(root->val);
//     inorder(root->right, pre);
// }

// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> inorder;

//         if (root == NULL)
//             return inorder;

//         stack<TreeNode*> st;
//         TreeNode* node = root;

//         while (true) {
//             if (node != NULL) {
//                 st.push(node);
//                 node = node->left;
//             } else {
//                 if (st.empty() == true)
//                     break;
//                 node = st.top();
//                 st.pop();
//                 inorder.push_back(node->val);
//                 node = node->right;
//             }
//         }

//         return inorder;
//     }
// };


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
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
                    curr = curr->left;
                } else {
                    prev->right = NULL; //reset thread
                    inorder.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }

        return inorder;
    }
};