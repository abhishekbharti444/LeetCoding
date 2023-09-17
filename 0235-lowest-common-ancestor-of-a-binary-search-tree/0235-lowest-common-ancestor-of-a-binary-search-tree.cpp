/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* util(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return root;
        if (root == p || root == q) return root;
        TreeNode* left = util(root->left, p, q);
        TreeNode* right = util(root->right, p, q);
        if (left && right) return root;
        if (left) return left;
        if (right) return right;
        return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return util(root, p, q);
    }
};