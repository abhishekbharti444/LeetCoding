/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "! ";
        
        // Notice here there wouldn't be an extra space needed as this would be handled by calling left side as in case of null it would return "@ ", this extra space would fill the space for the right side tree.
        return to_string(root->val) + " " + serialize(root->left) + serialize(root->right);
    }

    TreeNode* util(stringstream& str) {
        string curr;
        
        // dump current tokenized string from str to curr
        str>>curr;
        
        // If it reaches the delimiter, return null
        if (curr == "!") return NULL;
        
        // Else create a new node with int value of curr, and find the left, right and point them to root
        int val = stoi(curr);
        TreeNode* root = new TreeNode(val);
        root->left = util(str);
        root->right = util(str);
        return root;
        
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        // Stream would help you to convert strings into tokenized integers easily
        stringstream str(data);
        return util(str);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));