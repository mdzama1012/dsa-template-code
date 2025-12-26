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

class Solution {
public:
    // morris inorder traversal - O(1) space
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;

        TreeNode* curr = root;
        while (curr) {
            if (curr->left) {
                TreeNode* rightMost = curr->left;
                while (rightMost->right &&
                       rightMost->right != curr) {
                    rightMost = rightMost->right;
                }
                if (rightMost->right == curr) {
                    rightMost->right = nullptr;
                    ans.push_back(curr->val);
                    curr = curr->right;
                } else {
                    rightMost->right = curr;
                    curr = curr->left;
                }
            } else {
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }

        return ans;
    }
};
