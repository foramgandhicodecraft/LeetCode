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
    bool isValidBST(TreeNode* root) {

        vector<int>inorder;
        construct(inorder, root);

        for (int i = 0; i < inorder.size()-1; i++){
            if (inorder[i] >= inorder[i+1]){
                return false;
            }
        }

        return true;
        
    }

    void construct(vector<int>&inorder, TreeNode* root){
        if (root == nullptr) return;

        construct(inorder, root->left);
        inorder.push_back(root->val);
        construct(inorder, root->right);
        //inorder.push_back(root->val);

    }
};