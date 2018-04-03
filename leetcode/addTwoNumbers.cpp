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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *sum = NULL, *tail = NULL;
        int carry = 0;
        while (l1 || l2 || carry) {
            if (l1) { carry += l1->val; l1 = l1->next; }
            if (l2) { carry += l2->val; l2 = l2->next; }
            ListNode *cur = new ListNode(carry%10);
            if (tail) tail->next = cur; else sum = cur;
            tail = cur;
            carry /= 10;
        }
        return sum;
    }
};

