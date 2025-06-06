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
    bool findTarget(TreeNode* root, int k) {
        vector<int>list;
        inorder(root, list);
        int left = 0;
        int right = list.size()-1;
        int sum = 0;
        while (left < right){
            sum = list[left] + list[right];
            if (sum < k)
              left++;
            else if (sum > k)
              right--;
            else
              return true;
        }

        return false;
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