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
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *prev = NULL, *cur = head;
        while (cur && cur->next) {
            ListNode *a = cur, *b = cur->next;
            if (prev) prev->next = b; else head = b;
            a->next = b->next;
            b->next = a;
            prev = a; 
            cur = a->next;
        }
        return head;
    }
};

