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
        if (inorder.size() != postorder.size()) return nullptr;

        map<int, int> inorderInx;

        for (int i = 0; i < inorder.size(); i++){
            inorderInx[inorder[i]] = i;
        }

        return f (0, inorder.size()-1, inorderInx, 0, postorder.size()-1, inorder, postorder);

    }

private:
    TreeNode* f (int ins, int ine, map<int, int> &inorderInx, int ps, int pe, vector<int>& inorder, vector<int>& postorder){
        if (ins > ine || ps > pe){
            return nullptr;
        }

        int val = postorder[pe];

        TreeNode* root = new TreeNode(val);

        int inorder_lookup = inorderInx[val];

        int numsLeft = inorder_lookup - ins;

        root->left = f (ins, inorder_lookup-1, inorderInx, ps, ps+numsLeft-1, inorder, postorder);

        root->right = f (inorder_lookup+1, ine, inorderInx, ps+numsLeft,pe-1, inorder, postorder);

        return root;
    }
};