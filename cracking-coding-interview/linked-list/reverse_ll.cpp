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
    bool isPalindrome(ListNode* head) {
        std::vector<int> nor, rev;
        while(head != NULL) {
            nor.emplace_back(head->val);
            head = head->next;
        }
        rev = nor;
        std::reverse(rev.begin(), rev.end());
        for (int i = 0; i< rev.size(); i++) {
            if (rev[i] != nor[i]) {
                return false;
            }
        }
        return true;
    }
};