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
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 0;
        // node, index
        queue<pair<TreeNode*, long long>>q;
        q.push({root, 0});
        int min = 0;

        while (!q.empty()){
            int size = q.size();
            //min index in the level
            long long min = q.front().second;
            int last;
            int first;

            for (int i = 0; i < size; i++){
                if (i == 0)  first = q.front().second;
                if (i == size-1)  last = q.front().second;
                TreeNode* node = q.front().first;
                long long curr_index = q.front().second-min;
                q.pop();
                if (node->left){
                    q.push({node->left, curr_index*2+1});
                }
                if (node->right){
                    q.push({node->right, curr_index*2+2});
                }
            }
            ans = max(ans, last-first+1);
        }

        return ans;
    }
};