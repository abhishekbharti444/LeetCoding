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
    ListNode* reverseSecondHalf(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        
        while (curr) {
            ListNode* curr_next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = curr_next;
        }
        return prev;
    }
    ListNode* middle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    void reorderList(ListNode* head) {
        ListNode* mid = middle(head);
    
        // Notice here we are reversing the second half from the next of middle element. It works for both odd and even length LL. 
        ListNode* mid_next = reverseSecondHalf(mid->next);
        mid->next = NULL;
        ListNode* second = mid_next;
        ListNode* first = head;
        while (first && second) {
            ListNode* first_next = first->next;
            ListNode* second_next = second->next;
            first->next = second;
            second->next = first_next;
            first = first_next;
            second = second_next;   
        }   
    }
};