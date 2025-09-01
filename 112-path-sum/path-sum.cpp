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

    void dfs (vector<int>&paths, TreeNode* root, int sum){
        if (!root) return;
        
        sum += root->val;


        if (!root->left && !root->right){
            paths.push_back(sum);
        }

        dfs(paths, root->left, sum);
        dfs(paths, root->right, sum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        vector<int>paths;
        dfs(paths, root, 0);

        if (find(paths.begin(), paths.end(), targetSum) != paths.end()){
            return true;
        }

        return false;
       
    }
};