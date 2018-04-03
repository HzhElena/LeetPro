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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ans.clear();
        dp(root, 0);
        for (int i=0; i<ans.size(); ++i) if (i&1) reverse(ans[i].begin(), ans[i].end());
        return ans;
    }
private:
    void dp(TreeNode *root, int k) {
        if (!root) return;
        if (ans.size() <= k) ans.push_back(vector<int>());
        ans[k].push_back(root->val);
        dp(root->left, k+1);
        dp(root->right, k+1);
    }

    vector<vector<int> > ans;
};

