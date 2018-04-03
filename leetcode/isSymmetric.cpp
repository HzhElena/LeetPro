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
    bool isSymmetric(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!root) return true;
        return cmpTree(root->left, root->right);
    }
private:
    bool cmpTree(TreeNode *L, TreeNode *R) {
        if (!L || !R) return L==R;
        if (L->val != R->val) return false;
        return cmpTree(L->left, R->right) && cmpTree(L->right, R->left);
    }
};
