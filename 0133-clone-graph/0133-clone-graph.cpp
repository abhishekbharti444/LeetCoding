/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    map<Node*, Node*> mp;
    
//     void util(Node* node) {
//         if (!node) return;
//         for (auto& a : node->neighbors) {
//             mp[a] = node;
//             util(a);
//         }
//     }
    
    Node* formGraph(Node* node) {
        if (!node) return node;
        if (mp.find(node) != mp.end()) return mp[node];
        Node* root = new Node(node->val);
        mp[node] = root;
        for (int i = 0; i < node->neighbors.size(); ++i) {
            root->neighbors.push_back(formGraph(node->neighbors[i]));
        }
        return root;
    }
    Node* cloneGraph(Node* node) {
        return formGraph(node);
        // if (!node) return NULL;
        // Node* root = new Node(node->val);
        // for (int i = 0; i < node.neighbors.size(); ++i) {
        //     root->neighbors[i] = 
        // }
        // return root;
    }
};