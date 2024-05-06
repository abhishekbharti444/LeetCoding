/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        stack<int> st;
        ListNode* curr = head;
        while (curr) {
            while (!st.empty() && st.top() < curr->val) {
                st.pop();
            }
            st.push(curr->val);
            curr = curr->next;
        }
        ListNode* prev = NULL;
        while (st.size() > 0) {
            ListNode* new_head = new ListNode(st.top());
            new_head->next = prev;
            st.pop();
            prev = new_head;
        }
        return prev;
    }
};