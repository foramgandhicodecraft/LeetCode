/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        int prev = INT_MIN;
        vector<int>arr;
        inorder(root, arr);

        for (int i = 1; i < arr.size(); i++){
            if (arr[i] <= arr[i-1])
             return false;
        }

        return true;
    }

    void inorder(TreeNode* root, vector<int>&arr) {
        if (root) {

            inorder(root->left, arr);

            arr.push_back(root->val);

            inorder(root->right, arr);
        }

    }
};