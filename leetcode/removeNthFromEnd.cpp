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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!head) return NULL;
        ListNode *pn = head;
        for (int i=0; i<n; ++i) pn = pn->next;
        if (!pn) return head->next;
        
        ListNode *p = head;
        while (pn->next) {
            p = p->next;
            pn = pn->next;
        }
        p->next = p->next->next;
        return head;
    }
};

