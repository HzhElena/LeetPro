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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return dfs(num, 0, num.size()-1);
    }
private:
    TreeNode *dfs(vector<int> &num, int i, int j) {
        if (i > j) return NULL;
        int mid = (i+j)/2;
        TreeNode *root = new TreeNode(num[mid]);
        root->left = dfs(num, i, mid-1);
        root->right = dfs(num, mid+1, j);
        return root;
    }
};

