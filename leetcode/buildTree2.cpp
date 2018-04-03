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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return dfs(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }
private:
    TreeNode *dfs(vector<int> &ord, vector<int> &prd, int oi, int oj, int pi, int pj) {
        for (int k=oi; k<=oj; ++k) if (ord[k] == prd[pj]) {
            TreeNode *root = new TreeNode(prd[pj]);
            root->left = dfs(ord, prd, oi, k-1, pi, pi+k-oi-1);
            root->right = dfs(ord, prd, k+1, oj, pi+k-oi, pj-1);
            return root;
        }
        return NULL;
    }
};

