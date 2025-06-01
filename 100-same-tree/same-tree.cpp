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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p==NULL && q== NULL)
          return true;
        if (p==NULL && q!=NULL)
          return false;
        if (q==NULL && p!=NULL)
          return false;

        queue<TreeNode*>q1;
        queue<TreeNode*>q2;
        q1.push(p);
        q2.push(q);
        bool ans = bfs(p,q,q1,q2);
        return ans;
    }

private:
    bool bfs(TreeNode* p, TreeNode* q, queue<TreeNode*>q1, queue<TreeNode*>q2){
        while (!q1.empty() && !q2.empty()){
            TreeNode* c1 = q1.front();
            TreeNode* c2 = q2.front();
            q1.pop();
            q2.pop();

            //both nodes null continue
            if (!c1 && !c2)
              continue;
             //one node null return false
            if (!c1 || !c2)
              return false;
              

            if (c1->val != c2->val)
              return false;

            q1.push(c1->left);
            q1.push(c1->right);
            q2.push(c2->left);
            q2.push(c2->right);
 
        }
        if (!q1.empty() || !q2.empty())
          return false;
        return true;
    }
};