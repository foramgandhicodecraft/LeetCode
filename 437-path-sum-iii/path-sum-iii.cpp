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
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int>m; // ordered map(default) has a greater time complexity as it sorts the keys on insertion
        m[0] = 1;
        int count = 0;
        dfs (root, targetSum, 0,&count,m);
        return count;
    }

    void dfs (TreeNode* root, int target, long long current_sum, int* count, unordered_map<long long, int>&m){

        if (!root)
          return;

        current_sum += root->val;

        if (m.find(current_sum - target) != m.end()){
            *count += m[current_sum - target];
        }

        m[current_sum]++;

        dfs(root->left, target, current_sum, count, m);
        dfs(root->right, target, current_sum, count, m);

        // backtrack the current_sum
        m[current_sum]--;
    }
};