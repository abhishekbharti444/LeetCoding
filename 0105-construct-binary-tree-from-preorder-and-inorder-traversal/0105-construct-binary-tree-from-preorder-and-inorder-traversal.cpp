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
    vector<int> pre, in;
    unordered_map<int, int> mp;
    TreeNode* util(int left_pre, int right_pre, int left_in, int right_in) {
        if (left_pre > right_pre || left_in > right_in) return NULL;
        
        TreeNode* root = new TreeNode(pre[left_pre]);
        
        int index_in = mp[root->val];
        int len_left = index_in - left_in;
        root->left = util(left_pre + 1, left_pre + len_left, left_in, left_in + len_left - 1);
        root->right = util(left_pre + len_left + 1, right_pre, left_in + len_left + 1, right_in);
        return root;
        
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        pre = preorder;
        in = inorder;
        int n = in.size();
        for (int i = 0; i < n; ++i) mp[in[i]] = i;
        return util(0, n-1, 0, n-1);
    }
};