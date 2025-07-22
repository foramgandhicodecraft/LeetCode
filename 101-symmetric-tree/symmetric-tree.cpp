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
    bool isSymmetric(TreeNode* root) {
        // vector<int>arr;
        // inorder(root,arr);

        // int left = 0;
        // int right = arr.size()-1;
        // for (int num:arr){
        //     cout<<num;
        // }

        // while (left < right){
        //     if (arr[left] != arr[right]){
        //         return false;
        //     }
        //     left++;
        //     right--;
        // }

        // return true;

        if (!root) return true;

        return f(root->left, root->right);

        
    }

    // void inorder(TreeNode* root, vector<int>&arr){
    //     if (root){
    //         inorder(root->left, arr);
    //         arr.push_back(root->val);
    //         inorder(root->right, arr);
    //     }
    // }

    bool f(TreeNode* t1, TreeNode* t2){
        if (!t1 && !t2) return true;

        if (!t1 || !t2) return false;

        return (t1->val == t2->val) && f(t1->left, t2->right) && f(t1->right, t2->left);
    }
};