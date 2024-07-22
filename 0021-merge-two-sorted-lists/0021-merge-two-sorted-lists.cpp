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
    ListNode* addNew(ListNode* head, ListNode* target) {
        ListNode* node = new ListNode(target->val);
        head->next = node;
        head = head->next;
        return head;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* first = list1;
        ListNode* second = list2;
        ListNode* res = new ListNode(-1);
        ListNode* head = res;
        while (first && second) {
            if (first->val < second->val) {
                head = addNew(head, first);
                first = first->next;
            }
            else {
                head = addNew(head, second);
                second = second->next;
            }
        }
        
        while (first) {
            head = addNew(head, first);
            first = first->next;
        }
        
        while (second) {
            head = addNew(head, second);
            second = second->next;
        }
        return res->next;
    }
};