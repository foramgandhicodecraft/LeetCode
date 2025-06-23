/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        // since the graph is connected, traversal beginning from any node will eventually travel the entire graph
        if (node == nullptr)
          return nullptr;

        // mantain a map for original node -> cloned node
        unordered_map<Node*, Node*>clone;
        queue<Node*>q;

        // clone the original node
        Node* cloned = new Node(node->val);
        // add the cloned node to the map
        clone[node] = cloned;
        // push the origianl node in queue
        q.push(node); 

        while (!q.empty()){
            Node* current = q.front();
            q.pop();

            for (Node* itr : current->neighbors){
                // check if the node is cloned or not
                if (clone.find(itr) == clone.end()){
                    // clone the node
                    clone[itr] = new Node(itr->val);
                    q.push(itr);
                }

                // add the neighbours of the node to the current node's neighbours vector attribute
                clone[current]->neighbors.push_back(clone[itr]);
            }
        }

        return clone[node];
    }
};