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
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *les=NULL, *lesTail = NULL;
        ListNode *geq=NULL, *geqTail = NULL;
        while (head) {
            ListNode *cur = head;
            head = head->next;
            cur->next = NULL;
            
            if (cur->val < x) {
                if (lesTail) lesTail->next = cur; else les = cur;
                lesTail = cur;
            }
            else {
                if (geqTail) geqTail->next = cur; else geq = cur;
                geqTail = cur;
            }
        }
        if (!lesTail) return geq;
        lesTail->next = geq;
        return les;
    }
};

