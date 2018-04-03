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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ans.clear(); now.clear();
        dfs(root, sum);
        return ans;
    }
private:
    vector<vector<int> > ans;
    vector<int> now;
    void dfs(TreeNode *root, int sum) {
        if (!root) return;
        now.push_back(root->val);
        if (!root->left && !root->right) {
            if (sum == root->val) ans.push_back(now);
        }
        dfs(root->left, sum - root->val);
        dfs(root->right, sum - root->val);
        now.pop_back();
    }
};

