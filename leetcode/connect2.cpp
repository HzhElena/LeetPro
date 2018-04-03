/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        next = NULL;
        dfs(root);
    }
private:
    void dfs(TreeLinkNode *root) {
        if (!root) return;
        root->next = next;
        while (next) {
            if (next->left || next->right) {
                if (next->left) next = next->left; else next = next->right;
                break;
            }
            next = next->next;
        }
        dfs(root->right);
        dfs(root->left);
        next = root;
    }
    TreeLinkNode *next;
};

