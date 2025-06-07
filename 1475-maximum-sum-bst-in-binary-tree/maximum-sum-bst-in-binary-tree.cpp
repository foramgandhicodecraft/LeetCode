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
    int max_sum = 0;

    struct node{
        bool isBST;
        int max;
        int min;
        int sum=0;
    };

    int maxSumBST(TreeNode* root) {
        torture(root);
        return max_sum;
    }

private:
    node torture(TreeNode* root){
        if (!root) //for a null node
          return {true, INT_MIN, INT_MAX, 0};
        cout<<max_sum<<" "<<root->val<<endl;

        node left = torture(root->left);
        node right = torture(root->right);

        if (left.isBST && right.isBST && left.max < root->val && root->val<right.min){
            int curr_sum = left.sum + right.sum + root->val;
            max_sum = max(max_sum, curr_sum);
            return {true, max(right.max, root->val), min(left.min,root->val), curr_sum};
        }

        //if not a bst
        return {false, 0, 0, 0};
    }
};