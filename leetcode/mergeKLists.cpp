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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        set<pair<int, ListNode *> > pq;
        int n = lists.size();
        for (int i=0; i<n; ++i) 
            if (lists[i]) pq.insert(make_pair(lists[i]->val, lists[i]));
        ListNode *head = NULL, *tail = NULL;
        while (!pq.empty()) {
            int val = pq.begin()->first;
            ListNode *lst = pq.begin()->second;
            pq.erase(pq.begin());
            if (lst->next) pq.insert(make_pair(lst->next->val, lst->next));
            
            ListNode *cur = new ListNode(val);
            if (tail) tail->next = cur; else head = cur;
            tail = cur;
        }
        return head;
    }
};

