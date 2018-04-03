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
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        ListNode *phead = NULL, *ptail = NULL;
        while (head) {
            if (!head->next || (head->val!=head->next->val)) {
                ListNode *cur = new ListNode(head->val);
                if (ptail) ptail->next = cur; else phead = cur;
                ptail = cur;
            }
            head = head->next;
        }
        return phead;
    }
};

