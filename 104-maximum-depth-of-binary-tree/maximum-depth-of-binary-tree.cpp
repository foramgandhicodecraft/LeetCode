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
    int maxDepth(TreeNode* root) {
        if (root == NULL)
          return 0;
        int depth = 0;
        int max_depth = 0;
        int ans = dfs(root, depth);
        return ans+1;
    }

private:
    int max_depth = 0;
    int dfs(TreeNode* root, int depth){
        if (root!=NULL){
        dfs(root->left, depth+1);
        max_depth = max(max_depth, depth);}
        if (root != NULL){
        dfs(root->right, depth+1);
        max_depth = max(max_depth, depth);}

        return max_depth;
    }
};