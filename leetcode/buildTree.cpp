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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return dfs(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
private:
    TreeNode *dfs(vector<int> &pOrder, vector<int> &iOrder, int lp, int rp, int li, int ri) {
        for (int i=li; i<=ri; ++i)
            if (pOrder[lp] == iOrder[i]) {
                TreeNode *root = new TreeNode(pOrder[lp]);
                root->left = dfs(pOrder, iOrder, lp+1, lp+i-li, li, i-1);
                root->right = dfs(pOrder, iOrder, lp+i-li+1, rp, i+1, ri);
                return root;
            }
        return NULL;
    }
};

