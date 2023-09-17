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
    TreeNode* util(TreeNode* root) {
        if (!root) return root;
        TreeNode* left = util(root->left);
        TreeNode* right = util(root->right);
        root->left = right;
        root->right = left;
        return root;
    }
    TreeNode* invertTree(TreeNode* root) {
        return util(root);
    }
};