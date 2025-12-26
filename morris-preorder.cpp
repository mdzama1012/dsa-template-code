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

    // morris preorder traversal - O(1) space
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;

        TreeNode* curr = root;
        while (curr != nullptr) {
            if (curr->left) {
                TreeNode* rightMost = curr->left;
                while (rightMost->right != nullptr &&
                       rightMost->right != curr) {
                    rightMost = rightMost->right;
                }
                if (rightMost->right == curr) {
                    rightMost->right = nullptr;
                    curr = curr->right;
                } else {
                    ans.push_back(curr->val);
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
