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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int>inorderIdx;

        for (int i = 0; i < inorder.size(); i++){
            inorderIdx[inorder[i]] = i;
        }

        return f(inorderIdx, 0, inorder.size()-1, 0, postorder.size()-1, inorder, postorder);
    }

    TreeNode* f(unordered_map<int, int>&inorderIdx, int is, int ie, int ps, int pe, vector<int>& inorder, vector<int>& postorder) {
        if (is > ie || ps > pe){
            return nullptr;
        }

        int value = postorder[pe];
        TreeNode* root = new TreeNode(value);
        int inorderRoot = inorderIdx[value];

        int numsLeft = inorderRoot - is;

        root->left = f(inorderIdx, is, inorderRoot-1, ps, ps+numsLeft-1, inorder, postorder);
        root->right = f(inorderIdx, inorderRoot+1, ie, ps+numsLeft, pe-1, inorder, postorder);

        return root;
    }
};