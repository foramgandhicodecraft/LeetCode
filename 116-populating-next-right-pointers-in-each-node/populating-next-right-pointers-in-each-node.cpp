/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root)
          return NULL;
          
        Node* level_node = root;

        while (level_node->left){
            Node* current = level_node;
            
            while (current){
                current->left->next = current->right;
                if (current->next){
                    current->right->next = current->next->left;
                }
                current = current->next;
            }

            level_node = level_node->left;
        }

        return root;
    }
};  