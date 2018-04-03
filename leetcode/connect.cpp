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
        dp(root);
    }
private:
    void dp(TreeLinkNode *root) {
        if (!root) return;
        
        root->next = next;
        
        while (next) {
            if (!next->left && !next->right) next = next->next;
            else {
                if (next->left) next = next->left; else next = next->right;
                break;
            }
        }
        
        dp(root->right);
        dp(root->left);
        next = root;
    }

    TreeLinkNode *next;
};

