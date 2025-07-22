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
    int i = 0;

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return f (preorder, INT_MIN, INT_MAX);
    }

    TreeNode* f (vector<int>& preorder, int lower, int upper){

        if (i >= preorder.size()) return nullptr;

        int val = preorder[i];

        if (val < lower || val > upper) return nullptr;

        TreeNode* root = new TreeNode(val);
        i++;

        root->left = f (preorder, lower, val);
        root->right = f (preorder, val, upper);

        return root;
    }
};