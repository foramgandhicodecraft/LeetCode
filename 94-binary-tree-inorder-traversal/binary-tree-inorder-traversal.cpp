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
    void inorder(TreeNode* p, vector<int>&ans){
         if (p != NULL){
            inorder(p->left, ans);
            ans.push_back(p->val);
            inorder(p->right, ans);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* p = root;
        vector<int>ans;
        inorder(p, ans);
        return ans;
    }
};