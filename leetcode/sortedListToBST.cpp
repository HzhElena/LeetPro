/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = 0;
        for (ListNode *cur=head; cur; ++n, cur=cur->next);
        next = head;
        return dfs(n);
    }
private:
    TreeNode *dfs(int n) {
        if (n == 0) return NULL;
        int mid = n / 2;
        TreeNode *L = dfs(mid);
        TreeNode *root = new TreeNode(next->val);
        next = next->next;
        root->left = L;
        root->right = dfs(n-mid-1);
        return root;
    }
    ListNode *next;
};

