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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        
        while (n != 0) {
            curr = curr->next;
            n--;
        }
        ListNode* front = head;
        ListNode* prev = NULL;
        
        if (!curr) return head->next;
        
        
        while (curr) {
            prev = front;
            front = front->next;
            curr = curr->next;
        }
        if (prev) {
            prev->next = front->next;
        }
        else {
            return prev;
        }
        return head;
    }
};