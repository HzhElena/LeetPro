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
    vector<TreeNode *> generateTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return dp(1, n);
    }
private:
    vector<TreeNode *>dp(int lo, int hi) {
        vector<TreeNode *> trees;
        if (lo > hi) {
            trees.push_back(NULL);
            return trees;
        }
        
        for (int mid = lo; mid<=hi; ++mid) {
            vector<TreeNode *> left = dp(lo, mid-1);
            vector<TreeNode *> right = dp(mid+1, hi);
            
            for (int i=0; i<left.size(); ++i) for (int j=0; j<right.size(); ++j) {
                TreeNode *root = new TreeNode(mid);
                root->left = left[i];
                root->right = right[j];
                trees.push_back(root);
            }
        }
        
        return trees;
    }
};

