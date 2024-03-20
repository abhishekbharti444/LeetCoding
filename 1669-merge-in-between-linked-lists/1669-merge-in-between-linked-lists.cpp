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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* prev = list1;
        ListNode* head = list1;
        while (a > 0 && head) {
            prev = head;
            head = head->next;
            a--;
        }
        
        head = list1;
        
        while (b > 0 && head) {
            head = head->next;
            b--;
        }
        ListNode* next_node = head ? head->next : NULL;
        
        ListNode* head2 = list2;
        ListNode* tail2 = list2;
        ListNode* dummy = list2;
        while (dummy) {
            tail2 = dummy;
            dummy = dummy->next;
        }
        
        prev->next = list2;
        tail2->next = next_node;
        return list1;
    }
};