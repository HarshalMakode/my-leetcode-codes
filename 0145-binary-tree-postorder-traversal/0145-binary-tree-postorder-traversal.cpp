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

void postorder(TreeNode* root, vector<int>& pre) {
    if (root == NULL)
        return;

    postorder(root->left, pre);
    postorder(root->right, pre);
    pre.push_back(root->val);
}

// class Solution {
// public:
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> postorder;
//         if (root == NULL)
//             return postorder;

//         stack<TreeNode*> st1, st2;
//         st1.push(root);

//         while (!st1.empty()) {
//             TreeNode* node = st1.top();
//             st1.pop();
//             st2.push(node);

//             if (node->left != NULL)
//                 st1.push(node->left);

//             if (node->right != NULL)
//                 st1.push(node->right);
//         }

//         while (!st2.empty()) {
//             postorder.push_back(st2.top()->val);
//             st2.pop();
//         }

//         return postorder;
//     }
// };

// class Solution {
// public:
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> postorder;
//         if (root == NULL)
//             return postorder;

//         stack<TreeNode*> st1, st2;
//         st1.push(root);

//         while (!st1.empty()) {
//             TreeNode* node = st1.top();
//             st1.pop();
//             st2.push(node);

//             if (node->left != NULL)
//                 st1.push(node->left);

//             if (node->right != NULL)
//                 st1.push(node->right);
//         }

//         while (!st2.empty()) {
//             postorder.push_back(st2.top()->val);
//             st2.pop();
//         }

//         return postorder;
//     }
// };


class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        if (root == NULL)
            return postorder;

        stack<TreeNode*> st;
        TreeNode* curr = root;

        while (curr != NULL || !st.empty()) {
            if(curr != NULL) {
                st.push(curr);
                curr = curr->left;
            } else {
                TreeNode* temp = st.top()->right;
                
                if(temp == NULL) {
                    temp = st.top();
                    st.pop();
                    postorder.push_back(temp->val);
                    while (!st.empty() && temp == st.top()->right) {
                        temp = st.top();
                        st.pop();
                        postorder.push_back(temp->val);
                    }
                } else {
                    curr = temp;
                }
            }
        }

        return postorder;
    }
};