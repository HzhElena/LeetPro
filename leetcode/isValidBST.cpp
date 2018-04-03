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
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return dfs(root, INT_MIN, INT_MAX);
    }
private:
    bool dfs(TreeNode *root, int lo, int hi) {
        if (!root) return true;
        if ((root->val<=lo)||(root->val>=hi)) return false;
        return dfs(root->left, lo, root->val) && dfs(root->right, root->val, hi);
    }
};

