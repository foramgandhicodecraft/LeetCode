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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (inorder.size() != preorder.size()){
            return nullptr;
        }

        unordered_map<int, int>inorderIdx;
        int ie = inorder.size()-1;
        int pe = preorder.size()-1;

        for (int i = 0; i < inorder.size(); i++){
            inorderIdx[inorder[i]] = i;
        }

        return f(inorderIdx, 0, ie, 0, pe, preorder, inorder);
    }

    TreeNode* f(unordered_map<int, int>&inorderIdx, int is, int ie, int ps, int pe,vector<int>& preorder, vector<int>&inorder){
        if (is > ie || ps > pe) return nullptr;

        int value = preorder[ps];
        TreeNode* root = new TreeNode(value);

        int inorderRoot = inorderIdx[value];
        int numsLeft = inorderRoot - is;

        root->left = f(inorderIdx, is, inorderRoot-1, ps+1, ps+numsLeft, preorder, inorder);
        root->right = f(inorderIdx, inorderRoot+1, ie, ps+numsLeft+1, pe, preorder, inorder);

        return root;

    }
};