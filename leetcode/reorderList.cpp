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
    void reorderList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (!head) return;
        
        int n = 0;
        for (ListNode *cur=head; cur; cur=cur->next) ++n;
        n -= n/2;
        ListNode *prev = head;
        for (int i=1; i<n; ++i)  prev = prev->next;
        ListNode *second = prev->next;
        prev->next = NULL;
        
        second = listReverse(second);
        ListNode *first = head, *tail = NULL;
        head = NULL;
        while (first || second) {
            if (first) {
                if (tail) tail->next = first; else head = first;
                tail = first;
                first = first->next;
            }
            if (second) {
                if (tail) tail->next = second; else head = second;
                tail = second;
                second = second->next;
            }
        }
    }
private:
    ListNode *listReverse(ListNode *head) {
        ListNode *prev = NULL;
        while (head) {
            ListNode *next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};

