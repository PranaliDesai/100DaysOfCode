#include <iostream>


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *list = NULL;

        list = weave_two(l1, l2, 0);
        return list; 
    }
    ListNode* weave_two(ListNode* l1, ListNode* l2, bool carry) {
        int sum = 0;
        int first = 0;
        int second = 0;
        ListNode *temp_l1 = NULL;
        ListNode *temp_l2 = NULL;
        if ((l1 == NULL && l2 == NULL)) {
            if (carry == false) {
            return NULL;
            }
        }
        if (l1 != NULL) {
            first = l1->val;
            if (l1->next != NULL) {
                temp_l1 = l1->next;
            } 
        }
        if (l2 != NULL) {
            second = l2->val;
            if (l2->next != NULL) {
                temp_l2 = l2->next;
            }
        }
        if (carry == true) {
            sum = first + second + 1;
        } else {
            sum = first + second;
        }
      
        ListNode *list = NULL;
        if  (sum > 9) {
            carry = true;
            list = new ListNode(sum%10);
        } else {
            carry = false;
            cout << sum << "\n";
            list = new ListNode(sum);
        }
        ListNode *temp = NULL;
        if (l1 != NULL || l2!= NULL) {
            temp = weave_two(temp_l1, temp_l2, carry);
        }
        list->next = temp;
        return list;
    }
};