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
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *cur = head, *prev = NULL;
        while (cur && cur->next) {
            if (cur->val == cur->next->val) {
                int val = cur->val;
                while (cur && (cur->val == val)) {
                    ListNode *dup = cur;
                    cur = cur->next;
                    delete dup;
                }
                if (prev) prev->next = cur; else head = cur;
            }
            else {
                prev = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};

