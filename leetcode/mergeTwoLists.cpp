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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        ListNode *head = NULL, *tail = NULL;
        while (l1 || l2) {
            ListNode *cur;
            if (l1 && (!l2 || (l1->val <= l2->val))) {
                cur = l1; l1 = l1->next;
            }
            else {
                cur = l2; l2 = l2->next;
            }
            cur->next = NULL;
            if (tail) tail->next = cur; else head = cur;
            tail = cur;
        }
        return head;
    }
};

