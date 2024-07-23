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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int k = q.size();
            bool flag = true;
            for (int i = 0; i < k; ++i) {
                TreeNode* front = q.front();
                q.pop();
                if (flag) {
                    res.push_back(front->val);
                    flag = false;
                }

                if (front->right) q.push(front->right);
                if (front->left) q.push(front->left);
            }
        }
        return res;
    }
};