/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *res;
        if (l1 == NULL && l2 != NULL) {
            return l2;
        }
        if (l1 != NULL && l2 == NULL) {
            return l1;
        }
        if (l1 == NULL && l2 == NULL) {
            return NULL;
        }
        if (l1->val > l2->val) {
             res = l2;
             l2 = l2->next;
        } else {
             res = l1;
             l1 = l1->next;
        }
        ListNode *start = res;
        while (l1 != NULL &&  l2!= NULL) {
            if (l1->val <= l2->val) {
                start->next = l1;
                start = start->next;
                l1 = l1->next;
            } else {
                start->next = l2;
                start = start->next;
                l2 = l2->next;
            }
        }
        if (l1 != NULL) {
            start->next = l1; 
        }
         if (l2 != NULL) {
            start->next = l2; 
        }
        return res;
    } 
};