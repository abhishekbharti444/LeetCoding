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
    int res = 1;
    void util(TreeNode* root, int curr_max) {
        if (!root) return;
        
        if (root->val >= curr_max) res++;
        util(root->left, max(curr_max, root->val));
        util(root->right, max(curr_max, root->val));
    } 
    int goodNodes(TreeNode* root) {
        if (!root) return 0;
        util(root->left, root->val);
        util(root->right, root->val);
        return res;
    }
};