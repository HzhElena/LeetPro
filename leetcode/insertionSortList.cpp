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
    ListNode *insertionSortList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        ListNode *cur = head;
        head = NULL;
        while (cur) {
            ListNode *next = cur->next, *prev = NULL;
            for (ListNode *p=head; p && (p->val < cur->val); p=p->next) prev = p;
            if (!prev) {
                cur->next = head;
                head = cur;
            }
            else {
                cur->next = prev->next;
                prev->next = cur;
            }            
            cur = next;
        }
        return head;
    }
};