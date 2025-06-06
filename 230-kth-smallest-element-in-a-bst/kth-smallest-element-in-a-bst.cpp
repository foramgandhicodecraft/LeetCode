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
    int kthSmallest(TreeNode* root, int k) {
        vector<int>list;
        inorder(root, list);
        int index = k-1;
        return list[index];
    }

private:
    void inorder(TreeNode* root, vector<int>& list){
        if (root->left)
          inorder(root->left,list);
        list.push_back(root->val);
        if (root->right)
          inorder(root->right,list);
    }

    
};