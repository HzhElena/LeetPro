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
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        prev = a = b = NULL;
        inorder(root);
        if (a && b) swap(a->val, b->val);
    }
private:
    TreeNode *prev, *a, *b;
    void inorder(TreeNode *root) {
        if (!root) return;
        inorder(root->left);
        if (prev && (prev->val > root->val)) {
            if (!a) a = prev; 
            b = root;
        }
        prev = root;
        inorder(root->right);
    }
};
