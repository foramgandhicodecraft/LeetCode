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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if (root == NULL)
          return ans;
        int level = 0; //odd level->right to left and even level->left to right
        queue<TreeNode*>q;
        q.push(root);
        bfs(root, ans, level, q);
        return ans;
    }

private:
    void bfs(TreeNode* root, vector<vector<int>>&ans, int l, queue<TreeNode*>&q){
        while (!q.empty()){
            vector<int>temp;
            int size = q.size();
            // TreeNode* current = q.front();
            // temp.push_back(current->val);

            for (int i = 0; i < size; i++){
                TreeNode* current = q.front();
                temp.push_back(current->val);
                q.pop();
            
                if (current->left)
                  q.push(current->left);

                if (current->right)
                  q.push(current->right);

                // current = q.front();
                // temp.push_back(current->val);
                // q.pop();
            }

            if (l % 2 == 0)
              ans.push_back(temp);
            else{
                reverse(temp.begin(), temp.end());
                ans.push_back(temp);
            }
            l++;
        }
    }
};