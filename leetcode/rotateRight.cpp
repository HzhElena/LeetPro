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
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!head) return NULL;
        int n = 0;
        for (ListNode *cur=head; cur; cur=cur->next) ++n;
        k %= n;
        if (k==0) return head;
        
        ListNode *a=head, *b=head;
        for (int i=0; i<k; ++i) b = b->next;
        while (b->next) {
            a = a->next;
            b = b->next;
        }
        b->next = head;
        head = a->next;
        a->next = NULL;
        return head;
    }
};
