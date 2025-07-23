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
        if (preorder.size() != inorder.size()) return nullptr;

        map<int, int>inorderInx;

        for (int i = 0; i < inorder.size(); i++){
            inorderInx[inorder[i]] = i;
        }

        return f (inorderInx, 0, inorder.size()-1, 0, preorder.size()-1, inorder, preorder);
    }

    TreeNode* f (map<int, int>&inorderInx, int ins, int ine, int ps, int pe, vector<int>& inorder, vector<int>& preorder){
        if (ins > ine || ps > pe) return nullptr;

        int val = preorder[ps];

        TreeNode* root = new TreeNode(val);

        int inRoot = inorderInx[val];
        int numsLeft = inRoot - ins;

        root->left = f (inorderInx, ins, inRoot-1, ps+1, ps+numsLeft, inorder, preorder);
        root->right = f (inorderInx, inRoot+1, ine, ps+numsLeft+1, pe, inorder, preorder);

        return root;
    }
};