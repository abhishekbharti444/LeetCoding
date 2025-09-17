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
    /*
    Approach Summary:
    1. Use DFS with memoization to clone each node exactly once
    2. Store original->clone mapping before processing neighbors to handle cycles
    3. For each neighbor, recursively clone and add to current clone's neighbor list
    4. Return existing clone if node already processed (prevents infinite recursion)
    */
    
    map<Node*, Node*> cloned; // Maps original node to its clone
    
    Node* util(Node* node) {
        if (!node) return nullptr;
        
        // Check if node already cloned to avoid cycles and duplicates
        if (cloned.contains(node)) return cloned[node];
        
        // Create clone with same value
        Node* new_node = new Node(node->val);
        
        // Store mapping BEFORE processing neighbors (crucial for cycle handling)
        cloned[node] = new_node;
        
        // Recursively clone all neighbors and add to clone's neighbor list
        for (auto& next: node->neighbors) {
            Node* new_next = util(next);
            new_node->neighbors.push_back(new_next);
        }
        
        return new_node;
    }
    
    Node* cloneGraph(Node* node) {
        return util(node);
    }
};
