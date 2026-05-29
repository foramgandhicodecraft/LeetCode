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
    vector<int> rightSideView(TreeNode* root) {
        //vector<int>ans;
        vector<int>ds;
        calculate(root, ds, 0);
        return ds;
    }

    void calculate(TreeNode* root, vector<int>&ds, int level){
        if (root == nullptr){
            return;
        }

        if (level == ds.size()){
            ds.push_back(root->val);
        }

        calculate(root->right, ds, level+1);
        calculate(root->left, ds, level+1);
    }
};