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
    ListNode *sortList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        return mergeSort(head);
    }
private:
    ListNode *mergeSort(ListNode *head) {
        if (!head || !head->next) return head;
        
        int n = 0;
        for (ListNode *cur=head; cur; cur=cur->next) ++n;
        
        ListNode *a = head, *b = head, *prev = NULL;
        n /= 2;
        for (int i=0; i<n; ++i) {
            prev = b;
            b = b->next;
        }
        prev->next = NULL;
        a = mergeSort(a);
        b = mergeSort(b);
        
        head = NULL;
        ListNode *tail = NULL;
        while (a || b) {
            ListNode *cur;
            if (!b || (a && (a->val <= b->val))) {
                cur = a; a = a->next;
            }
            else {
                cur = b; b = b->next;
            }
            if (tail) tail->next = cur; else head = cur;
            tail = cur;
        }
        
        return head;
    }
};