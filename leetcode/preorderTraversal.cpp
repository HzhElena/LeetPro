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
    vector<int> preorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> ans;
        if (!root) return ans;
        
        vector<TreeNode *> stk;
        stk.push_back(root);
        while (!stk.empty()) {
            TreeNode *cur = stk.back();
            stk.pop_back();
            ans.push_back(cur->val);
            if (cur->right) stk.push_back(cur->right);
            if (cur->left) stk.push_back(cur->left);
        }
        
        return ans;
    }
};
