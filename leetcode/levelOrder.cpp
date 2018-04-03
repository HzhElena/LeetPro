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
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ans.clear();
        dfs(root, 0);
        return ans;
    }
private:
    vector<vector<int> > ans;
    void dfs(TreeNode *root, int lev) {
        if (!root) return;
        if (ans.size() <= lev) ans.push_back(vector<int>());
        ans[lev].push_back(root->val);
        dfs(root->left, lev+1);
        dfs(root->right, lev+1);
    }
};

