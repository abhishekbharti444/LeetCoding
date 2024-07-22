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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* res = new ListNode(-1);
        ListNode* curr = res;
        while (l1 && l2) {
            int sum = 0;
            if (l1) sum += l1->val;
            if (l2) sum += l2->val;
            sum += carry;
            if (sum >= 10) {
                carry = 1;
                sum = sum % 10;
            }
            else carry = 0;
            
            l1 = l1->next;
            l2 = l2->next;
            curr->next = new ListNode(sum);
            curr = curr->next;
        }
        
        while (l1) {
            int sum = 0;
            sum += l1->val;
            sum += carry;
            if (sum >= 10) {
                carry = 1;
                sum = sum % 10;
            }
            else carry = 0;
            l1 = l1->next;
            curr->next = new ListNode(sum);
            curr = curr->next;
        }
        while (l2) {
            int sum = 0;
            sum += l2->val;
            sum += carry;
            if (sum >= 10) {
                carry = 1;
                sum = sum % 10;
            }
            else carry = 0;
            l2 = l2->next;
            curr->next = new ListNode(sum);
            curr = curr->next;
        }
        
        if (carry == 1) {
            curr->next = new ListNode(1);
            curr = curr->next;
        }
        curr->next = NULL;
        return res->next;
        
        
    }
};