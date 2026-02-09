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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>inorder;
        inTraverse(root, inorder);
        return balanced_BST(inorder, 0, inorder.size()-1);
    }

    TreeNode* balanced_BST(vector<int>inorder, int low, int high){
        if (low > high) return nullptr;

        int mid = low + (high-low)/2;
        TreeNode* newNode = new TreeNode(inorder[mid]);
        newNode->left = balanced_BST(inorder, low, mid-1);
        newNode->right = balanced_BST(inorder, mid+1, high);
        return newNode;
    }

    void inTraverse(TreeNode* root, vector<int>&inorder){
        if (!root) return;

        inTraverse(root->left, inorder);
        inorder.push_back(root->val);
        inTraverse(root->right, inorder);
    }
};