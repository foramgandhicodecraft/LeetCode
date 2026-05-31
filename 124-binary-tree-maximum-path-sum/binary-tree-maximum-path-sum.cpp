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
    int maxPathSum(TreeNode* root) {
        if (root == nullptr){
            return 0;
        }
        int max_sum = INT_MIN;
        calc(root, max_sum);
        return max_sum;
    }

    int calc(TreeNode* root, int& max_sum){
        if (root == nullptr){
            return 0;
        }
        int lh = max(0, calc(root->left, max_sum));
        int rh = max(0, calc(root->right, max_sum));

        int sum = root->val + lh + rh;
        max_sum = max(sum, max_sum);

        return root->val + max(lh,rh);
    }
};