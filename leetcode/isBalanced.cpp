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
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return getDepth(root) != -1;
    }
private:
    int getDepth(TreeNode *root) {
        if (!root) return 0;
        int L = getDepth(root->left);
        int R = getDepth(root->right);
        if ((L==-1)||(R==-1)||(L>R+1)||(R>L+1)) return -1;
        return max(L, R) + 1;
    }
};

