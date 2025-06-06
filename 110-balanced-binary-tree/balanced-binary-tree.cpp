/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int ans = balanced(root);
        if (ans == -1)
          return false;
        return true;
    }

private:
    int balanced (TreeNode* root){
        if (root == NULL)
          return 0;

        int lh = balanced(root->left);
        // if any subtree is unbalanced, the node will also be unbalanced
        if (lh == -1) return -1;
        int rh = balanced(root->right);
        if (rh == -1) return -1;

        if (abs(lh - rh) > 1)
          return -1;

        return 1+max(lh,rh);
    }
};