/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return head;
        Node* curr = head;
        Node* dummy = new Node(-1);
        Node* res = dummy;
        map<Node*, Node*> mp;
        while (curr) {
            Node* new_node = new Node(curr->val);
            mp[curr] = new_node;
            res->next = new_node;
            res = res->next;
            curr = curr->next;
        }
        mp[NULL] = NULL;
        curr = head;
        res = dummy->next;
        while (curr) {
            res->random = mp[curr->random];
            res = res->next;
            curr = curr->next;
        }
        return dummy->next;
    }
};