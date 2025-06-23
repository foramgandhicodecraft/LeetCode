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
class BSTIterator {
public:
vector<int>inorder;
    BSTIterator(TreeNode* root) {
        left_most(root);
    }

    stack<TreeNode*>st;

        void left_most(TreeNode* root){
            while (root){
                st.push(root);
                root = root->left; // will keep the smallest node to root on top
            }
        }
    
    int next() {
        TreeNode* node = st.top();
        st.pop();

        if (node->right){
            left_most(node->right);
        }

        return node->val;
    }
    
    bool hasNext() {
        if (st.empty())
          return false;
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */