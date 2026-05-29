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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        return preorder(ans, root);
    }

    vector<int> preorder(vector<int>&ans, TreeNode* root){
        if (root != nullptr){
            ans.push_back(root->val);
            preorder(ans, root->left);
            preorder(ans, root->right);
        }

        return ans;
    }
};