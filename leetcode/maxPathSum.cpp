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
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret = INT_MIN;
        dp(root);
        return ret;
    }
private:
    int dp(TreeNode *root) {
        if (!root) return 0;
        int lsum = max(dp(root->left), 0);
        int rsum = max(dp(root->right), 0);
        ret = max(ret, lsum+rsum+root->val);
        return max(lsum, rsum) + root->val;
    }
    int ret;
};

