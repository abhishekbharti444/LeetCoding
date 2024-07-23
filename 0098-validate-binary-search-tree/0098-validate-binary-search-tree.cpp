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
    const long long MAX = 2147489647;
    const long long MIN = -2147489648;
    bool util(TreeNode* root, long long min_val, long long max_val) {
        if (!root) return true;
        
        if (root->val <= min_val || root->val >= max_val) return false;
        
        return util(root->left, min_val, root->val) && util(root->right, root->val, max_val);
    }
    bool isValidBST(TreeNode* root) {

        return util(root, MIN, MAX);
    }
};