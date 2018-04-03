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
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        dfs(root);
    }
private:
    TreeNode *dfs(TreeNode *root) {
        if (!root) return NULL;
        TreeNode *left_tail = dfs(root->left);
        TreeNode *right_tail = dfs(root->right);
        if (left_tail) {
            left_tail->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
        if (right_tail) return right_tail;
        if (left_tail) return left_tail;
        return root;
    }
};

