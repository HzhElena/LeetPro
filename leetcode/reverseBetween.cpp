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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (m == n) return head;
        ListNode *pm = head, *prev = NULL;;
        for (int i=1; i<m; ++i) {
            prev = pm;
            pm = pm->next;
        }
        
        ListNode *pp = NULL, *pn = pm;
        for (int i=m; i<=n; ++i) {
            ListNode *next = pn->next;
            pn->next = pp;
            pp = pn;
            pn = next;
        }
        
        pm->next = pn;
        if (prev) prev->next = pp; else head = pp;
        return head;
    }
};

