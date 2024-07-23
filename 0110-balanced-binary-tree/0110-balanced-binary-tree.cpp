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
    bool res = true;
    int util(TreeNode* root) {
        if (!root) return 0;
        int left_height = util(root->left);
        int right_height = util(root->right);
        if (abs(left_height - right_height) > 1) res = false; 
        return 1 + max(left_height, right_height);
    }
    
    bool isBalanced(TreeNode* root) {
        util(root);
        return res;
    }
};