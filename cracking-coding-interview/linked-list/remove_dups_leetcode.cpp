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
    ListNode* deleteDuplicates(ListNode* head) {
        // The idea is to map all the sorted list
        // and then iterate over the map to create another LL.
        if (head == NULL) {
            return NULL;
        }
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *temp = head;
        while (fast != NULL) {
            if (fast->val == slow->val) {
                fast = fast->next;
            } else {
                cout << slow->val << fast->val << "\n";
                slow->next = fast;
                slow = slow->next;

                fast = fast->next;
            }
        }
        slow->next = NULL;
        slow = temp;
        return slow;
    }
};