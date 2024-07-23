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
    int res = 0;
    
    int util(TreeNode* root) {
        if (!root) return 0;
        int left = util(root->left);
        int right = util(root->right);
        res = max(res, left + right + 1);
        
        return max(left, right) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        util(root);
        return res - 1;
    }
};