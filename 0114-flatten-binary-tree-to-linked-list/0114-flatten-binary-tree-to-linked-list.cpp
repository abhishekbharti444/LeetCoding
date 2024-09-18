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
    
    /*
        Read the Approach 3 of the solution section. O(1) space solution. Morris Traversal.
        Very informative. Similar question has been asked in a Google interview.
        
    */
    void flatten(TreeNode* root) {

        if (!root) return;
        while (root) {
            TreeNode* curr = root->left;
            if (curr) {
                TreeNode* right_child = curr;
                // find the first right_child of the left subtree which doesn't have the right child further.
                while (right_child->right) {
                    right_child = right_child->right;
                }
                right_child->right = root->right;
                root->right = curr;
                root->left = NULL;
            }
            root = root->right;
        }
    }
};