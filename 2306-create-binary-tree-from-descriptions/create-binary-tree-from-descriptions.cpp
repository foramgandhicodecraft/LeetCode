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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        // find the node which has no parent
        // find the parent question becomes easier then
        // maintain a hash map
        // parent->child, 0/1
        // keep putting in queue and on poping find children from hash map

        map<int, TreeNode*>m;
        set<int>s;

        for (auto& d: descriptions){
            int parent = d[0];
            int child = d[1];
            int isLeft = d[2];

            if (m.find(parent) == m.end()){
                m[parent] = new TreeNode(parent);
            }
            if (m.find(child) == m.end()) {
                m[child] = new TreeNode(child);
            }

            TreeNode* root = m[parent];
            TreeNode* bachu = m[child];
            s.insert(child);

            if (isLeft){
                root->left = bachu;
            } else {
                root->right = bachu;
            }
        }

        for (auto v:descriptions){
            if (s.find(v[0]) == s.end()){
                return m[v[0]];
            }
        }

        return nullptr;
    }
};