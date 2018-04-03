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
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (k <= 1) return head;
        
        ListNode *cur = head, *prev = NULL;
        while (cur) {
            ListNode *end = cur;
            for (int i=1; i<k; ++i) if (end) end = end->next;
            if (!end) break;
            
            ListNode *pp = end->next, *begin = cur;
            for (int i=0; i<k; ++i) {
                ListNode *next = cur->next;
                cur->next = pp;
                pp = cur;
                cur = next;
            }
            
            if (prev) prev->next = end; else head = end;
            prev = begin;
        }
        
        return head;
    }
};
