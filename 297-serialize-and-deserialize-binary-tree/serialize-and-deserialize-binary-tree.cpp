/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string data;
        stringHelper(root, data);
        return data;
    }

    void stringHelper(TreeNode* root, string& data){
        if (root == NULL){
         data += "null,";
         return;
        }

        data += to_string(root->val)+",";
        stringHelper(root->left, data);
        stringHelper(root->right, data);
    }



    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        vector<string>tokens;
        string token;
        while (getline(ss, token,',')){
            tokens.push_back(token);
        }

        int index = 0;
        return buildTree(tokens, index);
    }

    TreeNode* buildTree(vector<string>&tokens, int& index){
        if (index >= tokens.size() || tokens[index] == "null"){
            index++;
            return nullptr;
        }

        TreeNode* node = new TreeNode(stoi(tokens[index]));
        index++;

        node->left = buildTree(tokens, index);
        node->right = buildTree(tokens, index);

        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));