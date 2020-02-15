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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *second = head;
        ListNode *first = head;
        ListNode *temp = first;
        while (n != 0) {
            second = second->next;
            n--;
        }
        if (second == NULL) {
            first = first->next;
            return first;
        }
        
        while (second->next != NULL) {
            second = second->next;
            first = first->next;
        }
        first->next = first->next->next;
        // cout << first->val;
        first = temp;
        return first;
    }
};